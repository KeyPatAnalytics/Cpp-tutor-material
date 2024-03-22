#include <iostream>
#include <cstring>

int main() {
    // Ввод строки
    char input[50];
    std::cout << "Enter a string: ";
    std::cin >> input;
    std::cout << "You entered: " << input << std::endl;

    // Вывод строки
    const char* output = "This is a C-string";
    std::cout << "Output string: " << output << std::endl;

    return 0;
}
