#include <iostream>
#include <string>
#include <vector>
using namespace std;


class BankAccount {
private:
    static int totalAccounts; 
    int accountNumber;
    string accountHolder;
    double balance;

public:
   
    BankAccount(string name, double initialBalance) {
        totalAccounts++;  
        accountNumber = totalAccounts; 
        accountHolder = name;
        balance = initialBalance;
    }

    
    bool transferMoney(BankAccount& toAccount, double amount) {
        if (amount <= 0) {
            cout << "Transfer amount must be positive.\n";
            return false;
        }
        if (balance < amount) {
            cout << "Insufficient balance to transfer the amount.\n";
            return false;
        }
        balance -= amount;  
        toAccount.balance += amount;  
        cout << "Transferred Rs. " << amount << " to Account " << toAccount.accountNumber << ".\n";
        return true;
    }

    
    void displayAccountDetails() const {
        cout << "\nAccount Number: " << accountNumber
             << "\nAccount Holder: " << accountHolder
             << "\nBalance: Rs. " << balance << endl;
    }

    
    static int getTotalAccounts() {
        return totalAccounts;
    }

    
    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }
};


int BankAccount::totalAccounts = 0;

class BankSystem {
private:
    vector<BankAccount*> accounts;  

public:
   
    void addAccount(string name, double initialBalance) {
        BankAccount* newAccount = new BankAccount(name, initialBalance);
        accounts.push_back(newAccount);
        cout << "New account created successfully with Account Number: " << newAccount->getAccountNumber() << endl;
    }

    
    BankAccount* findAccount(int accountNumber) {
        for (auto account : accounts) {
            if (account->getAccountNumber() == accountNumber) {
                return account;
            }
        }
        return nullptr;  
    }

   
    void displayAllAccounts() const {
        cout << "\nAll Accounts:\n";
        for (auto account : accounts) {
            account->displayAccountDetails();
        }
    }

    
    void displayTotalAccounts() const {
        cout << "Total number of accounts: " << BankAccount::getTotalAccounts() << endl;
    }

    
    ~BankSystem() {
        for (auto account : accounts) {
            delete account;
        }
    }
};

int main() {
    BankSystem bank;

    
    bank.addAccount("Alice", 5000);
    bank.addAccount("Bob", 3000);
    bank.addAccount("Charlie", 7000);

    
    bank.displayTotalAccounts();

 
    bank.displayAllAccounts();

   
    int senderAccountNumber, receiverAccountNumber;
    double transferAmount;

    cout << "\nEnter sender account number: ";
    cin >> senderAccountNumber;
    cout << "Enter receiver account number: ";
    cin >> receiverAccountNumber;
    cout << "Enter transfer amount: ";
    cin >> transferAmount;

    BankAccount* sender = bank.findAccount(senderAccountNumber);
    BankAccount* receiver = bank.findAccount(receiverAccountNumber);

    if (sender != nullptr && receiver != nullptr) {
        sender->transferMoney(*receiver, transferAmount);
    } else {
        cout << "Account not found!\n";
    }

   
    bank.displayAllAccounts();

   
    bank.displayTotalAccounts();

    return 0;
}
