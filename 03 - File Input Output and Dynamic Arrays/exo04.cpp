#include <windows.h>
#include <iostream>
#include <algorithm>
using namespace std;

// Функция для вычисления суммы элементов массива,
// расположенных после последнего отрицательного элемента
int sumAfterLastNegative(const int arr[], int size) {
    int sum = 0;

    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] < 0) return sum ;
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
                swap(arr[i], arr[j]);
            }
        }
        // cout << endl;
    }

    for (int i = 1; i < size; i += 2) {
        for (int j = i + 2; j < size; j += 2) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main() {
    SetConsoleOutputCP(65001); // Set console output to UTF-8 encoding
    SetConsoleCP(65001); // Set console input to UTF-8 encoding

    // Пример использования функций
    int arr[] = {3, -2, 7, 1, -4, 5, 9, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Вычисляем сумму элементов массива, расположенных после последнего отрицательного элемента
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
