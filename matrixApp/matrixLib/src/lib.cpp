#include <iostream>
#include <iomanip>
#include "../include/lib.h"

using namespace std;

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
    int **macierz_w = utworz_macierz(ilosc_kolumn, ilosc_wierszy);

    for(int i = 0; i < ilosc_wierszy; i++){
        for (int j = 0; j < ilosc_kolumn; j++){
            macierz_w[j][i] = macierz[i][j];
        }
    }
    return macierz_w;
}

int **powerMatrix(int **macierz, int ilosc_wierszy, int ilosc_kolumn, int potega){
    int **macierz_w = utworz_macierz(ilosc_wierszy, ilosc_kolumn);
/*    for (int p = 1; p < potega; p++) {
        for (int i = 0; i < ilosc_wierszy; i++) {
            for (int j = 0; j < ilosc_kolumn; j++) {
                int suma_iloczynow = 0;
                for (int k = 0; k < ilosc_kolumn; k++)
                    suma_iloczynow += (macierz[i][k] * macierz[k][j]);
                macierz_w[i][j] = suma_iloczynow;
                }
            }
        }
        return macierz_w;*/
    if (potega == 0){
        for (int i = 0; i < ilosc_wierszy; i++){
            for (int j = 0; j < ilosc_kolumn; j++){
                if (i == j){
                    macierz_w[i][j] = 1;
                }
                else{
                    macierz_w[i][j] = 0;
                }
            }
        }
        return macierz_w;
    }

    else if (potega == 1){
        for (int i = 0; i < ilosc_wierszy; i++){
            for(int j = 0; j < ilosc_kolumn; j++){
                macierz_w[i][j] = macierz[i][j];
            }
        }
        return macierz_w;
    }

    else {
      return multiplyMatrix(macierz, powerMatrix(macierz, ilosc_wierszy, ilosc_kolumn, potega - 1), ilosc_wierszy, ilosc_kolumn, ilosc_kolumn);
    }
}

int **submatrix(int **macierz, int index_wierszy, int index_kolumn, int rozmiar_macierzy){
    int i = 0;
    int j = 0;

    int **macierz_w = utworz_macierz(rozmiar_macierzy, rozmiar_macierzy);

    for (int w = 0; w < rozmiar_macierzy; w++){
        for (int k = 0; k < rozmiar_macierzy; k++){
            if (w != index_wierszy && k != index_kolumn){
                macierz_w[i][j++] = macierz[w][k];

                if (j == rozmiar_macierzy - 1){
                    j = 0;
                    i++;
                }
            }
        }
    }
    return macierz_w;
}

int determinantMatrix(int **macierz, int ilosc_wierszy, int ilosc_kolumn){
    if (ilosc_wierszy == 1){
        return macierz[0][0];
    }
    else if(ilosc_wierszy == 2){
        return (macierz[0][0] * macierz[1][1])-(macierz[0][1] * macierz[1][0]);
    }
    else{
        int suma = 0;
        int znak = 1;
        int **pod_macierz;

        for(int i = 0; i < ilosc_wierszy; i++){
            pod_macierz = submatrix(macierz, 0, i, ilosc_wierszy);
            suma += znak * macierz[0][i] * determinantMatrix(pod_macierz, ilosc_wierszy - 1, ilosc_wierszy -1);
            znak = -znak;
        }

        return suma;

    }
}

