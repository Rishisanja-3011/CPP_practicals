#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    double basicSalary;
    double bonus;

public:
    
    Employee(string empName, double salary, double empBonus = 5000.0) {
        name = empName;
        basicSalary = salary;
        bonus = empBonus;
    }

   
    inline double getTotalSalary() const {
        return basicSalary + bonus;
    }

    
    void display() const {
        cout << "\nEmployee Name: " << name << endl;
        cout << "Basic Salary: Rs. " << basicSalary << endl;
        cout << "Bonus: Rs. " << bonus << endl;
        cout << "Total Salary: Rs. " << getTotalSalary() << endl;
    }
};

int main() {
    int num;
    cout << "Enter the number of employees: ";
    cin >> num;
    cin.ignore(); 

    Employee** employees = new Employee*[num]; 

    for (int i = 0; i < num; ++i) {
        string name;
        double salary;
        char choice;
        double bonus;

        cout << "\nEnter details for Employee #" << (i + 1) << endl;
        cout << "Name: ";
        getline(cin, name);
        cout << "Basic Salary: ";
        cin >> salary;

        cout << "Do you want to enter a custom bonus? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            cout << "Enter Bonus: ";
            cin >> bonus;
            employees[i] = new Employee(name, salary, bonus); 
        } else {
            employees[i] = new Employee(name, salary);
        }

        cin.ignore(); 
    }

    cout << "\n--- Employee Payroll Summary ---\n";
    for (int i = 0; i < num; ++i) {
        employees[i]->display();
    }

   
    for (int i = 0; i < num; ++i) {
        delete employees[i];
    }
    delete[] employees;

    return 0;
}
