#include "pch.h"
#include "windows.h"
#include <iostream>
#include "../Homework 3/05_operationsUponPointers.cpp"
using namespace std;

TEST(OpePointers, OpePointersTest) {
    SetConsoleOutputCP(65001); // Set console output to UTF-8 encoding
    SetConsoleCP(65001); // Set console input to UTF-8 encoding

    // Пример использования функций
    int arr[] = { 3, -2, 7, 1, -4, 5, 9, 6 };
    int orderedArr[] = { -4, -2, 3, 1, 7, 5, 9, 6 };

    int size = sizeof(arr) / sizeof(arr[0]);

    // Вычисляем сумму элементов массива, расположенных после последнего отрицательного элемента
    int sum = sum_After_Last_Negative(arr, size);
    cout << "Сумма элементов после последнего отрицательного: " << sum << endl;
    EXPECT_EQ(20, sum);

    // Упорядочиваем элементы на четных и нечетных позициях
    sort_Even_Odd_Elements(arr, size);

    // Выводим отсортированный массив
    cout << "Массив после сортировки четных и нечетных элементов: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
        EXPECT_EQ(arr[i], orderedArr[i]);
    }
    cout << endl;

}
