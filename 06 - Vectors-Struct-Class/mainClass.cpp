#include "Class.cpp"
#include "windows.h"

int main() {
    SetConsoleOutputCP(65001); // Set console output to UTF-8 encoding
    SetConsoleCP(65001); // Set console input to UTF-8 encoding

    // Создание объектов класса Dog
    Dog newDog("");//("Бобик", 3); // instance
    int x = 0;



    // myDog.setName("Toutpasse");

    // Использование методов объекта
    std::cout << "Имя: " << newDog.getName() << std::endl;
    std::cout << "Возраст: " << newDog.getAge() << " года" << std::endl;

    // // Изменение данных объекта
    // myDog.setName("Шарик");
    // myDog.setAge(4);

    // // Повторное использование методов
    // std::cout << "Новое имя: " << myDog.getName() << std::endl;
    // std::cout << "Новый возраст: " << myDog.getAge() << " года" << std::endl;

    // // Завершение программы, деструктор будет вызван автоматически
    return 0;
}
