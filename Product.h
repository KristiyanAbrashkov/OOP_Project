#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

using namespace std;

class Product{
protected:
    const int id;
    const string name;
    double price;
    int quantity;

public:
    Product(int id, string name, double price, int quantity);

    virtual ~Product();

    virtual double calculateDiscount() const = 0;

    int getId() const;

    int getQuantity() const;

    double getPrice() const;

    void setQuantity(int quantity);

    void setPrice(double price);

    string getName() const;

    friend ostream& operator<<(ostream& out, const Product& product);
};

#endif