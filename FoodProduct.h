#ifndef FOODPRODUCT_H
#define FOODPRODUCT_H

#include "Product.h"

class FoodProduct : public Product{
public:
    FoodProduct(int id, string name, double price, int quantity);

    double calculateDiscount() const override;
};

#endif