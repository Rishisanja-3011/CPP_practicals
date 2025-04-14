#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const int MAX_LOANS = 100;

class Loan {
private:
    int loanID;
    string applicantName;
    double principal;        // Total loan amount
    double annualInterest;   // Annual interest rate in percentage
    int tenureMonths;        // Loan tenure in months

public:
    // Default constructor initializing with sample default values
    Loan() {
        loanID = 0;
        applicantName = "Default Applicant";
        principal = 100000;   // Sample default principal
        annualInterest = 10;  // Sample default annual interest rate (%)
        tenureMonths = 60;    // Sample default tenure (5 years)
    }

    // Parameterized constructor to initialize with actual values
    Loan(int id, const string &name, double amount, double interest, int tenure) {
        loanID = id;
        applicantName = name;
        principal = amount;
        annualInterest = interest;
        tenureMonths = tenure;
    }

    // Function to input loan details
    void inputLoan() {
        cout << "Enter Loan ID: ";
        cin >> loanID;
        cin.ignore();
        cout << "Enter Applicant Name: ";
        getline(cin, applicantName);
        cout << "Enter Loan Amount (Principal): ";
        cin >> principal;
        cout << "Enter Annual Interest Rate (%): ";
        cin >> annualInterest;
        cout << "Enter Loan Tenure (in months): ";
        cin >> tenureMonths;
    }

    // Function to calculate EMI based on the formula
    // EMI = P * R * (1 + R)^T / [(1 + R)^T – 1]
    double calculateEMI() const {
        // Convert annual interest rate to a monthly rate in decimal
        double monthlyRate = annualInterest / (12 * 100);
        if (monthlyRate == 0)
            return principal / tenureMonths;
        
        double compound = pow(1 + monthlyRate, tenureMonths);
        double emi = (principal * monthlyRate * compound) / (compound - 1);
        return emi;
    }

    // Function to display loan details, including the computed EMI
    void displayLoan() const {
        cout << "\nLoan ID: " << loanID << endl;
        cout << "Applicant Name: " << applicantName << endl;
        cout << "Principal Amount: Rs. " << principal << endl;
        cout << "Annual Interest Rate: " << annualInterest << "%" << endl;
        cout << "Loan Tenure: " << tenureMonths << " months" << endl;
        cout << "Calculated EMI: Rs. " << calculateEMI() << endl;
    }
};

class LoanManager {
private:
    Loan loans[MAX_LOANS];
    int count;

public:
    LoanManager() : count(0) {}

    // Add loan with manual input
    void addLoanManual() {
        if (count >= MAX_LOANS) {
            cout << "Cannot add more loans. Maximum reached." << endl;
            return;
        }
        Loan loan;
        loan.inputLoan();
        loans[count++] = loan;
        cout << "Loan added successfully." << endl;
    }

    // Add loan with default values (for testing)
    void addLoanDefault() {
        if (count >= MAX_LOANS) {
            cout << "Cannot add more loans. Maximum reached." << endl;
            return;
        }
        Loan defaultLoan; // Uses default constructor values
        loans[count++] = defaultLoan;
        cout << "Default loan added successfully." << endl;
    }

    // Display details for all loans
    void displayAllLoans() const {
        if (count == 0) {
            cout << "No loan records available." << endl;
            return;
        }
        cout << "\n--- Loan Summary ---" << endl;
        for (int i = 0; i < count; ++i) {
            cout << "\nLoan Record #" << (i + 1) << ":" << endl;
            loans[i].displayLoan();
        }
    }
};

int main() {
    LoanManager loanManager;
    int choice;

    do {
        cout << "\n--- Loan Management System ---" << endl;
        cout << "1. Add Loan (Manual Input)" << endl;
        cout << "2. Add Loan (Default Values)" << endl;
        cout << "3. Display All Loans" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                loanManager.addLoanManual();
                break;
            case 2:
                loanManager.addLoanDefault();
                break;
            case 3:
                loanManager.displayAllLoans();
                break;
            case 4:
                cout << "Exiting system..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
