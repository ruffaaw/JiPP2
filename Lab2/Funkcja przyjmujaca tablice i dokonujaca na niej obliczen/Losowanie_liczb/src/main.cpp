//
// Created by Rafal on 19.10.2021.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../include/funkcja.h"

using namespace std;

int main(){
    int a,b;
    cout << "Podaj przedzial wylosowanych liczb"<<endl;
    cin>>a>>b;

    cout << "Wylosowana liczba to: " << losowanie(a, b) << endl;
    return 0;
}



