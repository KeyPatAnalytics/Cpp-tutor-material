#include <iostream>
#include <cstring>

int main() {
    // Литеральная инициализация
    const char str1[] = "Hello, World!";

    // Инициализация с помощью функции strcpy
    char str2[50];
    strcpy(str2, "C-strings");

    // Инициализация с использованием массива символов
    char str3[] = {'H', 'e', 'l', 'l', 'o', '\0'};

    // Инициализация с помощью конструктора строки (символьные литералы)
    const char* str4 = "Hello from pointers";

    // Вывод строк
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;
    std::cout << str3 << std::endl;
    std::cout << str4 << std::endl;

    return 0;
}
