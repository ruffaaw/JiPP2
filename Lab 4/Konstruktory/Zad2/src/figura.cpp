#include <iostream>
#include "../include/figura.h"

using namespace std;

Figura::Figura(int ilosc) {
    wierzcholki = new punkt[ilosc];

    for (int i = 0; i < ilosc; i++){
        cout << "Podaj wspolrzedne wierzcholka: " << endl;
        cin >> wierzcholki[i].x >> wierzcholki[i].y;
    }
}