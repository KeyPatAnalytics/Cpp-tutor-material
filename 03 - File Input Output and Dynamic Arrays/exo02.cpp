#include <iostream>
#include <fstream>

using namespace std;

void writeArrayToFile(const char* fileName, const int array[], int size) {
    ofstream outFile(fileName); // Открываем файл для записи

    if (outFile.is_open()) { // Проверяем, удалось ли открыть файл
        for (int i = 0; i < size; ++i) {
            outFile << array[i] << " "; // Записываем элементы массива в файл
        }

        outFile.close(); // Закрываем файл
        cout << "Массив успешно записан в файл." << endl;
    } else {
        cerr << "Ошибка: Не удалось открыть файл для записи." << endl;
    }
}

int main() {
    const char* fileName = "output.txt"; // Имя файла для записи
    int array[] = {1, 2, 3, 4, 5}; // Пример целочисленного массива

    int size = sizeof(array) / sizeof(array[0]); // Размерность массива

    writeArrayToFile(fileName, array, size); // Вызываем функцию для записи массива в файл

    return 0;
}
