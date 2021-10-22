#include <iostream>
#include <iomanip>
#include "../include/lib.h"

using namespace std;

void wypisz(int **macierz, int ilosc_wierszy, int ilosc_kolumn){
    for (int i = 0; i < ilosc_wierszy; i++){
        for(int j = 0; j < ilosc_kolumn; j++){
            cout << setw(5) << macierz[i][j];
        }
        cout << endl;
    }
}


int **addMatrix(int **macierz_a, int **macierz_b, int ilosc_wierszy, int ilosc_kolumn){
    int **macierz_w = 0;
    macierz_w = new int *[ilosc_wierszy];
    for (int i = 0; i<ilosc_wierszy; i++)
        macierz_w[i] = new int [ilosc_kolumn];

    for (int i = 0; i < ilosc_wierszy; i++){
        for(int j = 0; j < ilosc_kolumn; j++){
            macierz_w[i][j] = macierz_a[i][j] + macierz_b[i][j];
        }
    }
    return macierz_w;
}

int **subtractMatrix(int **macierz_a, int **macierz_b, int ilosc_wierszy, int ilosc_kolumn){
    int **macierz_w = NULL;
    macierz_w = new int *[ilosc_wierszy];
    for (int i = 0; i<ilosc_wierszy; i++)
        macierz_w[i] = new int [ilosc_kolumn];

    for (int i = 0; i < ilosc_wierszy; i++){
        for(int j = 0; j < ilosc_kolumn; j++){
            macierz_w[i][j] = macierz_a[i][j] - macierz_b[i][j];
        }
    }
    return macierz_w;
}

