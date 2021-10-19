#include <iostream>
#include "../include/calc.h"

using namespace std;
int x,y,h,H;

int add(){
    //int x,y;
    cout << "Wpisz dwie liczby aby je dodac" << endl;
    cin >> x;
    cin >>y;
    return (x+y);
}

int subtract(){
    cout << "Wpisz dwie liczby aby je odjac" << endl;
    cin >> x;
    cin >> y;
    return(x-y);
}

float volume(){
    cout << "Wpisz trzy liczby aby obliczyc objetosc graniastoslupa o podstawie trapeza:";
    cout << "\nPierwsza dlugosc podstawy - ";
    cin >> x;
    cout << "\nDruga dlugosc polowy - ";
    cin >> y;
    cout << "\nWysokosc trapezu - ";
    cin >> h;
    cout << "\nWysokosc graniastoslupa - ";
    cin >> H;

    return (((x+y)*h/2)*H);

}

void help(){
    cout << "Wpisz:\n\tadd - by dodac\n\tsubstract - odjac\n\tvolume - obliczyc objetosc graniastrupa"<<endl;
}




