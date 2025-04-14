#include <iostream>
#include <string>

using namespace std;

const int MAX_STUDENTS = 100;

class Student {
private:
    int rollNumber;
    string name;
    float marks[3];

public:
    // Default constructor
    Student() {
        rollNumber = 0;
        name = "Test Student";
        marks[0] = marks[1] = marks[2] = 0;
    }

    // Parameterized constructor
    Student(int roll, string studentName, float m1, float m2, float m3) {
        rollNumber = roll;
        name = studentName;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    void input() {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Marks in 3 subjects:\n";
        for (int i = 0; i < 3; ++i) {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    float calculateAverage() const {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }

    void display() const {
        cout << "\nRoll Number: " << rollNumber
             << "\nName: " << name
             << "\nMarks: ";
        for (int i = 0; i < 3; ++i) {
            cout << marks[i] << " ";
        }
        cout << "\nAverage Marks: " << calculateAverage() << endl;
    }
};

class StudentManager {
private:
    Student students[MAX_STUDENTS];
    int count;

public:
    StudentManager() {
        count = 0;
    }

    void addStudentWithInput() {
        if (count >= MAX_STUDENTS) {
            cout << "Maximum student limit reached.\n";
            return;
        }
        Student s;
        s.input();
        students[count++] = s;
        cout << "Student added successfully.\n";
    }

    void addStudentWithDefault() {
        if (count >= MAX_STUDENTS) {
            cout << "Maximum student limit reached.\n";
            return;
        }
        // Sample default values
        Student s(100 + count, "Default Student " + to_string(count + 1), 70, 75, 80);
        students[count++] = s;
        cout << "Default student added successfully.\n";
    }

    void displayAll() const {
        if (count == 0) {
            cout << "No student records to display.\n";
            return;
        }
        cout << "\n--- Student Records ---";
        for (int i = 0; i < count; ++i) {
            cout << "\n\nStudent #" << i + 1 << ":";
            students[i].display();
        }
    }
};

int main() {
    StudentManager manager;
    int choice;

    do {
        cout << "\n\n--- University Student Record System ---\n";
        cout << "1. Add Student (Custom Input)\n";
        cout << "2. Add Student (Default Values)\n";
        cout << "3. Display All Students\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addStudentWithInput();
                break;
            case 2:
                manager.addStudentWithDefault();
                break;
            case 3:
                manager.displayAll();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
