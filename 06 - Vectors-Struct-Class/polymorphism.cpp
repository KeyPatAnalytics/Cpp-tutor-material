#include "enheritance.cpp"

class Printable {
public:
    virtual void print() const = 0; // Виртуальная функция

    virtual ~Printable() {} // Виртуальный деструктор
};

class Transaction : public Printable {
private:
    std::string description;
    double amount;

public:
    Transaction(std::string desc, double amt) : description(desc), amount(amt) {}

    // Реализация виртуальной функции
    void print() const override {
        std::cout << "Транзакция: " << description << ", Сумма: " << amount << " руб.\n";
    }
};