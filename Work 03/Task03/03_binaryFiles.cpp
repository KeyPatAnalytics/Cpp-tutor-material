#include "pch.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include "binaryFiles.h"
// using namespace std;

// ������� ��� ������ ������� � �������� ����
void writeArrayToBinaryFile(const char* fileName, const int* array, int size) {
    std::ofstream outFile(fileName, std::ios::binary); // ��������� ���� ��� ������ � �������� ������

    if (outFile.is_open()) {

        // ���������� �������� �������
        outFile.write(reinterpret_cast<const char*>(array), size * sizeof(int));

        outFile.close(); // ��������� ����
        std::cout << "\n������ ������� ������� � �������� ����.\n" << std::endl;
    }
    else {
        std::cerr << "������: �� ������� ������� �������� ���� ��� ������." << std::endl;
    }
}


// ������� ��� ������ ������� �� ��������� ����� 
// � ����������� ���������� ���������
int* readArrayFromBinaryFile(const char* fileName, int& size) {
    int* array = nullptr; // ��������� �� ������ ��� �������� ��������� ������

    // ��������� ���� ��� ������ � �������� ������ (ios::binary)
    // ���������� ��������� ������ � ����� ����� (ios::ate)-- ATE = AT THE END
    // !!!! ��� ����� ����� ����� ����������� ����� ����� � �����. �-�� ���������
    std::ifstream inFile(fileName, std::ios::binary | std::ios::ate);

    if (inFile.is_open()) {
        // ����������� ������� ����� � ������ ����� ������ tellg()
        /*
            tellg() - ��� �������, ������������ � �������� (ifstream � fstream),
            ������� ���������� ������� ������� ��������� � ������ � ������. ���
            ������� ������������ ����� �������� �� ������ �����. � ��������� ��
            ��������� � ����� �����, �� �������� ������ ����� � ������. ���� ��
            ����� �� ���������� ������, ���������� ������ ���� int, �� �����
            �������� ���������� ��������� � �����.
        */
        size = inFile.tellg() / sizeof(int);
        inFile.seekg(0, std::ios::beg); // ����������� ��������� ������ � ������ �����

        // �������� ������ ��� ������ � ��������� �������� �������
        array = new int[size];
        inFile.read(reinterpret_cast<char*>(array), size * sizeof(int));

        inFile.close(); // ��������� ����
    }
    else {
        std::cerr << "������: �� ������� ������� �������� ���� ��� ������." << std::endl;
    }
    return array;
}

