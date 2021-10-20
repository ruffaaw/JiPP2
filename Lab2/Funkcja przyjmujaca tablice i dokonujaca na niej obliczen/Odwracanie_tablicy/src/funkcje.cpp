//
// Created by Rafal on 19.10.2021.
//
#include <iostream>
#include "../include/funkcje.h"

using namespace std;

void wypisz(int tablica[], int rozmiar_tablicy){
    for (int i = 0; i < rozmiar_tablicy; i++){
        cout << tablica[i] << " ";
    }
    cout << endl;
}

void odwracanie(int tablica[], int rozmiar_tablicy){
    double temp;
    for(int i = 0; i < rozmiar_tablicy/2; i++){
        temp = tablica[rozmiar_tablicy-i-1];
        tablica[rozmiar_tablicy-i-1] = tablica[i];
        tablica[i] = temp;
    }
}

