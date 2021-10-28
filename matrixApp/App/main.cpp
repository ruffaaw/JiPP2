#include <iostream>
#include "../matrixLib/include/lib.h"
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]) {
    string wybor = argv[1];

    if (wybor == "help") {
        help();
    } else if (sprawdzanie(wybor)) {
        //sprawdzanie czy komenda wprowadzona przez uzytkownika jest obslugiwana
        int typ_zmiennych;
        cout << "Prosze wybrac typ zmiennej:\n[0]\t-\tliczby calkowite(int)\n"
             << "[1]\t-\tliczby zmiennoprzecinkowe(double)" << endl;
        if (!(cin >> typ_zmiennych)) {
            //zabezpieczenie przed wprowadzeniem tekstu zamiast liczby
            cout << "Wprowadzono nieprawidlowe znaki\n" << endl;
            help();
            return 0;
        }

        if (typ_zmiennych == 0) {
            //operacje na int'ach
            if (wybor == "addMatrix" || wybor == "subtractMatrix") {
                int **macierz_a, **macierz_b, **macierz_w, ilosc_wierszy, ilosc_kolumn;
                cout << "Prosze podac ilosc wierszy macierzy: ";
                if (!(cin >> ilosc_wierszy)) {
                    //zabezpieczenie przed wprowadzeniem tekstu zamiast liczby
                    cout << "Wprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                cout << "Prosze podac ilosc kolumn macierzy: ";
                if (!(cin >> ilosc_kolumn)) {
                    //zabezpieczenie przed wprowadzeniem tekstu zamiast liczby
                    cout << "Wprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }

                //tworzenie macierzy
                macierz_a = utworz_macierz_int(ilosc_wierszy, ilosc_kolumn);
                macierz_b = utworz_macierz_int(ilosc_wierszy, ilosc_kolumn);

                //wypelnianie macierzy, zabezpieczenie przed wprowadzeniem tekstu zamiast liczby
                if (!wypelnianie_macierzy(macierz_a, ilosc_wierszy, ilosc_kolumn)) {
                    //zakonczenie i delokacja pamieci w razie podania tekstu zamiast liczby
                    for (int i = 0; i < ilosc_wierszy; i++) {
                        delete[] macierz_a[i];
                        delete[] macierz_b[i];
                    }
                    delete[] macierz_a;
                    delete[] macierz_b;
                    return 0;
                }
                if (!wypelnianie_macierzy(macierz_b, ilosc_wierszy, ilosc_kolumn)) {
                    //zakonczenie i delokacja pamieci w razie podania tekstu zamiast liczby
                    for (int i = 0; i < ilosc_wierszy; i++) {
                        delete[] macierz_a[i];
                        delete[] macierz_b[i];
                    }
                    delete[] macierz_a;
                    delete[] macierz_b;
                    return 0;
                }
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
                } else if (wybor == "subtractMatrix") {
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
            } else if (wybor == "multiplyMatrix") {
                int **macierz_a, **macierz_b, **macierz_w, ilosc_wierszy, ilosc_kolumn;
                int ilosc_wierszy_a, ilosc_kolumn_a, ilosc_kolumn_b;
                cout << "Prosze podac ilosc wierszy macierzy A: ";
                if (!(cin >> ilosc_wierszy_a)) {
                    //zabezpieczenie przed wprowadzeniem tekstu zamiast liczby
                    cout << "Wprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                cout << "Prosze podac ilosc kolumn macierzy A: ";
                if (!(cin >> ilosc_kolumn_a)) {
                    cout << "Wprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                cout << "Prosze podac ilosc kolumn macierzy B: ";
                if (!(cin >> ilosc_kolumn_b)) {
                    cout << "Wprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }

                macierz_a = utworz_macierz_int(ilosc_wierszy_a, ilosc_kolumn_a);
                macierz_b = utworz_macierz_int(ilosc_kolumn_a, ilosc_kolumn_b);

                if (!wypelnianie_macierzy(macierz_a, ilosc_wierszy_a, ilosc_kolumn_a)) {
                    for (int i = 0; i < ilosc_wierszy_a; i++) {
                        delete[] macierz_a[i];
                        delete[] macierz_b[i];
                    }
                    delete[] macierz_a;
                    delete[] macierz_b;
                    return 0;
                }
                if (!wypelnianie_macierzy(macierz_b, ilosc_kolumn_a, ilosc_kolumn_b)) {
                    for (int i = 0; i < ilosc_wierszy_a; i++) {
                        delete[] macierz_a[i];
                        delete[] macierz_b[i];
                    }
                    delete[] macierz_a;
                    delete[] macierz_b;
                    return 0;
                }

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

            } else if (wybor == "multiplyByScalar") {
                int **macierz_a, **macierz_w, ilosc_wierszy, ilosc_kolumn, skalar;
                cout << "Prosze podac ilosc wierszy macierzy: ";
                if (!(cin >> ilosc_wierszy)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                cout << "Prosze podac ilosc kolumn macierzy: ";
                if (!(cin >> ilosc_kolumn)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                cout << "Prosze podac skalar: ";
                if (!(cin >> skalar)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }

                macierz_a = utworz_macierz_int(ilosc_wierszy, ilosc_kolumn);

                if (!wypelnianie_macierzy(macierz_a, ilosc_wierszy, ilosc_kolumn)) {
                    for (int i = 0; i < ilosc_wierszy; i++) {
                        delete[] macierz_a[i];
                    }
                    delete[] macierz_a;
                    return 0;
                }

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

            } else if (wybor == "transpozeMatrix") {
                int **macierz_a, **macierz_w, ilosc_wierszy, ilosc_kolumn;
                cout << "Prosze podac ilosc wierszy macierzy: ";
                if (!(cin >> ilosc_wierszy)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                cout << "Prosze podac ilosc kolumn macierzy: ";
                if (!(cin >> ilosc_kolumn)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }

                macierz_a = utworz_macierz_int(ilosc_wierszy, ilosc_kolumn);

                if (!wypelnianie_macierzy(macierz_a, ilosc_wierszy, ilosc_kolumn)) {
                    for (int i = 0; i < ilosc_wierszy; i++) {
                        delete[] macierz_a[i];
                    }
                    delete[] macierz_a;
                    return 0;
                }

                cout << "ilosc wierszy = " << ilosc_wierszy << endl
                     << "ilosc kolumn = " << ilosc_kolumn << endl
                     << "Macierz A:" << endl;

                wyswietl(macierz_a, ilosc_wierszy, ilosc_kolumn);

                macierz_w = transpozeMatrix(macierz_a, ilosc_wierszy, ilosc_kolumn);
                cout << "Wynik transponowania macierzy:" << endl;
                wyswietl(macierz_w, ilosc_kolumn, ilosc_wierszy);

                for (int i = 0; i < ilosc_wierszy; i++) {
                    delete[] macierz_a[i];
                }
                for (int i = 0; i < ilosc_kolumn; i++) {
                    delete[] macierz_w[i];
                }
                delete[] macierz_a;
                delete[] macierz_w;
            } else if (wybor == "powerMatrix") {
                int **macierz_a, **macierz_w, ilosc_wierszy, ilosc_kolumn, potega;
                cout << "Prosze podac ilosc wierszy macierzy: ";
                if (!(cin >> ilosc_wierszy)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                cout << "Prosze podac ilosc kolumn macierzy: ";
                if (!(cin >> ilosc_kolumn)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                cout << "Prosze podac stopien potegi: ";
                if (!(cin >> potega)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }

                macierz_a = utworz_macierz_int(ilosc_wierszy, ilosc_kolumn);

                if (!wypelnianie_macierzy(macierz_a, ilosc_wierszy, ilosc_kolumn)) {
                    for (int i = 0; i < ilosc_wierszy; i++) {
                        delete[] macierz_a[i];
                    }
                    delete[] macierz_a;
                    return 0;
                }

                cout << "ilosc wierszy = " << ilosc_wierszy << endl
                     << "ilosc kolumn = " << ilosc_kolumn << endl
                     << "Macierz A:" << endl;

                wyswietl(macierz_a, ilosc_wierszy, ilosc_kolumn);

                macierz_w = powerMatrix(macierz_a, ilosc_wierszy, ilosc_kolumn, potega);
                cout << "Wynik potegowania macierzy:" << endl;
                wyswietl(macierz_w, ilosc_wierszy, ilosc_kolumn);

                for (int i = 0; i < ilosc_wierszy; i++) {
                    delete[] macierz_a[i];
                    delete[] macierz_w[i];
                }
                delete[] macierz_a;
                delete[] macierz_w;
            } else if (wybor == "determinantMatrix") {
                int **macierz_a, ilosc_wierszy, ilosc_kolumn, wyznacznik;
                cout << "Prosze podac ilosc wierszy macierzy: ";
                if (!(cin >> ilosc_wierszy)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                cout << "Prosze podac ilosc kolumn macierzy: ";
                if (!(cin >> ilosc_kolumn)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }

                macierz_a = utworz_macierz_int(ilosc_wierszy, ilosc_kolumn);
                if (!wypelnianie_macierzy(macierz_a, ilosc_wierszy, ilosc_kolumn)) {
                    for (int i = 0; i < ilosc_wierszy; i++) {
                        delete[] macierz_a[i];
                    }
                    delete[] macierz_a;
                    return 0;
                }

                cout << "ilosc wierszy = " << ilosc_wierszy << endl
                     << "ilosc kolumn = " << ilosc_kolumn << endl
                     << "Macierz A:" << endl;

                wyswietl(macierz_a, ilosc_wierszy, ilosc_kolumn);
                wyznacznik = determinantMatrix(macierz_a, ilosc_wierszy, ilosc_kolumn);
                cout << "Wyznacznik jest rowny: " << wyznacznik << endl;

                for (int i = 0; i < ilosc_wierszy; i++) {
                    delete[] macierz_a[i];
                }
                delete[] macierz_a;
            } else if (wybor == "matrixIsDiagonal") {
                bool wynik;
                int **macierz_a, ilosc_wierszy, ilosc_kolumn;

                cout << "Prosze podac ilosc wierszy macierzy: ";
                if (!(cin >> ilosc_wierszy)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                cout << "Prosze podac ilosc kolumn macierzy: ";
                if (!(cin >> ilosc_kolumn)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }

                macierz_a = utworz_macierz_int(ilosc_wierszy, ilosc_kolumn);
                if (!wypelnianie_macierzy(macierz_a, ilosc_wierszy, ilosc_kolumn)) {
                    for (int i = 0; i < ilosc_wierszy; i++) {
                        delete[] macierz_a[i];
                    }
                    delete[] macierz_a;
                    return 0;
                }

                cout << "ilosc wierszy = " << ilosc_wierszy << endl
                     << "ilosc kolumn = " << ilosc_kolumn << endl
                     << "Macierz A:" << endl;

                wyswietl(macierz_a, ilosc_wierszy, ilosc_kolumn);

                wynik = matrixIsDiagonal(macierz_a, ilosc_wierszy, ilosc_kolumn);

                if (wynik) {
                    cout << "Podana macierz jest diagonalna" << endl;
                } else {
                    cout << "Podana macierz nie jest diagonalna" << endl;
                }

                for (int i = 0; i < ilosc_wierszy; i++) {
                    delete[] macierz_a[i];
                }
                delete[] macierz_a;
            } else if (wybor == "swap") {
                int a, b;
                cout << "Podaj wartosc a: ";
                if (!(cin >> a)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                cout << "Podaj wartosc b: ";
                if (!(cin >> b)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }

                cout << "a = " << a << " b = " << b << endl;
                swap(a, b);
                cout << "a = " << a << " b = " << b << endl;
            } else if (wybor == "sortRow") {
                int liczba_kolumn;
                cout << "Prosze podac rozmiar tablicy: ";
                if (!(cin >> liczba_kolumn)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                int *tablica = new int[liczba_kolumn];
                cout << "Prosze podac liczby do wczytania: " << endl;

                for (int i = 0; i < liczba_kolumn; i++) {
                    if (!(cin >> tablica[i])) {
                        cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                        delete[] tablica;
                        return 0;
                    }
                }

                cout << "Podane liczby: ";
                for (int i = 0; i < liczba_kolumn; i++) {
                    cout << tablica[i] << " ";
                }
                cout << endl << "Liczby posortowane rosnaco: ";
                sortRow(tablica, liczba_kolumn);
                for (int i = 0; i < liczba_kolumn; i++) {
                    cout << tablica[i] << " ";
                }
                delete[] tablica;
            } else if (wybor == "sortRowsInMatrix") {
                int **macierz_a, ilosc_wierszy, ilosc_kolumn;
                cout << "Prosze podac ilosc wierszy macierzy: ";
                if (!(cin >> ilosc_wierszy)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                cout << "Prosze podac ilosc kolumn macierzy: ";
                if (!(cin >> ilosc_kolumn)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                macierz_a = utworz_macierz_int(ilosc_wierszy, ilosc_kolumn);

                if (!wypelnianie_macierzy(macierz_a, ilosc_wierszy, ilosc_kolumn)) {
                    for (int i = 0; i < ilosc_wierszy; i++) {
                        delete[] macierz_a[i];
                    }
                    delete[] macierz_a;
                    return 0;
                }

                cout << "ilosc wierszy = " << ilosc_wierszy << endl
                     << "ilosc kolumn = " << ilosc_kolumn << endl
                     << "Macierz A przed posortowaniem:" << endl;

                wyswietl(macierz_a, ilosc_wierszy, ilosc_kolumn);
                sortRowsInMatrix(macierz_a, ilosc_wierszy, ilosc_kolumn);
                cout << "Macierz A po posortowaniu:" << endl;
                wyswietl(macierz_a, ilosc_wierszy, ilosc_kolumn);

                for (int i = 0; i < ilosc_wierszy; i++) {
                    delete[] macierz_a[i];
                }
                delete[] macierz_a;
            }
        } else if (typ_zmiennych == 1) {
            if (wybor == "addMatrix" || wybor == "subtractMatrix") {
                double **macierz_a, **macierz_b, **macierz_w;
                int ilosc_wierszy, ilosc_kolumn;
                cout << "Prosze podac ilosc wierszy macierzy: ";
                if (!(cin >> ilosc_wierszy)) {
                    //zabezpieczenie przed wprowadzeniem tekstu zamiast liczby
                    cout << "Wprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                cout << "Prosze podac ilosc kolumn macierzy: ";
                if (!(cin >> ilosc_kolumn)) {
                    //zabezpieczenie przed wprowadzeniem tekstu zamiast liczby
                    cout << "Wprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }

                //tworzenie macierzy
                macierz_a = utworz_macierz_double(ilosc_wierszy, ilosc_kolumn);
                macierz_b = utworz_macierz_double(ilosc_wierszy, ilosc_kolumn);

                //wypelnianie macierzy, zabezpieczenie przed wprowadzeniem tekstu zamiast liczby
                if (!wypelnianie_macierzy(macierz_a, ilosc_wierszy, ilosc_kolumn)) {
                    //zakonczenie i delokacja pamieci w razie podania tekstu zamiast liczby
                    for (int i = 0; i < ilosc_wierszy; i++) {
                        delete[] macierz_a[i];
                        delete[] macierz_b[i];
                    }
                    delete[] macierz_a;
                    delete[] macierz_b;
                    return 0;
                }
                if (!wypelnianie_macierzy(macierz_b, ilosc_wierszy, ilosc_kolumn)) {
                    //zakonczenie i delokacja pamieci w razie podania tekstu zamiast liczby
                    for (int i = 0; i < ilosc_wierszy; i++) {
                        delete[] macierz_a[i];
                        delete[] macierz_b[i];
                    }
                    delete[] macierz_a;
                    delete[] macierz_b;
                    return 0;
                }
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
                } else if (wybor == "subtractMatrix") {
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
            } else if (wybor == "multiplyMatrix") {
                double **macierz_a, **macierz_b, **macierz_w;
                int ilosc_wierszy_a, ilosc_kolumn_a, ilosc_kolumn_b;
                cout << "Prosze podac ilosc wierszy macierzy A: ";
                if (!(cin >> ilosc_wierszy_a)) {
                    //zabezpieczenie przed wprowadzeniem tekstu zamiast liczby
                    cout << "Wprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                cout << "Prosze podac ilosc kolumn macierzy A: ";
                if (!(cin >> ilosc_kolumn_a)) {
                    cout << "Wprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                cout << "Prosze podac ilosc kolumn macierzy B: ";
                if (!(cin >> ilosc_kolumn_b)) {
                    cout << "Wprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }

                macierz_a = utworz_macierz_double(ilosc_wierszy_a, ilosc_kolumn_a);
                macierz_b = utworz_macierz_double(ilosc_kolumn_a, ilosc_kolumn_b);

                if (!wypelnianie_macierzy(macierz_a, ilosc_wierszy_a, ilosc_kolumn_a)) {
                    for (int i = 0; i < ilosc_wierszy_a; i++) {
                        delete[] macierz_a[i];
                        delete[] macierz_b[i];
                    }
                    delete[] macierz_a;
                    delete[] macierz_b;
                    return 0;
                }
                if (!wypelnianie_macierzy(macierz_b, ilosc_kolumn_a, ilosc_kolumn_b)) {
                    for (int i = 0; i < ilosc_wierszy_a; i++) {
                        delete[] macierz_a[i];
                        delete[] macierz_b[i];
                    }
                    delete[] macierz_a;
                    delete[] macierz_b;
                    return 0;
                }

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

            } else if (wybor == "multiplyByScalar") {
                double **macierz_a, **macierz_w, skalar;
                int ilosc_wierszy, ilosc_kolumn;

                cout << "Prosze podac ilosc wierszy macierzy: ";
                if (!(cin >> ilosc_wierszy)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                cout << "Prosze podac ilosc kolumn macierzy: ";
                if (!(cin >> ilosc_kolumn)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                cout << "Prosze podac skalar: ";
                if (!(cin >> skalar)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }

                macierz_a = utworz_macierz_double(ilosc_wierszy, ilosc_kolumn);

                if (!wypelnianie_macierzy(macierz_a, ilosc_wierszy, ilosc_kolumn)) {
                    for (int i = 0; i < ilosc_wierszy; i++) {
                        delete[] macierz_a[i];
                    }
                    delete[] macierz_a;
                    return 0;
                }

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

            } else if (wybor == "transpozeMatrix") {
                double **macierz_a, **macierz_w;
                int ilosc_wierszy, ilosc_kolumn;
                cout << "Prosze podac ilosc wierszy macierzy: ";
                if (!(cin >> ilosc_wierszy)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                cout << "Prosze podac ilosc kolumn macierzy: ";
                if (!(cin >> ilosc_kolumn)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }

                macierz_a = utworz_macierz_double(ilosc_wierszy, ilosc_kolumn);

                if (!wypelnianie_macierzy(macierz_a, ilosc_wierszy, ilosc_kolumn)) {
                    for (int i = 0; i < ilosc_wierszy; i++) {
                        delete[] macierz_a[i];
                    }
                    delete[] macierz_a;
                    return 0;
                }

                cout << "ilosc wierszy = " << ilosc_wierszy << endl
                     << "ilosc kolumn = " << ilosc_kolumn << endl
                     << "Macierz A:" << endl;

                wyswietl(macierz_a, ilosc_wierszy, ilosc_kolumn);

                macierz_w = transpozeMatrix(macierz_a, ilosc_wierszy, ilosc_kolumn);
                cout << "Wynik transponowania macierzy:" << endl;
                wyswietl(macierz_w, ilosc_kolumn, ilosc_wierszy);

                for (int i = 0; i < ilosc_wierszy; i++) {
                    delete[] macierz_a[i];
                }
                for (int i = 0; i < ilosc_kolumn; i++) {
                    delete[] macierz_w[i];
                }
                delete[] macierz_a;
                delete[] macierz_w;
            } else if (wybor == "powerMatrix") {
                double **macierz_a, **macierz_w;
                int ilosc_wierszy, ilosc_kolumn, potega;
                cout << "Prosze podac ilosc wierszy macierzy: ";
                if (!(cin >> ilosc_wierszy)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                cout << "Prosze podac ilosc kolumn macierzy: ";
                if (!(cin >> ilosc_kolumn)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                cout << "Prosze podac stopien potegi: ";
                if (!(cin >> potega)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }

                macierz_a = utworz_macierz_double(ilosc_wierszy, ilosc_kolumn);

                if (!wypelnianie_macierzy(macierz_a, ilosc_wierszy, ilosc_kolumn)) {
                    for (int i = 0; i < ilosc_wierszy; i++) {
                        delete[] macierz_a[i];
                    }
                    delete[] macierz_a;
                    return 0;
                }

                cout << "ilosc wierszy = " << ilosc_wierszy << endl
                     << "ilosc kolumn = " << ilosc_kolumn << endl
                     << "Macierz A:" << endl;

                wyswietl(macierz_a, ilosc_wierszy, ilosc_kolumn);

                macierz_w = powerMatrix(macierz_a, ilosc_wierszy, ilosc_kolumn, potega);
                cout << "Wynik potegowania macierzy:" << endl;
                wyswietl(macierz_w, ilosc_wierszy, ilosc_kolumn);

                for (int i = 0; i < ilosc_wierszy; i++) {
                    delete[] macierz_a[i];
                    delete[] macierz_w[i];
                }
                delete[] macierz_a;
                delete[] macierz_w;
            } else if (wybor == "determinantMatrix") {
                double **macierz_a;
                int ilosc_wierszy, ilosc_kolumn, wyznacznik;
                cout << "Prosze podac ilosc wierszy macierzy: ";
                if (!(cin >> ilosc_wierszy)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                cout << "Prosze podac ilosc kolumn macierzy: ";
                if (!(cin >> ilosc_kolumn)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }

                macierz_a = utworz_macierz_double(ilosc_wierszy, ilosc_kolumn);
                if (!wypelnianie_macierzy(macierz_a, ilosc_wierszy, ilosc_kolumn)) {
                    for (int i = 0; i < ilosc_wierszy; i++) {
                        delete[] macierz_a[i];
                    }
                    delete[] macierz_a;
                    return 0;
                }

                cout << "ilosc wierszy = " << ilosc_wierszy << endl
                     << "ilosc kolumn = " << ilosc_kolumn << endl
                     << "Macierz A:" << endl;

                wyswietl(macierz_a, ilosc_wierszy, ilosc_kolumn);
                wyznacznik = determinantMatrix(macierz_a, ilosc_wierszy, ilosc_kolumn);
                cout << "Wyznacznik jest rowny: " << wyznacznik << endl;

                for (int i = 0; i < ilosc_wierszy; i++) {
                    delete[] macierz_a[i];
                }
                delete[] macierz_a;
            } else if (wybor == "matrixIsDiagonal") {
                bool wynik;
                double **macierz_a;
                int ilosc_wierszy, ilosc_kolumn;

                cout << "Prosze podac ilosc wierszy macierzy: ";
                if (!(cin >> ilosc_wierszy)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                cout << "Prosze podac ilosc kolumn macierzy: ";
                if (!(cin >> ilosc_kolumn)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }

                macierz_a = utworz_macierz_double(ilosc_wierszy, ilosc_kolumn);
                if (!wypelnianie_macierzy(macierz_a, ilosc_wierszy, ilosc_kolumn)) {
                    for (int i = 0; i < ilosc_wierszy; i++) {
                        delete[] macierz_a[i];
                    }
                    delete[] macierz_a;
                    return 0;
                }

                cout << "ilosc wierszy = " << ilosc_wierszy << endl
                     << "ilosc kolumn = " << ilosc_kolumn << endl
                     << "Macierz A:" << endl;

                wyswietl(macierz_a, ilosc_wierszy, ilosc_kolumn);

                wynik = matrixIsDiagonal(macierz_a, ilosc_wierszy, ilosc_kolumn);

                if (wynik) {
                    cout << "Podana macierz jest diagonalna" << endl;
                } else {
                    cout << "Podana macierz nie jest diagonalna" << endl;
                }

                for (int i = 0; i < ilosc_wierszy; i++) {
                    delete[] macierz_a[i];
                }
                delete[] macierz_a;
            } else if (wybor == "swap") {
                double a, b;
                cout << "Podaj wartosc a: ";
                if (!(cin >> a)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                cout << "Podaj wartosc b: ";
                if (!(cin >> b)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }

                cout << "a = " << a << " b = " << b << endl;
                swap(a, b);
                cout << "a = " << a << " b = " << b << endl;
            } else if (wybor == "sortRow") {
                int liczba_kolumn;
                cout << "Prosze podac rozmiar tablicy: ";
                if (!(cin >> liczba_kolumn)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                double *tablica = new double[liczba_kolumn];
                cout << "Prosze podac liczby do wczytania: " << endl;

                for (int i = 0; i < liczba_kolumn; i++) {
                    if (!(cin >> tablica[i])) {
                        cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                        delete[] tablica;
                        return 0;
                    }
                }

                cout << "Podane liczby: ";
                for (int i = 0; i < liczba_kolumn; i++) {
                    cout << tablica[i] << " ";
                }
                cout << endl << "Liczby posortowane rosnaco: ";
                sortRow(tablica, liczba_kolumn);
                for (int i = 0; i < liczba_kolumn; i++) {
                    cout << tablica[i] << " ";
                }
                delete[] tablica;
            } else if (wybor == "sortRowsInMatrix") {
                double **macierz_a;
                int ilosc_wierszy, ilosc_kolumn;
                cout << "Prosze podac ilosc wierszy macierzy: ";
                if (!(cin >> ilosc_wierszy)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                cout << "Prosze podac ilosc kolumn macierzy: ";
                if (!(cin >> ilosc_kolumn)) {
                    cout << "\nWprowadzono nieprawidlowe znaki\n" << endl;
                    help();
                    return 0;
                }
                macierz_a = utworz_macierz_double(ilosc_wierszy, ilosc_kolumn);

                if (!wypelnianie_macierzy(macierz_a, ilosc_wierszy, ilosc_kolumn)) {
                    for (int i = 0; i < ilosc_wierszy; i++) {
                        delete[] macierz_a[i];
                    }
                    delete[] macierz_a;
                    return 0;
                }

                cout << "ilosc wierszy = " << ilosc_wierszy << endl
                     << "ilosc kolumn = " << ilosc_kolumn << endl
                     << "Macierz A przed posortowaniem:" << endl;

                wyswietl(macierz_a, ilosc_wierszy, ilosc_kolumn);
                sortRowsInMatrix(macierz_a, ilosc_wierszy, ilosc_kolumn);
                cout << "Macierz A po posortowaniu:" << endl;
                wyswietl(macierz_a, ilosc_wierszy, ilosc_kolumn);

                for (int i = 0; i < ilosc_wierszy; i++) {
                    delete[] macierz_a[i];
                }
                delete[] macierz_a;
            }
        }else {
            cout << "Wprowadzono niepoprawny typ zmiennych\n\n";
            help();
        }
    }else {
        cout << "Wprowadzona komenda jest niepoprawna\n\n" << endl;
        help();

    }
}



