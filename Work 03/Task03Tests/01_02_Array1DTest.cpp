#include "pch.h"
#include <windows.h>
#include <iostream>
#include "../Homework 3/01_dynamicArray.cpp"
#include "../Homework 3/02_arrayToFile.cpp"
using namespace std;


TEST(Array1D, DynArrayAndToFileTest) {
    //  ������������ ������� �����
    SetConsoleOutputCP(65001); // Set console output to UTF-8 encoding
    SetConsoleCP(65001); // Set console input to UTF-8 encoding


    const char* fileName = "../Homework 3/genaratedData.txt"; // ��� ����� ��� ������
    int array[] = { 1, 2, 3, 4, 5 }; // ������ �������������� �������

    int size = sizeof(array) / sizeof(array[0]); // ����������� �������
    writeArrayToFile(fileName, array, size); // �������� ������� ��� ������ ������� � ����

    // ���� ������� �������� ���� ������ 1,2,3,4,5
    // const char* fileName = "../Homework 3/genaratedData.txt";
    pair<int*, int> result = createDynamicArray(fileName);

    int* dynamicArray = result.first;
    int readSize = result.second;

    // cout << "���������� ���������� � �����: " << size << endl;
    EXPECT_EQ(readSize, size);

    if (dynamicArray != nullptr) {
        // cout << "Dynamic Array Elements: ";
        for (int i = 0; i < readSize; ++i) {
            EXPECT_EQ(array[i], dynamicArray[i]);
        }
        //cout << endl;

        // ����������� ������
        delete[] dynamicArray;
    }
}