#include <iostream>
#include "../include/student.h"

using namespace std;

void Student::wprowadz() {
    cout << "Podaj imie studenta: ";
    cin >> imie;
    cout << "Podaj nazwisko studenta";
    cin >> nazwisko;
    cout << "Podaj numer albumu studenta: ";
    cin >> numer_albumu;
    cout << "Podaj ilosc pytan: ";
    cin >> liczba_pytan;
    cout << "Podaj ilosc poprawnych odpowiedzi: ";
    cin >> poprawne_odpowiedzi;
}

double Student::oblicz() {
    double wynik;

    wynik = (poprawne_odpowiedzi / liczba_pytan) * 100;
    return wynik;

}

