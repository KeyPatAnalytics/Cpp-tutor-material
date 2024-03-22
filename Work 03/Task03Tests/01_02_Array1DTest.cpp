#include "pch.h"
#include <windows.h>
#include <iostream>
#include "../Homework 3/01_dynamicArray.cpp"
#include "../Homework 3/02_arrayToFile.cpp"
using namespace std;


TEST(Array1D, DynArrayAndToFileTest) {
    //  Использовать русский текст
    SetConsoleOutputCP(65001); // Set console output to UTF-8 encoding
    SetConsoleCP(65001); // Set console input to UTF-8 encoding


    const char* fileName = "../Homework 3/genaratedData.txt"; // Имя файла для записи
    int array[] = { 1, 2, 3, 4, 5 }; // Пример целочисленного массива

    int size = sizeof(array) / sizeof(array[0]); // Размерность массива
    writeArrayToFile(fileName, array, size); // Вызываем функцию для записи массива в файл

    // Файл который содержит наши данные 1,2,3,4,5
    // const char* fileName = "../Homework 3/genaratedData.txt";
    pair<int*, int> result = createDynamicArray(fileName);

    int* dynamicArray = result.first;
    int readSize = result.second;

    // cout << "Количество эленментов в файле: " << size << endl;
    EXPECT_EQ(readSize, size);

    if (dynamicArray != nullptr) {
        // cout << "Dynamic Array Elements: ";
        for (int i = 0; i < readSize; ++i) {
            EXPECT_EQ(array[i], dynamicArray[i]);
        }
        //cout << endl;

        // Освобождаем память
        delete[] dynamicArray;
    }
}