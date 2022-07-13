#include "../include/shoppingCart.h"


int ShoppingCart::validation(){
    int x;
    while (!(cin >> x)){
        cout << "Enter valid number!!" << endl;
        cin.clear();
        cin.ignore(123, '\n');
    }
    return x;
}
ShoppingCart::ShoppingCart(){
    mymap["Grocery   "] = 7;
    mymap["Fast food"] = 5;
    mymap["Electronic"] = 15;
    mymap["HouseHolds"] = 20;
}

ShoppingCart::~ShoppingCart() {}

void ShoppingCart::showItems(string userId){
    cout << "Dear Customer " << userId << ", Select your items from below: " << endl;

    for (auto const &pair : mymap){
        vector<string> userls;
        int x;
        cout << "Package " << pair.first << " of Price " << pair.second << "$ EACH!" << endl;
        cout << "Enter Quantity for " << pair.first << ": ";
        x = validation();
        cout << endl;
        if (x != 0){
           userls.push_back(pair.first);
            userls.push_back(to_string(pair.second));
            userls.push_back(to_string(pair.second * x));
            // customerList.push_back()
        }
        if (!userls.empty()){
            customerList.push_back(userls);
        }
    }
}