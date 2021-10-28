#include <iostream>
#include <iomanip>
#include "../include/lib.h"

using namespace std;

void help(){
    cout << "Kalkulator oblicza rozne rodzaje operacji na macierzach.\n"
    << "Uzytkownik sam wybiera rozmiary oraz wartosci macierzy.\n"
    << "Ponizej znajduje sie lista funkcji oraz komendy, ktorych nalezy uzyc aby je wywolac:\n\n";
    cout << "Dodawanie dwoch macierzy     \t\t\t\t-\tadd Matrix" << endl;
    cout << "Odejmowanie dwoch macierzy   \t\t\t\t-\tsubtractMatrix" << endl;
    cout << "Mnozenie dwoch macierzy   \t\t\t\t\t-\tmultiplyMatrix" << endl;
    cout << "Mnozenie przez skalar   \t\t\t\t\t-\tmultiplyByScalar" << endl;
    cout << "Transponowanie macierzy  \t\t\t\t\t-\ttranspozeMatrix" << endl;
    cout << "Potegowanie macierzy     \t\t\t\t\t-\tpowerMatrix" << endl;
    cout << "Wyznacznik macierzy   \t\t\t\t\t\t-\tdeterminantMatrix" << endl;
    cout << "Sprawdzanie czy macierz jest diagonalna\t\t-\tmatrixIsDiagonal" << endl;
    cout << "Zamiana dwoch wartosci miejscami\t\t\t-\tswap" << endl;
    cout << "Sortowanie tablicy\t\t\t\t\t\t\t-\tsortRow" << endl;
    cout << "Sortowanie wszystkich wierszy w macierzy\t-\tsortRowsInMatrix" << endl << endl;
    cout << "Nastepnie uzytkownik wybiera typ zmiennych wartosci macierzy" << endl;
    cout << "[0]\t-\tliczby calkowite (int)\n[1]\t-\tliczby zmiennoprzecinkowe(double)"<<endl;

}

int **utworz_macierz_int(int ilosc_wierszy, int ilosc_kolumn){
    int **macierz;
    macierz = new int * [ilosc_wierszy];

    for (int i = 0; i < ilosc_wierszy; i++){
        macierz[i] = new int [ilosc_kolumn];
    }

    return macierz;
}

double **utworz_macierz_double(int ilosc_wierszy, int ilosc_kolumn){
    double **macierz;
    macierz = new double * [ilosc_wierszy];

    for (int i = 0; i < ilosc_wierszy; i++){
        macierz[i] = new double [ilosc_kolumn];
    }

    return macierz;
}

bool wypelnianie_macierzy(int **macierz, int ilosc_wierszy, int ilosc_kolumn){
    for (int i = 0; i < ilosc_wierszy; i++){
        for(int j = 0; j < ilosc_kolumn; j++){
            if(!(cin >> macierz[i][j])){
                //zabezpieczenie przed wprowadzeniem tekstu zamiast liczby
                cout << "Wprowadzono nieprawidlowe znaki\n" <<endl;
                return false;
            }
        }
    }
    return true;
}

bool wypelnianie_macierzy(double **macierz, int ilosc_wierszy, int ilosc_kolumn){
    for (int i = 0; i < ilosc_wierszy; i++){
        for(int j = 0; j < ilosc_kolumn; j++){
            if(!(cin >> macierz[i][j])){
                //zabezpieczenie przed wprowadzeniem tekstu zamiast liczby
                cout << "Wprowadzono nieprawidlowe znaki\n" <<endl;
                return false;
            }
        }
    }
    return true;
}


void wyswietl(int **macierz, int ilosc_wierszy, int ilosc_kolumn){
    for (int i = 0; i < ilosc_wierszy; i++){
        for(int j = 0; j < ilosc_kolumn; j++){
            cout << setw(5) << macierz[i][j];
        }
        cout << endl;
    }
}

void wyswietl(double **macierz, int ilosc_wierszy, int ilosc_kolumn){
    for (int i = 0; i < ilosc_wierszy; i++){
        for(int j = 0; j < ilosc_kolumn; j++){
            cout << setw(5) << macierz[i][j];
        }
        cout << endl;
    }
}


int **addMatrix(int **macierz_a, int **macierz_b, int ilosc_wierszy, int ilosc_kolumn){
    int **macierz_w = utworz_macierz_int(ilosc_wierszy, ilosc_kolumn);

    for (int i = 0; i < ilosc_wierszy; i++){
        for(int j = 0; j < ilosc_kolumn; j++){
            macierz_w[i][j] = macierz_a[i][j] + macierz_b[i][j];
        }
    }
    return macierz_w;
}

double **addMatrix(double **macierz_a, double **macierz_b, int ilosc_wierszy, int ilosc_kolumn){
    double **macierz_w = utworz_macierz_double(ilosc_wierszy, ilosc_kolumn);

    for (int i = 0; i < ilosc_wierszy; i++){
        for(int j = 0; j < ilosc_kolumn; j++){
            macierz_w[i][j] = macierz_a[i][j] + macierz_b[i][j];
        }
    }
    return macierz_w;
}

int **subtractMatrix(int **macierz_a, int **macierz_b, int ilosc_wierszy, int ilosc_kolumn) {

    int **macierz_w = utworz_macierz_int(ilosc_wierszy, ilosc_kolumn);

    for (int i = 0; i < ilosc_wierszy; i++) {
        for (int j = 0; j < ilosc_kolumn; j++) {
            macierz_w[i][j] = macierz_a[i][j] - macierz_b[i][j];
        }
    }
    return macierz_w;
}
double **subtractMatrix(double **macierz_a, double **macierz_b, int ilosc_wierszy, int ilosc_kolumn){

    double **macierz_w = utworz_macierz_double(ilosc_wierszy, ilosc_kolumn);

    for (int i = 0; i < ilosc_wierszy; i++) {
        for (int j = 0; j < ilosc_kolumn; j++) {
            macierz_w[i][j] = macierz_a[i][j] - macierz_b[i][j];
        }
    }
    return macierz_w;
}

int **multiplyMatrix(int **macierz_a, int **macierz_b, int ilosc_wierszy_a, int ilosc_kolumn_a, int ilosc_kolumn_b){
    int **macierz_w = utworz_macierz_int(ilosc_wierszy_a, ilosc_kolumn_b);

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

double **multiplyMatrix(double **macierz_a, double **macierz_b, int ilosc_wierszy_a, int ilosc_kolumn_a, int ilosc_kolumn_b){
    double **macierz_w = utworz_macierz_double(ilosc_wierszy_a, ilosc_kolumn_b);

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
    int **macierz_w = utworz_macierz_int(ilosc_wierszy, ilosc_kolumn);

    for (int i = 0; i < ilosc_wierszy; i++){
        for (int j = 0; j < ilosc_kolumn; j++){
            macierz_w[i][j] = macierz[i][j] * skalar;
        }
    }
    return macierz_w;
}

double **multiplyByScalar(double **macierz, int ilosc_wierszy,int ilosc_kolumn,double skalar){
    double **macierz_w = utworz_macierz_double(ilosc_wierszy, ilosc_kolumn);

    for (int i = 0; i < ilosc_wierszy; i++){
        for (int j = 0; j < ilosc_kolumn; j++){
            macierz_w[i][j] = macierz[i][j] * skalar;
        }
    }
    return macierz_w;
}

int **transpozeMatrix(int **macierz, int ilosc_wierszy, int ilosc_kolumn){
    int **macierz_w = utworz_macierz_int(ilosc_kolumn, ilosc_wierszy);

    for(int i = 0; i < ilosc_wierszy; i++){
        for (int j = 0; j < ilosc_kolumn; j++){
            macierz_w[j][i] = macierz[i][j];
        }
    }
    return macierz_w;
}

double **transpozeMatrix(double **macierz, int ilosc_wierszy, int ilosc_kolumn){
    double **macierz_w = utworz_macierz_double(ilosc_kolumn, ilosc_wierszy);

    for(int i = 0; i < ilosc_wierszy; i++){
        for (int j = 0; j < ilosc_kolumn; j++){
            macierz_w[j][i] = macierz[i][j];
        }
    }
    return macierz_w;
}

int **powerMatrix(int **macierz, int ilosc_wierszy, int ilosc_kolumn, int potega){
    int **macierz_w = utworz_macierz_int(ilosc_wierszy, ilosc_kolumn);
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

double **powerMatrix(double **macierz, int ilosc_wierszy, int ilosc_kolumn, double potega){
    double **macierz_w = utworz_macierz_double(ilosc_wierszy, ilosc_kolumn);
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

    int **macierz_w = utworz_macierz_int(rozmiar_macierzy, rozmiar_macierzy);

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

double **submatrix(double **macierz, int index_wierszy, int index_kolumn, int rozmiar_macierzy){
    int i = 0;
    int j = 0;

    double **macierz_w = utworz_macierz_double(rozmiar_macierzy, rozmiar_macierzy);

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

double determinantMatrix(double **macierz, int ilosc_wierszy, int ilosc_kolumn){
    if (ilosc_wierszy == 1){
        return macierz[0][0];
    }
    else if(ilosc_wierszy == 2){
        return (macierz[0][0] * macierz[1][1])-(macierz[0][1] * macierz[1][0]);
    }
    else{
        int suma = 0;
        int znak = 1;
        double **pod_macierz;

        for(int i = 0; i < ilosc_wierszy; i++){
            pod_macierz = submatrix(macierz, 0, i, ilosc_wierszy);
            suma += znak * macierz[0][i] * determinantMatrix(pod_macierz, ilosc_wierszy - 1, ilosc_wierszy -1);
            znak = -znak;
        }

        return suma;

    }
}

bool matrixIsDiagonal(int **macierz, int ilosc_wierszy, int ilosc_kolumn){
    for(int i = 0; i < ilosc_wierszy; i++){
        for(int j = 0; j < ilosc_kolumn; j++){
            if((i != j) && (macierz[i][j] != 0)){
                return false;
            }
        }
    }
    return true;
}

bool matrixIsDiagonal(double **macierz, int ilosc_wierszy, int ilosc_kolumn){
    for(int i = 0; i < ilosc_wierszy; i++){
        for(int j = 0; j < ilosc_kolumn; j++){
            if((i != j) && (macierz[i][j] != 0)){
                return false;
            }
        }
    }
    return true;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap(double *a, double *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortRow (int *tablica, int liczba_kolumn){
    for(int i = 0; i < liczba_kolumn - 1; i++){
        for(int j = 0; j < liczba_kolumn - 1; j++){
            if(tablica[j] > tablica[j+1])
                swap(tablica[j], tablica[j+1]);
        }
    }
}

void sortRow (double *tablica, int liczba_kolumn){
    for(int i = 0; i < liczba_kolumn - 1; i++){
        for(int j = 0; j < liczba_kolumn - 1; j++){
            if(tablica[j] > tablica[j+1])
                swap(tablica[j], tablica[j+1]);
        }
    }
}

void sortRowsInMatrix(int **macierz, int liczba_wierszy,int liczba_kolumn){
    for(int i = 0; i < liczba_wierszy; i++){
        sortRow(macierz[i], liczba_kolumn);
    }
}

void sortRowsInMatrix(double **macierz, int liczba_wierszy,int liczba_kolumn){
    for(int i = 0; i < liczba_wierszy; i++){
        sortRow(macierz[i], liczba_kolumn);
    }
}


bool sprawdzanie(string komendy){

    string lista_komend[12] = {"addMatrix", "subtractMatrix", "multiplyMatrix", "multiplyByScalar",
                              "transpozeMatrix","powerMatrix", "determinantMatrix", "matrixIsDiagonal",
                              "swap", "sortRow", "sortRowsInMatrix", "help"};

    for (int i = 0; i < 12; i++){
        if(komendy == lista_komend[i])
            return true;
    }
    return false;
}

