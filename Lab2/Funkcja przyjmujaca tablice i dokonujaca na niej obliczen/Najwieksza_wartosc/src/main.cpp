//
// Created by Rafal on 19.10.2021.
//

#include<iostream>
#include "../include/max.h"


using namespace std;

int main(){
    int rozmiar_tablicy;
    int* tablica;
    cout << "Podaj rozmiar tablicy" << endl;
    cin >> rozmiar_tablicy;

    tablica = new int[rozmiar_tablicy]();

    cout << "Najwieksza wartosc " << max(tablica, rozmiar_tablicy) << endl;
    delete[] tablica;

    return 0;

}