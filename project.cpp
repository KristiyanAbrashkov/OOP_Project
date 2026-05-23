//Inventory and cash system
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product{
protected:
    const int id;
    const string name;
    double price;
    int quantity;

public:
    Product(int id, string name, double price, int quantity): id(id), name(name){
        this->price = price;
        this->quantity = quantity;
    }

    virtual ~Product(){}

    virtual double calculateDiscount() const = 0;

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

    void setPrice(double price){
    this->price = price;
    }

    string getName() const{
    return name;
    }
};

class FoodProduct : public Product{
public:
    FoodProduct(int id, string name, double price, int quantity): Product(id, name, price, quantity){}

    double calculateDiscount()const override{
        return price * 0.90;
    }
};

class ElectronicProduct : public Product{
public:
    ElectronicProduct(int id, string name, double price, int quantity): Product(id, name, price, quantity){}

    double calculateDiscount()const override{
        return price * 0.80;
    }
};

void addProduct(vector<Product*>& products){
    int type;
    int id;
    string name;
    double price;
    int quantity;

    cout << "1. Food Product\n";
    cout << "2. Electronic Product\n";
    cout << "Choose type: ";
    cin >> type;

    cout << "ID: ";
    cin >> id;

    cout << "Name: ";
    cin >> name;

    cout << "Price: ";
    cin >> price;

    cout << "Quantity: ";
    cin >> quantity;

    if(type == 1)
    {
        products.push_back(new FoodProduct(id, name, price, quantity));
    }
    else
    {
        products.push_back(new ElectronicProduct(id, name, price, quantity));
    }

    cout << "Product added successfully!\n";
}

void showProducts(const vector<Product*>& products){
    for(Product* product : products)
    {
        cout << "-------------------\n";
        product->showInfo();
    }
}

void deleteProduct(vector<Product*>& products){
    int id;

    cout << "Enter ID to delete: ";
    cin >> id;

    for(int i = 0; i < products.size(); i++)
    {
        if(products[i]->getId() == id)
        {
            delete products[i];

            products.erase(products.begin() + i);

            cout << "Product deleted!\n";

            return;
        }
    }

    cout << "Product not found!\n";
}

void buyProduct(vector<Product*>& products){
    int id;
    int buyQuantity;

    cout << "Enter product ID: ";
    cin >> id;

    cout << "Quantity: ";
    cin >> buyQuantity;

    for(Product* product : products)
    {
        if(product->getId() == id)
        {
            if(buyQuantity <= product->getQuantity())
            {
                product->setQuantity(product->getQuantity() - buyQuantity);

                double total = product->calculateDiscount() * buyQuantity;

                cout << "Purchase successful!\n";
                cout << "Total: " << total << " lv\n";
            }
            else
            {
                cout << "Not enough quantity!\n";
            }

            return;
        }
    }

    cout << "Product not found!\n";
}

void updateProduct(vector<Product*>& products){
    int id;

    cout << "Enter product ID: ";
    cin >> id;

    for(Product* product : products)
    {
        if(product->getId() == id)
        {
            double newPrice;
            int newQuantity;

            cout << "New price: ";
            cin >> newPrice;

            cout << "New quantity: ";
            cin >> newQuantity;

            product->setPrice(newPrice);
            product->setQuantity(newQuantity);

            cout << "Product updated successfully!\n";

            return;
        }
    }

    cout << "Product not found!\n";
}

void searchProduct(const vector<Product*>& products){
    string keyword;
    cout << "Enter name or category to search: ";
    cin >> keyword;

    bool found = false;

    for(Product* product : products){
        if(product->getName() == keyword){
            cout << "-------------------\n";
            product->showInfo();
            found = true;
        }
    }

    if(!found) cout << "No matching products found!\n";
}

int main(){
    vector<Product*> products;
    int choice;

    do{
        cout << "\n===== INVENTORY SYSTEM =====\n";
        cout << "1. Add product\n";
        cout << "2. Show products\n";
        cout << "3. Delete product\n";
        cout << "4. Update product\n";
        cout << "5. Buy product\n";
        cout << "6. Search product\n";
        cout << "7. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if(choice == 1) addProduct(products);
        else if(choice == 2) showProducts(products);
        else if(choice == 3) deleteProduct(products);
        else if(choice == 4) updateProduct(products);
        else if(choice == 5) buyProduct(products);
        else if(choice == 6) searchProduct(products);
        
    } while(choice != 7);

   
    for(Product* product : products){delete product;}

    return 0;
}