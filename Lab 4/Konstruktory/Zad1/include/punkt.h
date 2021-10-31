#ifndef STUDENT_PUNKT_H
#define STUDENT_PUNKT_H
#include <iostream>
using namespace std;

struct punkt{
    int x;
    int y;
};

class Punkt{
public:
    punkt a, b;
    double oblicz();
    Punkt();
};

#endif //STUDENT_PUNKT_H
