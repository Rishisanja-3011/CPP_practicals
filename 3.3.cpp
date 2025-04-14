#include <iostream>
#include <string>
using namespace std;

// Bank Account class
class BankAccount {
private:
    static int totalAccounts;  // Static member to keep track of total accounts
    int accountNumber;
    string accountHolder;
    double balance;

public:
    // Constructor to initialize account with account holder's name and balance
    BankAccount(string name, double initialBalance) {
        totalAccounts++;  // Increment total accounts
        accountNumber = totalAccounts;  // Assign account number based on total accounts
        accountHolder = name;
        balance = initialBalance;
    }

    // Function to transfer money between accounts
    bool transferMoney(BankAccount &toAccount, double amount) {
        if (amount <= 0) {
            cout << "Transfer amount must be positive.\n";
            return false;
        }
        if (balance < amount) {
            cout << "Insufficient balance to transfer the amount.\n";
            return false;
        }
        balance -= amount;  // Deduct from sender account
        toAccount.balance += amount;  // Add to receiver account
        cout << "Transferred Rs. " << amount << " to Account " << toAccount.accountNumber << ".\n";
        return true;
    }

    // Function to display account details
    void displayAccountDetails() const {
        cout << "\nAccount Number: " << accountNumber
             << "\nAccount Holder: " << accountHolder
             << "\nBalance: Rs. " << balance << endl;
    }

    // Static function to get total accounts created
    static int getTotalAccounts() {
        return totalAccounts;
    }
};

// Initialize static member
int BankAccount::totalAccounts = 0;

int main() {
    BankAccount* accounts[100];  // Array of pointers to store accounts (up to 100 accounts)
    int accountCount = 0;

    // Creating some accounts
    accounts[accountCount++] = new BankAccount("Alice", 5000);
    accounts[accountCount++] = new BankAccount("Bob", 3000);

    // Displaying total accounts
    cout << "Total Accounts Created: " << BankAccount::getTotalAccounts() << endl;

    // Display account details
    accounts[0]->displayAccountDetails();
    accounts[1]->displayAccountDetails();

    // Transferring money from Alice to Bob
    accounts[0]->transferMoney(*accounts[1], 1500);

    // Displaying updated account details
    accounts[0]->displayAccountDetails();
    accounts[1]->displayAccountDetails();

    // Creating a new account dynamically
    accounts[accountCount++] = new BankAccount("Charlie", 2000);
    cout << "Total Accounts Created: " << BankAccount::getTotalAccounts() << endl;

    // Displaying Charlie's account details
    accounts[2]->displayAccountDetails();

    // Clean up dynamically allocated memory
    for (int i = 0; i < accountCount; ++i) {
        delete accounts[i];
    }

    return 0;
}

