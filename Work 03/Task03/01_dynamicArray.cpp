#include "pch.h"
#include <iostream>
#include <fstream>
#include "DynamicArray.h"
// using namespace std;

std::pair<int*, int> createDynamicArray(const char* fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open the file." << std::endl;
        return { nullptr, 0 };
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

    return { dynamicArray, size };
}
