#include "pch.h"
#include <windows.h>
#include <iostream>
#include "operationsUponPointers.h"
// using namespace std;

// Функция для вычисления суммы элементов массива, 
// расположенных после последнего отрицательного элемента
int sum_After_Last_Negative(int arr[], int size) {
    int sum = 0;
    int* ptr = arr + size - 1; // Используем указатель для адресной арифметики

    // Используем цикл while с индексированием и адресной арифметикой
    while (ptr >= arr) {
        if (*ptr < 0) return sum;

        sum += *ptr;
        ptr--;
    }

    return sum;
}

// Функция для упорядочивания элементов по 
// возрастанию на четных и нечетных позициях
void sort_Even_Odd_Elements(int arr[], int size) {
    // Используем цикл for для четных элементов с адресной арифметикой
    for (int* ptr = arr; ptr < arr + size; ptr += 2) {
        for (int* nextPtr = ptr + 2; nextPtr < arr + size; nextPtr += 2) {
            if (*ptr > *nextPtr) {
                std::swap(*ptr, *nextPtr);
            }
        }
    }

    // Используем цикл while для нечетных элементов с индексированием
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
