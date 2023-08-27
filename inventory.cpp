#include <iostream>
#include <string>
#include <map>
using namespace std;

class Vegetable {
public:
    string name;
    int quantity;
    double price;

    Vegetable(string n, int q, double p) : name(n), quantity(q), price(p) {}
};

class Inventory {
private:
    map<string, Vegetable> vegetables;

public:
    void addVegetable(string name, int quantity, double price) {
        Vegetable veg(name, quantity, price);
        vegetables[name] = veg;
    }

    bool updateVegetable(string name, int newQuantity, double newPrice) {
        if (vegetables.find(name) != vegetables.end()) {
            vegetables[name].quantity = newQuantity;
            vegetables[name].price = newPrice;
            return true;
        }
        return false;
    }

    bool deleteVegetable(string name) {
        if (vegetables.find(name) != vegetables.end()) {
            vegetables.erase(name);
            return true;
        }
        return false;
    }

    void viewInventory() {
        if (vegetables.empty()) {
            cout << "Inventory is empty." << endl;
        } else {
            cout << "Inventory:" << endl;
            for (const auto& entry : vegetables) {
                const Vegetable& veg = entry.second;
                cout << "Name: " << veg.name << " | Quantity: " << veg.quantity << " | Price: " << veg.price << endl;
            }
        }
    }
};

int main() {
    Inventory inventory;

    while (true) {
        cout << "Choose an action:" << endl;
        cout << "1. Add Vegetable" << endl;
        cout << "2. Update Vegetable" << endl;
        cout << "3. Delete Vegetable" << endl;
        cout << "4. View Inventory" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cin >> choice;
        cin.ignore(); // Clear the newline character

        string name;
        int quantity;
        double price;

        switch (choice) {
            case 1:
                cout << "Enter vegetable name: ";
                getline(cin, name);
                cout << "Enter quantity: ";
                cin >> quantity;
                cout << "Enter price: ";
                cin >> price;
                cin.ignore(); // Clear the newline character

                inventory.addVegetable(name, quantity, price);
                break;

            case 2:
                cout << "Enter vegetable name: ";
                getline(cin, name);
                cout << "Enter new quantity: ";
                cin >> quantity;
                cout << "Enter new price: ";
                cin >> price;
                cin.ignore(); // Clear the newline character

                if (inventory.updateVegetable(name, quantity, price)) {
                    cout << "Vegetable updated." << endl;
                } else {
                    cout << "Vegetable not found." << endl;
                }
                break;

            case 3:
                cout << "Enter vegetable name: ";
                getline(cin, name);

                if (inventory.deleteVegetable(name)) {
                    cout << "Vegetable deleted." << endl;
                } else {
                    cout << "Vegetable not found." << endl;
                }
                break;

            case 4:
                inventory.viewInventory();
                break;

            case 5:
                cout << "Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please select a valid option." << endl;
                break;
        }
    }

    return 0;
}

