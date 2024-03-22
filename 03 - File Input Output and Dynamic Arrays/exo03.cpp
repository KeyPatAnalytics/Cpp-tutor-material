#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

// Функция для записи массива в бинарный файл
void writeArrayToBinaryFile(const char* fileName, const int* array, int size) {
    ofstream outFile(fileName, ios::binary); // Открываем файл для записи в бинарном режиме

    if (outFile.is_open()) {
        
        // Записываем элементы массива
        outFile.write(reinterpret_cast<const char*>(array), size * sizeof(int));

        outFile.close(); // Закрываем файл
        cout << "\nМассив успешно записан в бинарный файл.\n" << endl;
    } else {
        cerr << "Ошибка: Не удалось открыть бинарный файл для записи." << endl;
    }
}


// Функция для чтения массива из бинарного файла 
// и определения количества элементов
int* readArrayFromBinaryFile(const char* fileName, int& size) {
    int* array = nullptr; // Указатель на массив для хранения считанных данных

    // Открываем файл для чтения в бинарном режиме (ios::binary)
    // Перемещаем указатель чтения в конце файла (ios::ate)-- ATE = AT THE END
    // !!!! ЭТО ОЧЕНЬ ВАЖНО ЧТОБЫ ОПРЕДЕЛЕИТЬ ОБЬЕМ ФАЙЛА И СООТВ. К-ВО ЭЛЕМЕНТОВ
    ifstream inFile(fileName, ios::binary | ios::ate); 

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
        inFile.seekg(0, ios::beg); // Перемещение указателя чтения в начало файла

        // Выделяем память под массив и считываем элементы массива
        array = new int[size];
        inFile.read(reinterpret_cast<char*>(array), size * sizeof(int));

        inFile.close(); // Закрываем файл
    } else {
        cerr << "Ошибка: Не удалось открыть бинарный файл для чтения." << endl;
    }
    return array;
}


int main() {
    SetConsoleOutputCP(65001); // Set console output to UTF-8 encoding
    SetConsoleCP(65001); // Set console input to UTF-8 encoding

    // Пример данных для записи в бинарный файл
    int dataToWrite[] = {-5, -10, 4, 1, 2, 3, 4, 5};
    int size = sizeof(dataToWrite) / sizeof(dataToWrite[0]);

    // Запись массива в бинарный файл
    writeArrayToBinaryFile("data.bin", dataToWrite, size);

    // Чтение массива из бинарного файла
    int readSize;
    int* readData = readArrayFromBinaryFile("data.bin", readSize);

    // Вывод считанных данных
    cout << "Считанный массив из бинарного файла содержит " << readSize << " элемент(-а/ов): ";
    for (int i = 0; i < readSize; ++i) {
        cout << readData[i] << " ";
    }
    cout << endl << endl;

    // Освобождаем выделенную память
    delete[] readData;

    return 0;
}
