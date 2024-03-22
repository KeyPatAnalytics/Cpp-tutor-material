/*
Инкапсуляция:
Инкапсуляция позволяет скрыть детали реализации от пользователя 
и предоставлять только интерфейс взаимодействия.
*/

#include <iostream>
#include <string>
#include "windows.h"

class BankAccount {
private:
    std::string accountHolder;
    double balance;

public:
    BankAccount(std::string holder, double initialBalance) : accountHolder(holder), balance(initialBalance) {}

    // Методы для работы с балансом
    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Депозит на " << amount << " руб. выполнен успешно.\n";
        } else {
            std::cout << "Сумма депозита должна быть положительной.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Снятие " << amount << " руб. выполнено успешно.\n";
        } else {
            std::cout << "Недостаточно средств или некорректная сумма для снятия.\n";
        }
    }
};
