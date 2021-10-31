#include <iostream>
#include "../include/funkcja_kwadratowa.h"

void FunkcjaKwadratowa::wpisz() {
    cout << "Wpisz a: ";
    cin >> a;
    cout << "Wpisz b: ";
    cin >> b;
    cout << "Wpisz c: ";
    cin >> c;
}

void FunkcjaKwadratowa::wyswietl() {
    cout << "f(x)=" << a << "x^2+" << b << "x+" << c <<endl;

}