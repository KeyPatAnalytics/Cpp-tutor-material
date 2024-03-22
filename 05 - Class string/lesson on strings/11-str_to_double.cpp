#include <iostream>
#include <sstream>

int main() {
    const char str[] = "42.75";
    double num;

    // Преобразование C-строки в число
    std::istringstream(str) >> num;

    std::cout << "String as double: " << num << std::endl;

    return 0;
}
