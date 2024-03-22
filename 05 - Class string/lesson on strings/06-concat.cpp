#include <iostream>
#include <cstring>

int main() {
    char str1[50] = "Hello, ";
    const char str2[] = "World!";

    // Конкатенация
    strcat(str1, str2);

    std::cout << "Concatenated string: " << str1 << std::endl;

    return 0;
}
