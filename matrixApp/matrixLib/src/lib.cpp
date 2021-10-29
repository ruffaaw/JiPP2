#include <iostream>
#include <iomanip>
#include <string>
#include "../include/lib.h"
using namespace std;

//tablica z wszystkimi komendami do help'a
string tab[24] = {"addMatrix", "subtractMatrix", "multiplyMatrix", "multiplyByScalar",
                  "transpozeMatrix", "powerMatrix", "determinantMatrix",
                  "matrixIsDiagonal", "swap", "sortRow", "sortRowsInMatrix",
                  "Dodawanie dwoch macierzy", "Odejmowanie dwoch macierzy",
                  "Mnozenie dwoch macierzy", "Mnozenie przez skalar",
                  "Transponowanie macierzy", "Potegowanie macierzy", "Wyznacznik macierzy",
                  "Sprawdzanie czy macierz jest diagonalna", "Zamiana dwoch wartosci miejscami",
                  "Sortowanie tablicy", "Sortowanie wszystkich wierszy w macierzy",
                  "help", "Pomoc"};

//funkcja pomocnicza help do ktorej uzylem wczesniej stworzonej tablicy stringow
void help(){
    cout << "Kalkulator osluguje rozne rodzaje operacji na macierzach.\n"
    << "Uzytkownik sam wybiera rozmiary oraz wartosci macierzy.\n"
    << "Ponizej znajduje sie lista funkcji oraz komendy, ktorych nalezy uzyc aby je wywolac:\n\n";

    cout << tab[22] << right << setw(20) << "-" << right << setw(10) <<  tab[23] << endl;
    cout << tab[0] << right << setw(15) << "-" << right << setw(29) <<  tab[11] << endl;
    cout << tab[1] << right << setw(10) << "-" << right << setw(31) << tab[12] << endl;
    cout << tab[2] << right << setw(10) << "-" << right << setw(28) << tab[13] << endl;
    cout << tab[3] << right << setw(8) << "-" << right << setw(26) << tab[14] << endl;
    cout << tab[4] << right << setw(9) << "-" << right << setw(28) << tab[15] << endl;
    cout << tab[5] << right << setw(13) << "-" << right << setw(25) << tab[16] << endl;
    cout << tab[6] << right << setw(7) << "-" << right << setw(24) << tab[17] << endl;
    cout << tab[7] << right << setw(8) << "-" << right << setw(44) << tab[18] << endl;
    cout << tab[8] << right << setw(20) << "-" << right << setw(37) << tab[19] << endl;
    cout << tab[9] << right << setw(17) << "-" << right << setw(23) << tab[20] << endl;
    cout << tab[10] << right << setw(8) << "-" << right << setw(45) << tab[21] << endl;
    cout << "Nastepnie uzytkownik wybiera typ zmiennych wartosci macierzy" << endl;
    cout << "[0]" << right << setw(3) << "-" << right << setw(24) <<"liczby calkowite (int)" << endl;
    cout << "[1]" << right << setw(3) << "-" << right << setw(35) <<"liczby zmiennoprzecinkowe(double)" << endl;

}
//funkcja do dynamicznego alokowania macierzy o wartosciach typu int
int **utworz_macierz_int(int ilosc_wierszy, int ilosc_kolumn){
    int **macierz;
    macierz = new int * [ilosc_wierszy];

    for (int i = 0; i < ilosc_wierszy; i++){
        macierz[i] = new int [ilosc_kolumn];
    }

    return macierz;
}

//funkcja do dynamicznego alokowania macierzy o wartosciach typu double
double **utworz_macierz_double(int ilosc_wierszy, int ilosc_kolumn){
    double **macierz;
    macierz = new double * [ilosc_wierszy];

    for (int i = 0; i < ilosc_wierszy; i++){
        macierz[i] = new double [ilosc_kolumn];
    }

    return macierz;
}

//wypelnianie macierzy o wartosciach typu int
bool wypelnianie_macierzy(int **macierz, int ilosc_wierszy, int ilosc_kolumn){
    for (int i = 0; i < ilosc_wierszy; i++){
        for(int j = 0; j < ilosc_kolumn; j++){
            cout << "[" << i << "]" << "[" << j << "]-";
            if(!(cin >> macierz[i][j])){
                //zabezpieczenie przed wprowadzeniem tekstu zamiast liczby
                cout << "Wprowadzono nieprawidlowe znaki\n" <<endl;
                return false;
            }
        }
    }
    return true;
}

//wypelnianie macierzy o wartosciach typu double
bool wypelnianie_macierzy(double **macierz, int ilosc_wierszy, int ilosc_kolumn){
    for (int i = 0; i < ilosc_wierszy; i++){
        for(int j = 0; j < ilosc_kolumn; j++){
            cout << "[" << i << "]" << "[" << j << "]-";
            if(!(cin >> macierz[i][j])){
                //zabezpieczenie przed wprowadzeniem tekstu zamiast liczby
                cout << "Wprowadzono nieprawidlowe znaki\n" <<endl;
                return false;
            }
        }
    }
    return true;
}

//wyswietlanie macierzy o wartosciach typu int
void wyswietl(int **macierz, int ilosc_wierszy, int ilosc_kolumn){
    for (int i = 0; i < ilosc_wierszy; i++){
        for(int j = 0; j < ilosc_kolumn; j++){
            cout << setw(5) << macierz[i][j];
        }
        cout << endl;
    }
}

//wyswietlanie macierzy o wartosciach typu double
void wyswietl(double **macierz, int ilosc_wierszy, int ilosc_kolumn){
    for (int i = 0; i < ilosc_wierszy; i++){
        for(int j = 0; j < ilosc_kolumn; j++){
            cout << setw(5) << macierz[i][j];
        }
        cout << endl;
    }
}

//funkcja dodawania macierzy o wartosciach typu int
int **addMatrix(int **macierz_a, int **macierz_b, int ilosc_wierszy, int ilosc_kolumn){
    //tworzy macierz wynikowa
    int **macierz_w = utworz_macierz_int(ilosc_wierszy, ilosc_kolumn);

    /*dokonywanie dodawania wartosci za pomoca dwoch petli for oraz zapisywanie wynikow w
    wczesniej stworzonej macierzy wynikowej*/
    for (int i = 0; i < ilosc_wierszy; i++){
        for(int j = 0; j < ilosc_kolumn; j++){
            macierz_w[i][j] = macierz_a[i][j] + macierz_b[i][j];
        }
    }
    //zwracanie macierzy wynikowej
    return macierz_w;
}

//funkcja dodawania macierzy o wartosciach typu double
double **addMatrix(double **macierz_a, double **macierz_b, int ilosc_wierszy, int ilosc_kolumn){
    //tworzy macierz wynikowa
    double **macierz_w = utworz_macierz_double(ilosc_wierszy, ilosc_kolumn);

    /*dokonywanie dodawania wartosci za pomoca dwoch petli for oraz zapisywanie wynikow w
    wczesniej stworzonej macierzy wynikowej*/
    for (int i = 0; i < ilosc_wierszy; i++){
        for(int j = 0; j < ilosc_kolumn; j++){
            macierz_w[i][j] = macierz_a[i][j] + macierz_b[i][j];
        }
    }
    //zwracanie macierzy wynikowej
    return macierz_w;
}

//funkcja odejmowania macierzy o wartosciach typu int
int **subtractMatrix(int **macierz_a, int **macierz_b, int ilosc_wierszy, int ilosc_kolumn) {

    int **macierz_w = utworz_macierz_int(ilosc_wierszy, ilosc_kolumn);

    /*dokonywanie odejmowania wartosci za pomoca dwoch petli for oraz zapisywanie wynikow w
    wczesniej stworzonej macierzy wynikowej*/
    for (int i = 0; i < ilosc_wierszy; i++) {
        for (int j = 0; j < ilosc_kolumn; j++) {
            macierz_w[i][j] = macierz_a[i][j] - macierz_b[i][j];
        }
    }
    return macierz_w;
}

//funkcja odejmowania macierzy o wartosciach typu double
double **subtractMatrix(double **macierz_a, double **macierz_b, int ilosc_wierszy, int ilosc_kolumn){

    double **macierz_w = utworz_macierz_double(ilosc_wierszy, ilosc_kolumn);

    /*dokonywanie odejmowania wartosci za pomoca dwoch petli for oraz zapisywanie wynikow w
    wczesniej stworzonej macierzy wynikowej*/
    for (int i = 0; i < ilosc_wierszy; i++) {
        for (int j = 0; j < ilosc_kolumn; j++) {
            macierz_w[i][j] = macierz_a[i][j] - macierz_b[i][j];
        }
    }
    return macierz_w;
}

//funkcja mnozenia macierzy o wartosciach typu int
int **multiplyMatrix(int **macierz_a, int **macierz_b, int ilosc_wierszy_a, int ilosc_kolumn_a, int ilosc_kolumn_b){
    //tworzenie macierzy wynikowej o wymiarach ilosci wierszy macierzy A x ilosci kolumn macierzy B
    int **macierz_w = utworz_macierz_int(ilosc_wierszy_a, ilosc_kolumn_b);

    for (int i = 0; i < ilosc_wierszy_a; i++){
        for(int j = 0; j < ilosc_kolumn_b; j++){
            /*tworzenie zmiennej do ktorej beda zapisywanie wyniki sumy iloczynow,
             za kazdym razem po skonczeniu nastepnej petli ta wartosc jest zerowana*/
            int suma_iloczynow = 0;
            for (int k = 0; k < ilosc_kolumn_a; k++)
                suma_iloczynow += (macierz_a[i][k] * macierz_b[k][j]);
            //wpisywanie danej wyniku sumy iloczynow
            macierz_w[i][j] = suma_iloczynow;
        }
    }
    return macierz_w;
}

//funkcja mnozenia macierzy o wartosciach typu double
double **multiplyMatrix(double **macierz_a, double **macierz_b, int ilosc_wierszy_a, int ilosc_kolumn_a, int ilosc_kolumn_b){
    double **macierz_w = utworz_macierz_double(ilosc_wierszy_a, ilosc_kolumn_b);

    for (int i = 0; i < ilosc_wierszy_a; i++){
        for(int j = 0; j < ilosc_kolumn_b; j++){
            double suma_iloczynow = 0;
            for (int k = 0; k < ilosc_kolumn_a; k++)
                suma_iloczynow += (macierz_a[i][k] * macierz_b[k][j]);
            macierz_w[i][j] = suma_iloczynow;
        }
    }
    return macierz_w;
}

//funkcja mnozenia macierzy o wartosciach typu int przez skalar
int **multiplyByScalar(int **macierz, int ilosc_wierszy,int ilosc_kolumn,int skalar){
    int **macierz_w = utworz_macierz_int(ilosc_wierszy, ilosc_kolumn);

    for (int i = 0; i < ilosc_wierszy; i++){
        for (int j = 0; j < ilosc_kolumn; j++){
            macierz_w[i][j] = macierz[i][j] * skalar;
        }
    }
    return macierz_w;
}

//funkcja mnozenia macierzy o wartosciach typu double przez skalar
double **multiplyByScalar(double **macierz, int ilosc_wierszy,int ilosc_kolumn,double skalar){
    double **macierz_w = utworz_macierz_double(ilosc_wierszy, ilosc_kolumn);

    for (int i = 0; i < ilosc_wierszy; i++){
        for (int j = 0; j < ilosc_kolumn; j++){
            macierz_w[i][j] = macierz[i][j] * skalar;
        }
    }
    return macierz_w;
}

//funkcja transponowania macierzy o wartosciach typu int
int **transpozeMatrix(int **macierz, int ilosc_wierszy, int ilosc_kolumn){
    //tworzenie macierzy wynikowej o wymiarach ilosci kolumn x ilosci wierszy macierzy A
    int **macierz_w = utworz_macierz_int(ilosc_kolumn, ilosc_wierszy);

    //transponowanie macierzy, zapisywanie
    for(int i = 0; i < ilosc_wierszy; i++){
        for (int j = 0; j < ilosc_kolumn; j++){
            macierz_w[j][i] = macierz[i][j];
        }
    }
    return macierz_w;
}

//funkcja transponowania macierzy o wartosciach typu double
double **transpozeMatrix(double **macierz, int ilosc_wierszy, int ilosc_kolumn){
    double **macierz_w = utworz_macierz_double(ilosc_kolumn, ilosc_wierszy);

    for(int i = 0; i < ilosc_wierszy; i++){
        for (int j = 0; j < ilosc_kolumn; j++){
            macierz_w[j][i] = macierz[i][j];
        }
    }
    return macierz_w;
}

//funkcja potegowania macierzy o wartosciach typu int
int **powerMatrix(int **macierz, int ilosc_wierszy, int ilosc_kolumn, int potega){
    int **macierz_w = utworz_macierz_int(ilosc_wierszy, ilosc_kolumn);
    //przypadek w ktorym potega jest rowna 0, wtedy zwracana jest macierz jednostkowa
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

    /*przypadek w ktorym potega jest rowna 1, wtedy zwracana jest macierz o takich
     samych wartosciach*/
    else if (potega == 1){
        for (int i = 0; i < ilosc_wierszy; i++){
            for(int j = 0; j < ilosc_kolumn; j++){
                macierz_w[i][j] = macierz[i][j];
            }
        }
        return macierz_w;
    }

    //mnozenie macierzy za pomoca rekurencyjnego uzycia funkcji powerMatrix
    else {
      return multiplyMatrix(macierz, powerMatrix(macierz, ilosc_wierszy, ilosc_kolumn, potega - 1), ilosc_wierszy, ilosc_kolumn, ilosc_kolumn);
    }
}

//funkcja potegowania macierzy o wartosciach typu double
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

//funkcja pomocnicza do obliczania wyznacznika tworzaca podmacierz
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

//funkcja obliczajaca wyznacznik macierzy o wartosciach typu int
int determinantMatrix(int **macierz, int ilosc_wierszy, int ilosc_kolumn){
    //przypadek macierzy o wymiarach 1x1
    if (ilosc_wierszy == 1){
        return macierz[0][0];
    }
    //przypadek macierzy o wymiarach 2x2
    else if(ilosc_wierszy == 2){
        return (macierz[0][0] * macierz[1][1])-(macierz[0][1] * macierz[1][0]);
    }
    else{
        int suma = 0;
        int znak = 1;
        int **pod_macierz;

        for(int i = 0; i < ilosc_wierszy; i++){
            //tworzymy podmacierz ktora jest pomniejszona o konkretny wiersz i konkretna kolumne
            pod_macierz = submatrix(macierz, 0, i, ilosc_wierszy);
            //obliczamy ze wzoru
            suma += znak * macierz[0][i] * determinantMatrix(pod_macierz, ilosc_wierszy - 1, ilosc_wierszy -1);
            //zmiana znaku
            znak = -znak;
        }
        return suma;
    }
}

//funkcja pomocnicza do obliczania wyznacznika tworzaca podmacierz
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

//funkcja obliczajaca wyznacznik macierzy o wartosciach typu double
double determinantMatrix(double **macierz, int ilosc_wierszy, int ilosc_kolumn){
    if (ilosc_wierszy == 1){
        return macierz[0][0];
    }
    else if(ilosc_wierszy == 2){
        return (macierz[0][0] * macierz[1][1])-(macierz[0][1] * macierz[1][0]);
    }
    else{
        double suma = 0;
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

//funkcja sprawdzajaca czy dana macierz o wartosciach typu int jest diagonalna
bool matrixIsDiagonal(int **macierz, int ilosc_wierszy, int ilosc_kolumn){
    for(int i = 0; i < ilosc_wierszy; i++){
        for(int j = 0; j < ilosc_kolumn; j++){
            //sprawdzanie czy na przekatnej znajduja sie liczby, a pozostale wartosci macierzy sa rowne 0
            if((i != j) && (macierz[i][j] != 0)){
                return false;
            }
        }
    }
    return true;
}

//funkcja sprawdzajaca czy dana macierz o wartosciach double int jest diagonalna
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

//funkcja zamieniaja dwie wartosci typu int miejscami
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//funkcja zamieniaja dwie wartosci typu double miejscami
void swap(double *a, double *b){
    double temp = *a;
    *a = *b;
    *b = temp;
}

//funkcja sortujaca tablice typu int za pomoca sortowania bombelkowego
void sortRow (int *tablica, int liczba_kolumn){
    for(int i = 0; i < liczba_kolumn - 1; i++){
        for(int j = 0; j < liczba_kolumn - 1; j++){
            if(tablica[j] > tablica[j+1])
                swap(tablica[j], tablica[j+1]);
        }
    }
}

//funkcja sortujaca tablice typu double za pomoca sortowania bombelkowego
void sortRow (double *tablica, int liczba_kolumn){
    for(int i = 0; i < liczba_kolumn - 1; i++){
        for(int j = 0; j < liczba_kolumn - 1; j++){
            if(tablica[j] > tablica[j+1])
                swap(tablica[j], tablica[j+1]);
        }
    }
}

//funkcja sortujaca wiersze macierzy o wartosciach typu int, do tego uzyto wczesniej napisanej funkcji sortRow
void sortRowsInMatrix(int **macierz, int liczba_wierszy,int liczba_kolumn){
    for(int i = 0; i < liczba_wierszy; i++){
        sortRow(macierz[i], liczba_kolumn);
    }
}

//funkcja sortujaca wiersze macierzy o wartosciach typu double, do tego uzyto wczesniej napisanej funkcji sortRow
void sortRowsInMatrix(double **macierz, int liczba_wierszy,int liczba_kolumn){
    for(int i = 0; i < liczba_wierszy; i++){
        sortRow(macierz[i], liczba_kolumn);
    }
}

//funkcja sprawdzajaca czy komenda ktorej uzyl uzytkownik jest prawidlowa
bool sprawdzanie(string komendy){

    string lista_komend[12] = {"addMatrix", "subtractMatrix", "multiplyMatrix", "multiplyByScalar",
                              "transpozeMatrix","powerMatrix", "determinantMatrix", "matrixIsDiagonal",
                              "swap", "sortRow", "sortRowsInMatrix", "help"};

    for (int i = 0; i < 12; i++){
        if(komendy == lista_komend[i])
            return false;
    }
    return true;
}