#include <iostream>
#include <string>

// Определение класса
class Dog {
private: // Члены класса доступны только внутри самого класса
    std::string name;
    int age;

public: // Члены класса доступны извне класса
    
    // Конструктор1 класса
    Dog(std::string dogName, int dogAge) : name(dogName), age(dogAge) {
        std::cout << "Создан объект класса Dog." << std::endl;
    }


    Dog(): name(""), age(-1){
    }

    Dog(std::string dogName): name(dogName), age(1){
    }

    // Метод для получения имени
    std::string getName() const {
        return name;
    }

    // Метод для установки имени
    void setName(std::string newName) {
        name = newName;
    }

    // Метод для получения возраста
    int getAge() const {
        return age;
    }

    // Метод для установки возраста
    void setAge(int newAge) {
        age = newAge;
    }

    // Деструктор класса
    ~Dog() {
        std::cout << "Уничтожен объект класса Dog." << std::endl;
    }
};
