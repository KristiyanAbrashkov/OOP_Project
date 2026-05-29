#include "Functions.h"
#include "FoodProduct.h"
#include "ElectronicProduct.h"

#include <iostream>

using namespace std;

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

    if(type == 1){
        products.push_back(new FoodProduct(id, name, price, quantity));
    }
    else if(type == 2){
        products.push_back(new ElectronicProduct(id, name, price, quantity));
    }
    else{
        cout << "Invalid type!\n";
    }

    cout << "Product added successfully!\n";
}

void showProducts(const vector<Product*>& products){
    for(Product* product : products)
    {
        cout << "-------------------\n";
        cout << *product;
    }
}

void deleteProduct(vector<Product*>& products){
    int id;

    cout << "Enter ID to delete: ";
    cin >> id;

    for(size_t i = 0; i < products.size(); i++)
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
    cout << "Enter name to search: ";
    cin >> keyword;

    bool found = false;

    for(Product* product : products){
        if(product->getName() == keyword){
            cout << "-------------------\n";
            cout << *product;
            found = true;
        }
    }

    if(!found) cout << "No matching products found!\n";
}

void showLowStockProducts(const vector<Product*>& products){
    bool found = false;

    for(Product* product : products){

        if(product->getQuantity() < 5){

            cout << "-------------------\n";

            cout << *product;

            cout << "Low stock warning!\n";

            found = true;
        }
    }

    if(!found){
        cout << "No low stock products found!\n";
    }
}

void showInventoryValue(const vector<Product*>& products){

    double total = 0;

    for(Product* product : products){

        total += product->getPrice() * product->getQuantity();
    }

    cout << "Total inventory value: "
         << total << " lv\n";
}