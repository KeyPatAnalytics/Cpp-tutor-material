#include "polymorphism.cpp"
#include "windows.h"


int main() {
    SetConsoleOutputCP(65001); // Set console output to UTF-8 encoding
    SetConsoleCP(65001); // Set console input to UTF-8 encoding

    // Пример использования инкапсуляции
    BankAccount account("Иван Иванов", 1000.0);
    account.deposit(500.0);
    account.withdraw(200.0);

    std::cout << "Баланс аккаунта: " << account.getBalance() << " руб.\n";

    // Пример использования наследования и полиморфизма
    SavingsAccount savingsAccount("Петр Петров", 2000.0, 5.0);
    savingsAccount.deposit(1000.0);
    savingsAccount.accrueInterest();

    std::cout << "Баланс сберегательного счета: " << savingsAccount.getBalance() << " руб.\n";

    // Пример использования полиморфизма через указатель на базовый класс
    Printable* transaction = new Transaction("Покупка товаров", 150.0);
    transaction->print();

    delete transaction; // Очистка памяти

    return 0;
}