#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include "user.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
class Customer : public User
{
protected:
    bool ans = false;
    string contactNumber, address;

public:
    void working();

    bool returnAuthorized();

    void customerData();

};

#endif //CUSTOMER_H
