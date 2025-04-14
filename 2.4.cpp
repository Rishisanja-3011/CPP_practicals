#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 100;

class Item {
private:
    int itemID;
    string itemName;
    float price;
    int quantity;

public:
    // Default constructor
    Item() {
        itemID = 0;
        itemName = "Unnamed";
        price = 0.0;
        quantity = 0;
    }

    // Parameterized constructor
    Item(int id, string name, float pr, int qty) {
        itemID = id;
        itemName = name;
        price = pr;
        quantity = qty;
    }

    void inputItem() {
        cout << "Enter Item ID: ";
        cin >> itemID;
        cin.ignore();
        cout << "Enter Item Name: ";
        getline(cin, itemName);
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    void addStock(int qty) {
        if (qty > 0) {
            quantity += qty;
            cout << "Stock updated. New quantity: " << quantity << endl;
        } else {
            cout << "Invalid quantity to add.\n";
        }
    }

    void sellItem(int qty) {
        if (qty <= 0) {
            cout << "Invalid quantity to sell.\n";
        } else if (qty > quantity) {
            cout << "Not enough stock to sell. Available: " << quantity << endl;
        } else {
            quantity -= qty;
            cout << "Sale successful. Remaining quantity: " << quantity << endl;
        }
    }

    void displayItem() const {
        cout << "\nItem ID: " << itemID
             << "\nItem Name: " << itemName
             << "\nPrice: Rs. " << price
             << "\nQuantity in Stock: " << quantity << endl;
    }

    int getItemID() const {
        return itemID;
    }
};

class Inventory {
private:
    Item items[MAX_ITEMS];
    int count;

public:
    Inventory() {
        count = 0;
    }

    void addItemManual() {
        if (count >= MAX_ITEMS) {
            cout << "Inventory full.\n";
            return;
        }

        Item newItem;
        newItem.inputItem();
        items[count++] = newItem;
        cout << "Item added successfully.\n";
    }

    void addItemDefault() {
        if (count >= MAX_ITEMS) {
            cout << "Inventory full.\n";
            return;
        }

        Item defaultItem(1000 + count, "Default Item " + to_string(count + 1), 50.0, 10);
        items[count++] = defaultItem;
        cout << "Default item added.\n";
    }

    void addStockToItem() {
        int id, qty;
        cout << "Enter Item ID to add stock: ";
        cin >> id;
        for (int i = 0; i < count; ++i) {
            if (items[i].getItemID() == id) {
                cout << "Enter quantity to add: ";
                cin >> qty;
                items[i].addStock(qty);
                return;
            }
        }
        cout << "Item not found.\n";
    }

    void sellItemByID() {
        int id, qty;
        cout << "Enter Item ID to sell: ";
        cin >> id;
        for (int i = 0; i < count; ++i) {
            if (items[i].getItemID() == id) {
                cout << "Enter quantity to sell: ";
                cin >> qty;
                items[i].sellItem(qty);
                return;
            }
        }
        cout << "Item not found.\n";
    }

    void displayAllItems() const {
        if (count == 0) {
            cout << "No items in inventory.\n";
            return;
        }

        for (int i = 0; i < count; ++i) {
            cout << "\n--- Item #" << i + 1 << " ---";
            items[i].displayItem();
        }
    }
};

int main() {
    Inventory inventory;
    int choice;

    do {
        cout << "\n--- Retail Store Inventory Management ---\n";
        cout << "1. Add New Item (Manual Input)\n";
        cout << "2. Add New Item (Default Values)\n";
        cout << "3. Add Stock to Item\n";
        cout << "4. Sell Item\n";
        cout << "5. Display Inventory\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: inventory.addItemManual(); break;
            case 2: inventory.addItemDefault(); break;
            case 3: inventory.addStockToItem(); break;
            case 4: inventory.sellItemByID(); break;
            case 5: inventory.displayAllItems(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}

