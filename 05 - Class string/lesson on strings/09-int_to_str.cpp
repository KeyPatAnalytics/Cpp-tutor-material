#include <iostream>
#include <cstdio>

int main() {
    int num = 42;
    char str[20];

    // Преобразование числа в C-строку
    sprintf(str, "%d", num);

    std::cout << "Number as string: " << str << std::endl;

    return 0;
}
