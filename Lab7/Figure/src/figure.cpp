#include <iostream>
#include "../include/figure.h"
#include <math.h>
#define PI 3.14

void Figure::print() {
    cout << "Nazwa: " << this -> name << "Kolor: " << this -> color << endl;
}

Circle::Circle(double r):r(r) {}

double Circle::getArea() {
    return PI * r * r;
};

double Triangle::pole() {
    return abs((b.x - a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x));
}

double Triangle::obwod() {
    float ab=sqrt(pow((a.x-b.x),2) + pow((a.y-b.y),2));
    float bc=sqrt(pow((b.x-c.x), 2)+pow((b.y-c.y),2));
    float ca=sqrt(pow((c.x-a.x),2)+pow((c.y-a.y), 2));
    return ab + bc + ca;
}

