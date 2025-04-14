
#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountHolderName;
    std::string accountNumber;
    double balance;

public:
    // Constructor to initialize the bank account
    BankAccount(const std::string& name, const std::string& accNumber)
        : accountHolderName(name), accountNumber(accNumber), balance(0.0) {}

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Successfully deposited: $" << amount << std::endl;
        } else {
            std::cout << "Deposit amount must be positive." << std::endl;
        }
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (amount > 0) {
            if (amount <= balance) {
                balance -= amount;
                std::cout << "Successfully withdrew: $" << amount << std::endl;
            } else {
                std::cout << "Error: Insufficient funds. Available balance: $" << balance << std::endl;
            }
        } else {
            std::cout << "Withdrawal amount must be positive." << std::endl;
        }
    }

    // Method to check account balance
    void checkBalance() const {
        std::cout << "Account Balance: $" << balance << std::endl;
    }

    // Method to get account holder's name
    std::string getAccountHolderName() const {
        return accountHolderName;
    }

    // Method to get account number
    std::string getAccountNumber() const {
        return accountNumber;
    }
};

int main() {
    // Create a bank account for a customer
    BankAccount account("John Doe", "123456789");

    // Perform banking operations
    account.deposit(500.0);
    account.checkBalance();

    account.withdraw(200.0);
    account.checkBalance();

    account.withdraw(400.0); // This should show an error message
    account.checkBalance();
    std::cout<<"24CE109_RishiSanja";

    return 0;
}
