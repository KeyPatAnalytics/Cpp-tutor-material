#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

pair<int*, int> createDynamicArray(const char* fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return {nullptr, 0};
    }

    int size = 0;
    int number;
    while (file >> number) {
        size++;
    }

    file.clear();   // Clear the end-of-file flag
    file.seekg(0);  // Move file cursor back to the beginning

    
    int* dynamicArray = new int[size];

    for (int i = 0; i < size; ++i) {
        file >> dynamicArray[i];
    }

    file.close();

    return {dynamicArray, size};
}

int main() {
    //  Использовать русский текст
    SetConsoleOutputCP(65001); // Set console output to UTF-8 encoding
    SetConsoleCP(65001); // Set console input to UTF-8 encoding

    const char* fileName = "input.txt"; // Файл который содержит наши данные
    pair<int*, int> result = createDynamicArray(fileName);
    
    int* dynamicArray = result.first;
    int size = result.second;
    cout << "Количество эленментов в файле: " << size << endl;

    if (dynamicArray != nullptr) {
        cout << "Dynamic Array Elements: ";
        for (int i = 0; i < size; ++i) {
            cout << dynamicArray[i] << " ";
        }
        cout << endl;

        // We don't forget to free the dynamically allocated memory
        delete[] dynamicArray;
    }

    return 0;
}
