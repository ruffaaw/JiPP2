#ifndef PUNKT_FIGURA_H
#define PUNKT_FIGURA_H
#include <iostream>
using namespace std;

struct punkt{
    int x;
    int y;
};

class Figura{
public:
    int ilosc_wierzcholkow;
    punkt *wierzcholki;

    Figura(int ilosc);
};
#endif //PUNKT_FIGURA_H
