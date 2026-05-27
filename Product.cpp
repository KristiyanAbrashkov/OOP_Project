#include "Product.h"

using namespace std;

Product::Product(int id, string name, double price, int quantity): id(id), name(name){
    this->price = price;
    this->quantity = quantity;
}

Product::~Product(){}

int Product::getId() const{
    return id;
}

int Product::getQuantity() const{
    return quantity;
}

double Product::getPrice() const{
    return price;
}

void Product::setQuantity(int quantity){
    this->quantity = quantity;
}

void Product::setPrice(double price){
    this->price = price;
}

string Product::getName() const{
    return name;
}

ostream& operator<<(ostream& out, const Product& product){
    out << "ID: " << product.id << endl;
    out << "Name: " << product.name << endl;
    out << "Price: " << product.price << endl;
    out << "Discount price: "<< product.calculateDiscount() << endl;
    out << "Quantity: " << product.quantity << endl;

    return out;
}