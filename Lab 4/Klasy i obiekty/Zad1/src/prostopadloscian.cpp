#include<iostream>
#include "../include/prostopadloscian.h"

using namespace std;

void Prostopadloscian::wypelnij(){
    cout << "Prosze wprowadzic dane prostopadloscianu\na = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "h = ";
    cin >> h;
}

int Prostopadloscian::obliczanie_pola(){
    int pole;
    pole = 2 * (a*b + a*h + b*h);
    return pole;
}

