#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include <iostream>
#include "user.h"
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

class ShoppingCart
{
protected:
    vector<vector<string>> customerList;
    //bool order = false;
    map<string, int> mymap;

public:

    int validation();

    ShoppingCart();

    ~ShoppingCart();

    void showItems(string userId);

};


#endif //SHOPPINGCART_H
