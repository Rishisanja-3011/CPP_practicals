#include <iostream>
#include <string>

using namespace std;

const int MAX_ACCOUNTS = 100;

class BankAccount {
private:
    int accountNumber;
    string holderName;
    double balance;

public:
    // Default constructor
    BankAccount() {
        accountNumber = 0;
        holderName = "Unnamed";
        balance = 0.0;
    }

    // Parameterized constructor
    BankAccount(int accNo, string name, double initialBalance) {
        accountNumber = accNo;
        holderName = name;
        balance = initialBalance;
    }

    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        cin.ignore();
        cout << "Enter Account Holder Name: ";
        getline(cin, holderName);
        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New Balance: Rs. " << balance << endl;
        } else {
            cout << "Invalid amount. Deposit failed.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance. Withdrawal failed.\n";
        } else if (amount <= 0) {
            cout << "Invalid amount. Withdrawal failed.\n";
        } else {
            balance -= amount;
            cout << "Withdrawal successful. New Balance: Rs. " << balance << endl;
        }
    }

    void displaySummary() const {
        cout << "\nAccount Number: " << accountNumber
             << "\nHolder Name: " << holderName
             << "\nCurrent Balance: Rs. " << balance << endl;
    }

    int getAccountNumber() const {
        return accountNumber;
    }
};

class Bank {
private:
    BankAccount accounts[MAX_ACCOUNTS];
    int count;

public:
    Bank() {
        count = 0;
    }

    void createAccountManual() {
        if (count >= MAX_ACCOUNTS) {
            cout << "Cannot create more accounts.\n";
            return;
        }

        BankAccount newAccount;
        newAccount.createAccount();
        accounts[count++] = newAccount;
        cout << "Account created successfully.\n";
    }

    void createAccountDefault() {
        if (count >= MAX_ACCOUNTS) {
            cout << "Cannot create more accounts.\n";
            return;
        }

        BankAccount newAccount(1000 + count, "Default User " + to_string(count + 1), 0.0);
        accounts[count++] = newAccount;
        cout << "Default account created successfully.\n";
    }

    void depositToAccount() {
        int accNo;
        double amount;
        cout << "Enter Account Number: ";
        cin >> accNo;

        for (int i = 0; i < count; ++i) {
            if (accounts[i].getAccountNumber() == accNo) {
                cout << "Enter amount to deposit: ";
                cin >> amount;
                accounts[i].deposit(amount);
                return;
            }
        }

        cout << "Account not found.\n";
    }

    void withdrawFromAccount() {
        int accNo;
        double amount;
        cout << "Enter Account Number: ";
        cin >> accNo;

        for (int i = 0; i < count; ++i) {
            if (accounts[i].getAccountNumber() == accNo) {
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                accounts[i].withdraw(amount);
                return;
            }
        }

        cout << "Account not found.\n";
    }

    void displayAllAccounts() const {
        if (count == 0) {
            cout << "No accounts to display.\n";
            return;
        }

        for (int i = 0; i < count; ++i) {
            cout << "\n--- Account #" << i + 1 << " ---";
            accounts[i].displaySummary();
        }
    }
};

int main() {
    Bank bank;
    int choice;

    do {
        cout << "\n--- Bank Account Management System ---\n";
        cout << "1. Create Account (Manual Input)\n";
        cout << "2. Create Account (Default Values)\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Display All Accounts\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bank.createAccountManual();
                break;
            case 2:
                bank.createAccountDefault();
                break;
            case 3:
                bank.depositToAccount();
                break;
            case 4:
                bank.withdrawFromAccount();
                break;
            case 5:
                bank.displayAllAccounts();
                break;
            case 6:
                cout << "Exiting system...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}

