#include <iostream>
#include <iomanip>
#include "../include/lib.h"

using namespace std;

int rozmiar_macierzy(int rozmiar){
    cin >> rozmiar;
    return rozmiar;
}

int **utworz_macierz(int ilosc_wierszy, int ilosc_kolumn){
    int **macierz;
    macierz = new int * [ilosc_wierszy];

    for (int i = 0; i < ilosc_wierszy; i++){
        macierz[i] = new int [ilosc_kolumn];
    }

    return macierz;
}
void wypelnianie_macierzy(int **macierz, int ilosc_wierszy, int ilosc_kolumn){
    for (int i = 0; i < ilosc_wierszy; i++){
        for(int j = 0; j < ilosc_kolumn; j++){
            cin >> macierz[i][j];
        }
    }
}

void wyswietl(int **macierz, int ilosc_wierszy, int ilosc_kolumn){
    for (int i = 0; i < ilosc_wierszy; i++){
        for(int j = 0; j < ilosc_kolumn; j++){
            cout << setw(5) << macierz[i][j];
        }
        cout << endl;
    }
}


int **addMatrix(int **macierz_a, int **macierz_b, int ilosc_wierszy, int ilosc_kolumn){
    int **macierz_w = utworz_macierz(ilosc_wierszy, ilosc_kolumn);

    for (int i = 0; i < ilosc_wierszy; i++){
        for(int j = 0; j < ilosc_kolumn; j++){
            macierz_w[i][j] = macierz_a[i][j] + macierz_b[i][j];
        }
    }
    return macierz_w;
}

int **subtractMatrix(int **macierz_a, int **macierz_b, int ilosc_wierszy, int ilosc_kolumn) {

    int **macierz_w = utworz_macierz(ilosc_wierszy, ilosc_kolumn);

    for (int i = 0; i < ilosc_wierszy; i++) {
        for (int j = 0; j < ilosc_kolumn; j++) {
            macierz_w[i][j] = macierz_a[i][j] - macierz_b[i][j];
        }
    }
    return macierz_w;
}


int **multiplyMatrix(int **macierz_a, int **macierz_b, int ilosc_wierszy_a, int ilosc_kolumn_a, int ilosc_kolumn_b){
    int **macierz_w = utworz_macierz(ilosc_wierszy_a, ilosc_kolumn_b);

    for (int i = 0; i < ilosc_wierszy_a; i++){
        for(int j = 0; j < ilosc_kolumn_b; j++){
            int suma_iloczynow = 0;
            for (int k = 0; k < ilosc_kolumn_a; k++)
                suma_iloczynow += (macierz_a[i][k] * macierz_b[k][j]);
            macierz_w[i][j] = suma_iloczynow;
        }
    }
    return macierz_w;
}

int **multiplyByScalar(int **macierz, int ilosc_wierszy,int ilosc_kolumn,int skalar){
    int **macierz_w = utworz_macierz(ilosc_wierszy, ilosc_kolumn);

    for (int i = 0; i < ilosc_wierszy; i++){
        for (int j = 0; j < ilosc_kolumn; j++){
            macierz_w[i][j] = macierz[i][j] * skalar;
        }
    }
    return macierz_w;
}

int **transpozeMatrix(int **macierz, int ilosc_wierszy, int ilosc_kolumn){
    int **macierz_w = utworz_macierz(ilosc_wierszy, ilosc_kolumn);


}


