#include <iostream>
#include <cstring>

int main() {
    const char str1[] = "banana";
    const char str2[] = "bananatyu";

    // Сравнение
    int result = strcmp(str1, str2);

    if (result == 0) {
        std::cout << "Strings are equal." << std::endl;
    } else if (result < 0) {
        std::cout << "String 1 is less than String 2." << std::endl;
    } else {
        std::cout << "String 1 is greater than String 2." << std::endl;
    }

    return 0;
}
