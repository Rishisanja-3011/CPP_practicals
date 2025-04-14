#include <iostream>
#include <string>

using namespace std;

const int MAX_PRODUCTS = 100;

class Product {
private:
    int id;
    string name;
    int quantity;
    double price;

public:
    void input() {
        cout << "Enter Product ID: ";
        cin >> id;
        cout << "Enter Product Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Quantity: ";
        cin >> quantity;
        cout << "Enter Price per unit: ";
        cin >> price;
    }

    void updateQuantity(int qty) {
        quantity = qty;
    }

    int getId() const {
        return id;
    }

    double getValue() const {
        return quantity * price;
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Qty: " << quantity << ", Price: " << price << endl;
    }
};

class Inventory {
private:
    Product products[MAX_PRODUCTS];
    int size;

public:
    Inventory() {
        size = 0;
    }

    void addProduct() {
        if (size >= MAX_PRODUCTS) {
            cout << "Inventory is full!\n";
            return;
        }
        products[size].input();
        size++;
        cout << "Product added successfully.\n";
    }

    void updateQuantity() {
        int id, qty;
        cout << "Enter Product ID to update quantity: ";
        cin >> id;
        bool found = false;
        for (int i = 0; i < size; ++i) {
            if (products[i].getId() == id) {
                cout << "Enter new quantity: ";
                cin >> qty;
                products[i].updateQuantity(qty);
                cout << "Quantity updated successfully.\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Product not found.\n";
        }
    }

    void calculateTotalValue() const {
        double total = 0;
        for (int i = 0; i < size; ++i) {
            total += products[i].getValue();
        }
        cout << "Total Inventory Value: Rs. " << total << endl;
    }

    void displayAll() const {
        cout << "--- Product List ---\n";
        for (int i = 0; i < size; ++i) {
            products[i].display();
        }
    }
};

int main() {
    Inventory inventory;
    int choice;

    do {
        cout << "\n--- Inventory Management (OOP Approach) ---\n";
        cout << "1. Add Product\n";
        cout << "2. Update Quantity\n";
        cout << "3. Calculate Inventory Value\n";
        cout << "4. Display All Products\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inventory.addProduct();
                break;
            case 2:
                inventory.updateQuantity();
                break;
            case 3:
                inventory.calculateTotalValue();
                break;
            case 4:
                inventory.displayAll();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
