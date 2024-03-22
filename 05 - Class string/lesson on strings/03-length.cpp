#include <iostream>
#include <cstring>

int main() {
    const char str[] = "Hello, World!";
    size_t length = strlen(str);

    std::cout << "Length of the string: " << length << std::endl;

    return 0;
}
