/*
С Ильёй пройти инициализацию строк, конкатенацию, 
доступ к символам, работу с длиной, сравнение, 
подстроки, поиск подстроки, замену подстроки, 
ввод/вывод, преобразование чисел в строки и наоборот, 
итерацию по строке, 
а также операции с символами
*/

using namespace std;

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    // 1. Инициализация строк
    std::string str1 = "Hello, ";
    std::string str2 = "world!";

    // 2. Конкатенация строк
    std::string result = str1 + str2;

    // 3. Доступ к символам строки
    char firstChar = str1[0];

    // 4. Длина строки
    int length = str1.length();

    // 5. Сравнение строк
    if (str1 == str2) { //overload
        std::cout << "Strings are equal." << std::endl;
    } else {
        std::cout << "Strings are not equal." << std::endl;
    }

    // 6. Подстроки
    std::string substr = str1.substr(0, 5); // подстрока с позиции 0 до 4
    // "Patatclonalo" "lo"
    // 7. Поиск подстроки
    size_t pos = str1.find("lo");
    if (pos != std::string::npos) {
        std::cout << "Substring found at position " << pos << std::endl;
    } else {
        std::cout << "Substring not found." << std::endl;
    }

    // 8. Замена подстроки
    size_t replacePos = str1.find("lo");
    if (replacePos != std::string::npos) {
        str1.replace(replacePos, 2, "xy");
    }

    // 9. Ввод/вывод строк
    std::cout << "Enter a string: ";
    std::cin >> str1;

    // 10. Преобразование чисел в строки и наоборот
    int num = 42;
    std::string strNum = std::to_string(num);

    std::string str = "123";
    int convertedNum = std::stoi(str);

    // 11. Итерация по строке
    for (char c : str1) {
        // делайте что-то с символом c
    }

    // 12. Операции с символами
    char upperC = std::toupper('a');
    char lowerC = std::tolower('A');

    return 0;
}
