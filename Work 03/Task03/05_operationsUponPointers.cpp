#include "pch.h"
#include <windows.h>
#include <iostream>
#include "operationsUponPointers.h"
// using namespace std;

// ������� ��� ���������� ����� ��������� �������, 
// ������������� ����� ���������� �������������� ��������
int sum_After_Last_Negative(int arr[], int size) {
    int sum = 0;
    int* ptr = arr + size - 1; // ���������� ��������� ��� �������� ����������

    // ���������� ���� while � ��������������� � �������� �����������
    while (ptr >= arr) {
        if (*ptr < 0) return sum;

        sum += *ptr;
        ptr--;
    }

    return sum;
}

// ������� ��� �������������� ��������� �� 
// ����������� �� ������ � �������� ��������
void sort_Even_Odd_Elements(int arr[], int size) {
    // ���������� ���� for ��� ������ ��������� � �������� �����������
    for (int* ptr = arr; ptr < arr + size; ptr += 2) {
        for (int* nextPtr = ptr + 2; nextPtr < arr + size; nextPtr += 2) {
            if (*ptr > *nextPtr) {
                std::swap(*ptr, *nextPtr);
            }
        }
    }

    // ���������� ���� while ��� �������� ��������� � ���������������
    int i = 1;
    while (i < size) {
        int j = i + 2;
        while (j < size) {
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
            j += 2;
        }
        i += 2;
    }
}
