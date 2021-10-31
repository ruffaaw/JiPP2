#include <iostream>
#include "../include/destruktor.h"

Destruktor::Destruktor() {
    tab = new int [1024];
    cout << "Konstruktor wywolany!" << endl;
}

void Destruktor::pause(){
    system("PAUSE");
}

Destruktor::~Destruktor() {
    cout << "Destruktor wywolany!" << endl;
    delete[] tab;
}
