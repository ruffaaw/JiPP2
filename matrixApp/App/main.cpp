#include <iostream>
#include "../matrixLib/include/lib.h"
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]){
    string wybor = argv[1];
    int **macierz_a, **macierz_b, **macierz_w, ilosc_wierszy, ilosc_kolumn;
    cout << "Prosze podac ilosc wierszy macierzy: ";
    cin >> ilosc_wierszy;
    cout << "Prosze podac ilosc kolumn macierzy: ";
    cin >> ilosc_kolumn;

    //tablica wskaznikow
    macierz_a = new int * [ilosc_wierszy];
    macierz_b = new int * [ilosc_wierszy];

    //tablica wierszy
    for(int i = 0; i < ilosc_wierszy; i++){
        macierz_a[i] = new int [ilosc_kolumn];
        macierz_b[i] = new int [ilosc_kolumn];
    }

    //wypelniamy macierz a
    for(int i = 0; i < ilosc_wierszy; i++){
        for(int j = 0; j < ilosc_kolumn; j++){
            cin >> macierz_a[i][j];
        }
    }

    //wypelniamy macierz b
    for(int i = 0; i < ilosc_wierszy; i++){
        for(int j = 0; j < ilosc_kolumn; j++){
            cin >> macierz_b[i][j];
        }
    }

    //wyswietlamy macierze
    cout << "ilosc wierszy = " << ilosc_wierszy << endl
         << "ilosc kolumn = " << ilosc_kolumn << endl
         << "Macierz A:" << endl;

/*    for( int i = 0; i < ilosc_wierszy; i++ ){
        for( int j = 0; j < ilosc_kolumn; j++ ) {
            cout << setw(5) << macierz_a[i][j];
        }
        cout << endl;
    }*/
    wypisz(macierz_a, ilosc_wierszy, ilosc_kolumn);

    cout << endl << "Macierz B:" << endl;

/*    for( int i = 0; i < ilosc_wierszy; i++ ){
        for( int j = 0; j < ilosc_kolumn; j++ ) {
            cout << setw(5) << macierz_b[i][j];
        }
        cout << endl;
    }*/
    wypisz(macierz_b, ilosc_wierszy, ilosc_kolumn);

    //wykorzystywanie biblioteki dokonujacej obliczen na macierzach
    if (wybor == "addMatrix") {
        macierz_w = addMatrix(macierz_a, macierz_b, ilosc_wierszy, ilosc_kolumn);
        cout << "wynik dodawania: " << endl;
        wypisz(macierz_w, ilosc_wierszy, ilosc_kolumn);
    }

    if (wybor == "subtractMatrix"){
        macierz_w = subtractMatrix(macierz_a, macierz_b, ilosc_wierszy, ilosc_kolumn);
        cout << "wynik odejmowania" << endl;
        wypisz(macierz_w, ilosc_wierszy, ilosc_kolumn);
    }


    //zwalniamy pamiec
    for (int i = 0; i < ilosc_wierszy; i++){
        delete[] macierz_a[i];
        delete[] macierz_b[i];
        delete[] macierz_w[i];
    }
    delete[] macierz_a;
    delete[] macierz_b;
    delete[] macierz_w;

    return 0;
}

