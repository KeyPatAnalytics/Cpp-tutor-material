#include <iostream>

int main() {
    const char str[] = "Hello, World!";

    // Итерация по C-строке
    for (size_t i = 0; i < strlen(str) - 1; ++i) {
        std::cout << str[i] << " ";
    }

    return 0;
}
