#ifndef ELECTRONICPRODUCT_H
#define ELECTRONICPRODUCT_H

#include "Product.h"

class ElectronicProduct : public Product{
public:
    ElectronicProduct(int id, string name, double price, int quantity);

    double calculateDiscount() const override;
};

#endif