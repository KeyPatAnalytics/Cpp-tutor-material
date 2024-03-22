#include <iostream>
#include <cstring>

int main() {
    const char source[] = "This is a sample string";
    char destination[20];

    // Получение подстроки
    strncpy(destination, source + 5, 10);
    destination[10] = '\0';  // Добавление нулевого символа

    std::cout << "Substring: " << destination << std::endl;

    return 0;
}
