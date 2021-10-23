#include <iostream>
#include "../matrixLib/include/lib.h"
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]) {
    string wybor = argv[1];
    int **macierz_a, **macierz_b, **macierz_w, ilosc_wierszy, ilosc_kolumn;

    if (wybor == "addMatrix" || wybor == "subtractMatrix"){
        cout << "Prosze podac ilosc wierszy macierzy: ";
        cin >> ilosc_wierszy;
        cout << "Prosze podac ilosc kolumn macierzy: ";
        cin >> ilosc_kolumn;

        //tworzenie macierzy
        macierz_a = utworz_macierz(ilosc_wierszy, ilosc_kolumn);
        macierz_b = utworz_macierz(ilosc_wierszy, ilosc_kolumn);

        //wypelnianie macierzy
        wypelnianie_macierzy(macierz_a, ilosc_wierszy, ilosc_kolumn);
        wypelnianie_macierzy(macierz_b, ilosc_wierszy, ilosc_kolumn);

        //wyswietlamy macierze
        cout << "ilosc wierszy = " << ilosc_wierszy << endl
             << "ilosc kolumn = " << ilosc_kolumn << endl
             << "Macierz A:" << endl;

        wyswietl(macierz_a, ilosc_wierszy, ilosc_kolumn);

        cout << endl << "Macierz B:" << endl;

        wyswietl(macierz_b, ilosc_wierszy, ilosc_kolumn);

        //wykorzystywanie biblioteki dokonujacej obliczen na macierzach
        if (wybor == "addMatrix") {
            macierz_w = addMatrix(macierz_a, macierz_b, ilosc_wierszy, ilosc_kolumn);
            cout << "wynik dodawania: " << endl;
            wyswietl(macierz_w, ilosc_wierszy, ilosc_kolumn);
        }

        if (wybor == "subtractMatrix") {
            macierz_w = subtractMatrix(macierz_a, macierz_b, ilosc_wierszy, ilosc_kolumn);
            cout << "wynik odejmowania" << endl;
            wyswietl(macierz_w, ilosc_wierszy, ilosc_kolumn);
        }

        for (int i = 0; i < ilosc_wierszy; i++) {
            delete[] macierz_a[i];
            delete[] macierz_b[i];
            delete[] macierz_w[i];
        }
        delete[] macierz_a;
        delete[] macierz_b;
        delete[] macierz_w;
    }

    if (wybor == "multiplyMatrix"){
        int ilosc_wierszy_a, ilosc_kolumn_a, ilosc_kolumn_b;
        cout << "Prosze podac ilosc wierszy macierzy A: ";
        cin >> ilosc_wierszy_a;
        cout << "Prosze podac ilosc kolumn macierzy A: ";
        cin >> ilosc_kolumn_a;
        cout << "Prosze podac ilosc kolumn macierzy B: ";
        cin >> ilosc_kolumn_b;

        macierz_a = utworz_macierz(ilosc_wierszy_a, ilosc_kolumn_a);
        macierz_b = utworz_macierz(ilosc_kolumn_a, ilosc_kolumn_b);

        wypelnianie_macierzy(macierz_a, ilosc_wierszy_a, ilosc_kolumn_a);
        wypelnianie_macierzy(macierz_b, ilosc_kolumn_a, ilosc_kolumn_b);

        cout << "Macierz A:" << endl;
        wyswietl(macierz_a, ilosc_wierszy_a, ilosc_kolumn_a);
        cout << "Macierz B:" << endl;
        wyswietl(macierz_b, ilosc_kolumn_a, ilosc_kolumn_b);

        macierz_w = multiplyMatrix(macierz_a, macierz_b, ilosc_wierszy_a, ilosc_kolumn_a, ilosc_kolumn_b);
        cout << "Wynik mnozenia: " << endl;
        wyswietl(macierz_w, ilosc_wierszy_a, ilosc_kolumn_b);

        for (int i = 0; i < ilosc_wierszy_a; i++) {
            delete[] macierz_a[i];
            delete[] macierz_b[i];
            delete[] macierz_w[i];
        }
        delete[] macierz_a;
        delete[] macierz_b;
        delete[] macierz_w;

    }

    if (wybor == "multiplyByScalar"){
        int skalar;
        cout << "Prosze podac ilosc wierszy macierzy: ";
        cin >> ilosc_wierszy;
        cout << "Prosze podac ilosc kolumn macierzy: ";
        cin >> ilosc_kolumn;
        cout << "Prosze podac skalar: ";
        cin >> skalar;

        macierz_a = utworz_macierz(ilosc_wierszy, ilosc_kolumn);

        wypelnianie_macierzy(macierz_a, ilosc_wierszy, ilosc_kolumn);

        cout << "ilosc wierszy = " << ilosc_wierszy << endl
             << "ilosc kolumn = " << ilosc_kolumn << endl
             << "Macierz A:" << endl;

        wyswietl(macierz_a, ilosc_wierszy, ilosc_kolumn);

        macierz_w = multiplyByScalar(macierz_a, ilosc_wierszy, ilosc_kolumn, skalar);
        cout << "Wynik mnozenia przez skalar:" << endl;
        wyswietl(macierz_w, ilosc_wierszy, ilosc_kolumn);

        for (int i = 0; i < ilosc_wierszy; i++) {
            delete[] macierz_a[i];
            delete[] macierz_w[i];
        }
        delete[] macierz_a;
        delete[] macierz_w;

    }

    if (wybor == "transpozeMatrix"){
        cout << "Prosze podac ilosc wierszy macierzy: ";
        cin >> ilosc_wierszy;
        cout << "Prosze podac ilosc kolumn macierzy: ";
        cin >> ilosc_kolumn;

        macierz_a = utworz_macierz(ilosc_wierszy, ilosc_kolumn);

        wypelnianie_macierzy(macierz_a, ilosc_wierszy, ilosc_kolumn);

        cout << "ilosc wierszy = " << ilosc_wierszy << endl
             << "ilosc kolumn = " << ilosc_kolumn << endl
             << "Macierz A:" << endl;

        wyswietl(macierz_a, ilosc_wierszy, ilosc_kolumn);


    }



/*        //zwalniamy pamiec
        for (int i = 0; i < ilosc_wierszy; i++) {
            delete[] macierz_a[i];
            delete[] macierz_b[i];
            delete[] macierz_w[i];
        }
        delete[] macierz_a;
        delete[] macierz_b;
        delete[] macierz_w;

        return 0;*/

}
