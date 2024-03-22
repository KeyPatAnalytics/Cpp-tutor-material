#include "encapsulation.cpp"

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(std::string holder, double initialBalance, double rate)
        : BankAccount(holder, initialBalance), interestRate(rate) {}

    // Метод для начисления процентов
    void accrueInterest() {
        double interest = getBalance() * interestRate / 100;
        deposit(interest);
        std::cout << "Проценты начислены.\n";
    }
};
