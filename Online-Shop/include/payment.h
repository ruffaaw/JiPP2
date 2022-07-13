#ifndef PAYMENT_H
#define PAYMENT_H
#include <iostream>
#include "user.h"
#include "shoppingCart.h"
#include <string>
#include <sstream>

using namespace std;

class Payment : public ShoppingCart
{
protected:
    double totalCost = 0;
    bool done = false;
    static int OrderNumber;
    string paymentMethod;
    string card;
    string pin;

public:
    Payment();

    ~Payment();

    void showCosts();

    void agrii();

};

#endif //PAYMENT_H
