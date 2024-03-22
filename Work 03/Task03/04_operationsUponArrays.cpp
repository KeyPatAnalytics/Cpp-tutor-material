#include "pch.h"
#include <windows.h>
#include <iostream>
#include "operationsUponArrays.h"
//using namespace std;

// Функция для вычисления суммы элементов массива,
// расположенных после последнего отрицательного элемента
int sumAfterLastNegative(const int arr[], int size) {
    int sum = 0;

    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] < 0) return sum;
        sum += arr[i];
    }

    return sum;
}

// Функция для упорядочивания элементов по возрастанию на четных и нечетных позициях
void sortEvenOddElements(int arr[], int size) { //inplace
    // Сортируем четные и нечетные элементы
    for (int i = 0; i < size; i += 2) {
        // Мы сравниваем элемент в позиции i со всеми следующими элементами в четных позициях
        for (int j = i + 2; j < size; j += 2) {
            // cout << "(" << arr[i] << "," << arr[j] << ") ";  // Для проверки какие элементы сравниваются
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
