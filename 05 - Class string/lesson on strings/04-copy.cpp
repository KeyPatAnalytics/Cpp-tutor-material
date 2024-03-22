#include <iostream>
#include <cstring>

int main() {
    const char source[] = "Copy me!";
    char destination[50];

    // Копирование
    strcpy(destination, source);

    std::cout << "Source string: " << source << std::endl;
    std::cout << "Copied string: " << destination << std::endl;

    return 0;
}
