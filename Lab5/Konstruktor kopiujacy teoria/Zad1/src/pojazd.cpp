#include <iostream>
#include "../include/pojazd.h"

Pojazd::Pojazd(int nr_rejestracyjny, string nazwa, int ilosc_miejsc, string typ_pojazdu):
    nr_rejestracyjny(nr_rejestracyjny),
    nazwa(nazwa),
    ilosc_miejsc(ilosc_miejsc),
    marka_typ(typ_pojazdu)
{
    dane_pasazera = new string[ilosc_miejsc];

    for (int i = 0; i < ilosc_miejsc; i++){
        dane_pasazera[i] = "empty";
    }
}

Pojazd::Pojazd(Pojazd &kopia):
    nr_rejestracyjny(kopia.nr_rejestracyjny),
    nazwa(kopia.nazwa),
    ilosc_miejsc(kopia.ilosc_miejsc),
    marka_typ(kopia.marka_typ)
{
    dane_pasazera = new string[ilosc_miejsc];

    for(int i = 0; i < ilosc_miejsc; i++){
        dane_pasazera[i] = kopia.dane_pasazera[i];
    }
}

void Pojazd::print(){
    cout << "Numer rejestracyjny: " << nr_rejestracyjny << endl;
    cout << "Nazwa pojazdu: " << nazwa << endl;
    cout << "Dostepne miejsca: " << ilosc_miejsc << endl;
    cout << "Pasazerowie: ";
    for(int i = 0; i < ilosc_miejsc; i++){
        cout << dane_pasazera[i] << endl;
    }
    cout << "Typ pojazdu" << marka_typ;
}

void Pojazd::zmiana_info(int nr_miejsca, string info_pasazer){
    dane_pasazera[nr_miejsca] = info_pasazer;
}

string Pojazd::get_name(){
    return this->nazwa;
}
int Pojazd::get_nr_rejestracyjny() {
    return this->nr_rejestracyjny;
}

string Pojazd::get_typ() {
    return this->marka_typ;
}

void Pojazd::set_nazwa(string nazwa) {
    this->nazwa=nazwa;
}

void Pojazd::set_nr_rejestracyjny(int numer){
    this->nr_rejestracyjny = numer;
}

void Pojazd::wypiszWerOpro() {
    cout << "Zainstalowana wersja oprogramowania: " << zainstalowanaWersjaOprogramowania << endl;
}

void Pojazd::opublikujNowOprog(string wersja) {
    najnowszaWersjaOprogramowania = wersja;
}

void Pojazd::zaktuaWerOpro() {
    zainstalowanaWersjaOprogramowania = najnowszaWersjaOprogramowania;
}


