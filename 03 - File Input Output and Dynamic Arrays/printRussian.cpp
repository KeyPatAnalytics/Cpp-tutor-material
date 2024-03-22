#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001); // Set console output to UTF-8 encoding
    SetConsoleCP(65001); // Set console input to UTF-8 encoding

    std::cout << "Привет, мир!" << std::endl; // Print Russian text using std::cout

    return 0;
}
