#include "pch.h"
#include <windows.h>
#include <iostream>
#include "operationsUponArrays.h"
//using namespace std;

// ������� ��� ���������� ����� ��������� �������,
// ������������� ����� ���������� �������������� ��������
int sumAfterLastNegative(const int arr[], int size) {
    int sum = 0;

    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] < 0) return sum;
        sum += arr[i];
    }

    return sum;
}

// ������� ��� �������������� ��������� �� ����������� �� ������ � �������� ��������
void sortEvenOddElements(int arr[], int size) { //inplace
    // ��������� ������ � �������� ��������
    for (int i = 0; i < size; i += 2) {
        // �� ���������� ������� � ������� i �� ����� ���������� ���������� � ������ ��������
        for (int j = i + 2; j < size; j += 2) {
            // cout << "(" << arr[i] << "," << arr[j] << ") ";  // ��� �������� ����� �������� ������������
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }
        // cout << endl;
    }

    for (int i = 1; i < size; i += 2) {
        for (int j = i + 2; j < size; j += 2) {
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}
