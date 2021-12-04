#include <iostream>
#include "../include/figure.h"

using namespace std;

int main(){
    Figure *circle = new Circle(5);
    cout << "Circle area: " << circle->getArea() << endl;
}