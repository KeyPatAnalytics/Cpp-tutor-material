#include <windows.h>
#include <iostream>
using namespace std;

// Функция для вычисления суммы элементов массива, расположенных после последнего отрицательного элемента
int sumAfterLastNegative(int arr[], int size) {
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

// Функция для упорядочивания элементов по возрастанию на четных и нечетных позициях
void sortEvenOddElements(int arr[], int size) {
    // Используем цикл for для четных элементов с адресной арифметикой
    for (int* ptr = arr; ptr < arr + size; ptr += 2) {
        for (int* nextPtr = ptr + 2; nextPtr < arr + size; nextPtr += 2) {
            if (*ptr > *nextPtr) {
                swap(*ptr, *nextPtr);
            }
        }
    }

    // Используем цикл while для нечетных элементов с индексированием
    int i = 1;
    while (i < size) {
        int j = i + 2;
        while (j < size) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
            j += 2;
        }
        i += 2;
    }
}



int main() {
    SetConsoleOutputCP(65001); // Set console output to UTF-8 encoding
    SetConsoleCP(65001); // Set console input to UTF-8 encoding

    // Пример использования функций с различными видами циклов
    // и методами доступа к элементам массива
    int arr[] = {3, -2, 7, 1, -4, 5, 9, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Вычисляем сумму элементов массива, р
    // асположенных после последнего отрицательного элемента
    int sum = sumAfterLastNegative(arr, size);
    cout << "Сумма элементов после последнего отрицательного: " << sum << endl;

    // Упорядочиваем элементы на четных и нечетных позициях
    sortEvenOddElements(arr, size);

    // Выводим отсортированный массив
    cout << "Массив после сортировки четных и нечетных элементов: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
