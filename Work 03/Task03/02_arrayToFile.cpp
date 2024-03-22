#include "pch.h"
#include <iostream>
#include <fstream>
#include "arrayToFile.h"
// using namespace std;

void writeArrayToFile(const char* fileName, const int array[], int size) {
    std::ofstream outFile(fileName); // ��������� ���� ��� ������

    if (outFile.is_open()) { // ���������, ������� �� ������� ����
        for (int i = 0; i < size; ++i) {
            outFile << array[i] << " "; // ���������� �������� ������� � ����
        }

        outFile.close(); // ��������� ����
        std::cout << "������ ������� ������� � ����." << std::endl;
    }
    else {
        std::cerr << "������: �� ������� ������� ���� ��� ������." << std::endl;
    }
}
