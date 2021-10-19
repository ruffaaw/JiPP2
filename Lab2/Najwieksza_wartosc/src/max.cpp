//
// Created by Rafal on 19.10.2021.
//
#include <iostream>
#include "../include/max.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int max(int *tablica, int rozmiar_tablicy){
    int i, najwieksza_wartosc = 0;
    srand(time(NULL));

        for ( i = 0; i < rozmiar_tablicy; i++){
            tablica[i] = (rand()%100)+1;
        }

        for (i =0; i < rozmiar_tablicy; i++){
           if(najwieksza_wartosc < tablica[i]){
               najwieksza_wartosc = tablica[i];
           }
        }

        return najwieksza_wartosc;
}

