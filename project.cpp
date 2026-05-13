//Inventory and cash system
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int choice;

    do
    {
        cout << "\n===== INVENTORY SYSTEM =====\n";
        cout << "1. Add product\n";
        cout << "2. Show products\n";
        cout << "3. Delete product\n";
        cout << "4. Buy product\n";
        cout << "5. Exit\n";
        cout << "Choose: ";
        cin >> choice;

    } while(choice != 5);

    return 0;
}