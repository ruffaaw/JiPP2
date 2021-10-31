#include <iostream>
#include "../include/punkt.h"
#include <math.h>

Punkt::Punkt(){
    cout << "Wprowadz wspolrzedne a: ";
    cin >> a.x >> a.y;
    cout << "Wprowadz wsporzedne b:";
    cin >> b.x >> b.y;
}

double Punkt::oblicz() {
    double wynik;
    wynik = sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2) );
    return wynik;
}
