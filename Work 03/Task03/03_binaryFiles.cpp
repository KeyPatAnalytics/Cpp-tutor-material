#include "pch.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include "binaryFiles.h"
// using namespace std;

// Функция для записи массива в бинарный файл
void writeArrayToBinaryFile(const char* fileName, const int* array, int size) {
    std::ofstream outFile(fileName, std::ios::binary); // Открываем файл для записи в бинарном режиме

    if (outFile.is_open()) {

        // Записываем элементы массива
        outFile.write(reinterpret_cast<const char*>(array), size * sizeof(int));

        outFile.close(); // Закрываем файл
        std::cout << "\nМассив успешно записан в бинарный файл.\n" << std::endl;
    }
    else {
        std::cerr << "Ошибка: Не удалось открыть бинарный файл для записи." << std::endl;
    }
}


// Функция для чтения массива из бинарного файла 
// и определения количества элементов
int* readArrayFromBinaryFile(const char* fileName, int& size) {
    int* array = nullptr; // Указатель на массив для хранения считанных данных

    // Открываем файл для чтения в бинарном режиме (ios::binary)
    // Перемещаем указатель чтения в конце файла (ios::ate)-- ATE = AT THE END
    // !!!! ЭТО ОЧЕНЬ ВАЖНО ЧТОБЫ ОПРЕДЕЛЕИТЬ ОБЬЕМ ФАЙЛА И СООТВ. К-ВО ЭЛЕМЕНТОВ
    std::ifstream inFile(fileName, std::ios::binary | std::ios::ate);

    if (inFile.is_open()) {
        // Определение размера файла в байтах ЧЕРЕЗ МЕТОДА tellg()
        /*
            tellg() - это функция, используемая с потоками (ifstream и fstream),
            которая возвращает текущую позицию указателя в потоке в байтах. Эта
            позиция представляет собой смещение от начала файла. И поскольку мы
            находимся в конце файле, мы получаем размер файла в байтах. Если мы
            делим на количество байтов, занимаемых числом типа int, мы сразу
            получаем количество элементов в файле.
        */
        size = inFile.tellg() / sizeof(int);
        inFile.seekg(0, std::ios::beg); // Перемещение указателя чтения в начало файла

        // Выделяем память под массив и считываем элементы массива
        array = new int[size];
        inFile.read(reinterpret_cast<char*>(array), size * sizeof(int));

        inFile.close(); // Закрываем файл
    }
    else {
        std::cerr << "Ошибка: Не удалось открыть бинарный файл для чтения." << std::endl;
    }
    return array;
}

