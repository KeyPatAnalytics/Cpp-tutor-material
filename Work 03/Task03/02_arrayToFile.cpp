#include "pch.h"
#include <iostream>
#include <fstream>
#include "arrayToFile.h"
// using namespace std;

void writeArrayToFile(const char* fileName, const int array[], int size) {
    std::ofstream outFile(fileName); // Открываем файл для записи

    if (outFile.is_open()) { // Проверяем, удалось ли открыть файл
        for (int i = 0; i < size; ++i) {
            outFile << array[i] << " "; // Записываем элементы массива в файл
        }

        outFile.close(); // Закрываем файл
        std::cout << "Массив успешно записан в файл." << std::endl;
    }
    else {
        std::cerr << "Ошибка: Не удалось открыть файл для записи." << std::endl;
    }
}
