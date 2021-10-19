//
// Created by Rafal on 19.10.2021.
//
#include <iostream>
#include "../include/funkcje.h"

int main(){
    int tablica[] = {5,6,-2,18,-5};
    int rozmiar_tablicy = sizeof(tablica) / sizeof(tablica[0]);

    wypisz(tablica, rozmiar_tablicy);
    odwracanie(tablica, rozmiar_tablicy);
    wypisz(tablica, rozmiar_tablicy);

    return 0;
}
