//Inventory and cash system
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product
{
protected:
    const int id;
    const string name;
    double price;
    int quantity;

public:
    Product(const int id, const string& name, double price, int quantity): id(id), name(name){
        this->price = price;
        this->quantity = quantity;
    }

    virtual ~Product() = default;

    virtual double calculateDiscount() = 0;

    virtual void showInfo()const{
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
    }

    int getId() const{
        return id;
    }

    int getQuantity() const{
        return quantity;
    }

    void setQuantity(int quantity){
        this->quantity = quantity;
    }
};

int main()
{
    int choice;

    do
    {
        cout << "\n===== INVENTORY SYSTEM =====\n";
        cout << "1. Add product\n";
        cout << "2. Show products\n";
        cout << "3. Delete product\n";
        cout << "4. Buy product\n";
        cout << "5. Exit\n";
        cout << "Choose: ";
        cin >> choice;

    } while(choice != 5);

    return 0;
}