#include <iostream>
#include <cstring>

int main() {
    const char str[] = "This is a sample string";
    const char substring[] = "sample";

    // Поиск подстроки
    const char* result = strstr(str, substring);

    if (result != nullptr) {
        std::cout << "Substring found at position: " << result - str << std::endl;
    } else {
        std::cout << "Substring not found." << std::endl;
    }

    return 0;
}
