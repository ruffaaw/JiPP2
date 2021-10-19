//
// Created by Rafal on 19.10.2021.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../include/funkcja.h"


int losowanie(int a, int b){
    srand(time(NULL));
    int liczba_wylosowana;
    liczba_wylosowana = (rand() % b) + a;
    return liczba_wylosowana;

}