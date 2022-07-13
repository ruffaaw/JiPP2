#ifndef FINALIZE_H
#define FINALIZE_H
#include <iostream>
#include "user.h"
#include "customer.h"
#include "payment.h"
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <ctime>
class Finalize : public Customer, public Payment
{
public:
    Finalize();

    ~Finalize();

    void finalize();
};
#endif //FINALIZE_H
