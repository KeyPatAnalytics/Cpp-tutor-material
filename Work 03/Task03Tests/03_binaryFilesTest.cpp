#include "pch.h"
#include "windows.h"
#include <iostream>
#include "../Homework 3/03_binaryFiles.cpp"
using namespace std;

TEST(BinaryFiles, BF_Test) {
    SetConsoleOutputCP(65001); // Set console output to UTF-8 encoding
    SetConsoleCP(65001); // Set console input to UTF-8 encoding

    // Пример данных для записи в бинарный файл
    int dataToWrite[] = { -5, -10, 4, 1, 2, 3, 4, 5 };
    int size = sizeof(dataToWrite) / sizeof(dataToWrite[0]);

    // Запись массива в бинарный файл
    writeArrayToBinaryFile("data.bin", dataToWrite, size);

    // Чтение массива из бинарного файла
    int readSize;
    int* readData = readArrayFromBinaryFile("data.bin", readSize);

    // Вывод считанных данных
    cout << "Считанный массив из бинарного файла содержит " << readSize << " элемент(-а/ов): ";
    EXPECT_EQ(size, readSize);

    for (int i = 0; i < readSize; ++i) {
        cout << readData[i] << " ";
        EXPECT_EQ(dataToWrite[i], readData[i]);
    }
    cout << endl << endl;

    // Освобождаем выделенную память
    delete[] readData;
}