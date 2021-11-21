#ifndef E1NOCOPYINGCONSTRUCTOR_POJAZD_H
#define E1NOCOPYINGCONSTRUCTOR_POJAZD_H

#include <iostream>
using namespace std;

class Pojazd{
private:
    int nr_rejestracyjny;
    string nazwa;
    int ilosc_miejsc;
    string *dane_pasazera;
    string marka_typ;
    static string najnowszaWersjaOprogramowania;
    string zainstalowanaWersjaOprogramowania;

public:
    Pojazd(int nr_rejestracyjny, string nazwa, int ilosc_miejsc, string typ_pojazdu);

    Pojazd(Pojazd &pojazd);

    void print();

    void zmiana_info(int nr_miejsca, string info_pasazer);

    string get_name();

    int get_nr_rejestracyjny();

    string get_typ();

    void set_nazwa(string nazwa);

    void set_nr_rejestracyjny(int numer);

    void wypiszWerOpro();
    void zaktuaWerOpro();
    static void opublikujNowOprog(string wersja);

};
#endif //E1NOCOPYINGCONSTRUCTOR_POJAZD_H
