#include "ElectronicProduct.h"

using namespace std;

ElectronicProduct::ElectronicProduct(int id, string name, double price, int quantity): Product(id, name, price, quantity){}

double ElectronicProduct::calculateDiscount() const{
    return price * 0.80;
}