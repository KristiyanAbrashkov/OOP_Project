//Inventory and cash system
#include <iostream>
#include <vector>

#include "Functions.h"

using namespace std;

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
        cout << "7. Show low stock\n";
        cout << "8. Show inventory value\n";
        cout << "9. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if(choice == 1) addProduct(products);
        else if(choice == 2)showProducts(products);
        else if(choice == 3) deleteProduct(products);
        else if(choice == 4) updateProduct(products);
        else if(choice == 5) buyProduct(products);
        else if(choice == 6) searchProduct(products);
        else if(choice == 7) showLowStockProducts(products);
        else if(choice == 8) showInventoryValue(products);

    } while(choice != 9);

    for(Product* product : products){
        delete product;
    }

    return 0;
}