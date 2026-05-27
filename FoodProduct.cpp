#include "FoodProduct.h"

using namespace std;

FoodProduct::FoodProduct(int id, string name, double price, int quantity): Product(id, name, price, quantity){}

double FoodProduct::calculateDiscount() const{
    return price * 0.90;
}