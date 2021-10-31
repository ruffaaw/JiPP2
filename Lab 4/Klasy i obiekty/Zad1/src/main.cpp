#include <iostream>
#include "../include/prostopadloscian.h"
using namespace std;

int main(){
    Prostopadloscian figura;
    figura.wypelnij();
    cout << "Pole wynosi: " << figura.obliczanie_pola() << endl;
    return 0;
}

