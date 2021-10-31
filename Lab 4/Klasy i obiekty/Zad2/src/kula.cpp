#include <iostream>
#include "../include/kula.h"
#include <math.h>

void Kula::wypelnij(){
    cout << "Prosze podac promien kuli:";
    cin >> r;
}

double Kula::obliczanie_obj(){
    return 4/3.0 * M_PI * pow(r, 3);
}
