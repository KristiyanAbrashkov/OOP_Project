#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>

#include "Product.h"

using namespace std;

void addProduct(vector<Product*>& products);

void showProducts(const vector<Product*>& products);

void deleteProduct(vector<Product*>& products);

void updateProduct(vector<Product*>& products);

void buyProduct(vector<Product*>& products);

void searchProduct(const vector<Product*>& products);

void showLowStockProducts(const vector<Product*>& products);

void showInventoryValue(const vector<Product*>& products);

void saveProductsToFile(const vector<Product*>& products);

void loadProductsFromFile(vector<Product*>& products);

#endif