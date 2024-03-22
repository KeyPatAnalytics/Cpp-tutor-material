#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(65001); // Set console output to UTF-8 encoding
    SetConsoleCP(65001); // Set console input to UTF-8 encoding

    // int number = 10;
    // int number1 = 456;
    // bool passed = true;
    // string name = "Patatchona";

    // int* ptr = &number;
    // *ptr = 100
    // cout << "Значение переменной: " << number << endl;
    // // cout << "Значение указателя: " << ptr << endl;

    // number = 45;
    // cout << "Значение через указатель после ман.: " << *ptr << endl;


    int* dynamicPtr = new int;
    *dynamicPtr = 20;

    cout << "Динамически выделенное значение: " << *dynamicPtr << endl;

    delete dynamicPtr; // Освободить динамическую память
    // worth it

    return 0;
}
