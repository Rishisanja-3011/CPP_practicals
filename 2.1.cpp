#include <iostream>

using namespace std;

const int MAX_RECTANGLES = 100;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle() {
        length = 0;
        width = 0;
    }

    void setDimensions(double l, double w) {
        if (l > 0 && w > 0) {
            length = l;
            width = w;
        } else {
            cout << "Invalid dimensions. Length and width must be positive.\n";
        }
    }

    void updateDimensions() {
        double l, w;
        cout << "Enter new length: ";
        cin >> l;
        cout << "Enter new width: ";
        cin >> w;
        setDimensions(l, w);
        cout << "Dimensions updated.\n";
    }

    double getArea() const {
        return length * width;
    }

    double getPerimeter() const {
        return 2 * (length + width);
    }

    void display() const {
        cout << "Length: " << length << ", Width: " << width
             << ", Area: " << getArea()
             << ", Perimeter: " << getPerimeter() << endl;
    }
};

class RectangleManager {
private:
    Rectangle rectangles[MAX_RECTANGLES];
    int count;

public:
    RectangleManager() {
        count = 0;
    }

    void addRectangle() {
        if (count >= MAX_RECTANGLES) {
            cout << "Maximum rectangle limit reached.\n";
            return;
        }

        double l, w;
        cout << "Enter length: ";
        cin >> l;
        cout << "Enter width: ";
        cin >> w;

        rectangles[count].setDimensions(l, w);
        count++;

        cout << "Rectangle added successfully.\n";
    }

    void updateRectangle() {
        int index;
        cout << "Enter rectangle index (0 to " << count - 1 << ") to update: ";
        cin >> index;

        if (index >= 0 && index < count) {
            rectangles[index].updateDimensions();
        } else {
            cout << "Invalid index.\n";
        }
    }

    void displayAll() const {
        if (count == 0) {
            cout << "No rectangles to display.\n";
            return;
        }

        cout << "\n--- All Rectangles ---\n";
        for (int i = 0; i < count; ++i) {
            cout << "Rectangle #" << i << ": ";
            rectangles[i].display();
        }
    }
};

int main() {
    RectangleManager manager;
    int choice;

    do {
        cout << "\n--- Rectangle Management System ---\n";
        cout << "1. Add Rectangle\n";
        cout << "2. Update Rectangle\n";
        cout << "3. Display All Rectangles\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addRectangle();
                break;
            case 2:
                manager.updateRectangle();
                break;
            case 3:
                manager.displayAll();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
