#ifndef MATRIXAPP_FIGURE_H
#define MATRIXAPP_FIGURE_H
#include <iostream>

using namespace std;

struct point{
    double x, y;
};

class Figure{
    string name, color;
public:
    void print();
    virtual double getArea() = 0;
};

class Circle: public Figure{
    double r;
public:
    Circle(double r);
    double getArea();
};

class Triangle: public Figure{
    point a, b, c;
public:
    double pole();
    double obwod();
};
#endif //MATRIXAPP_FIGURE_H
