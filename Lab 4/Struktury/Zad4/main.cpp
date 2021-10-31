#include <iostream>
using namespace std;

struct samochod{
    string marka;
    string model;
    int rok_produkcji;
    string kolor;
};
struct liczenie{
    string marka;
    int liczba;
};

int najstarszy(samochod* tab, liczenie* liczba){
    int a =0;
    for (int i = 0; i < 4; i++){
        if (i == 0){
            a = tab[i].rok_produkcji;
        }
        else if (tab[i].rok_produkcji < a){
            a = tab[i].rok_produkcji;
        }
    }
    return a;
}

int main() {
    int liczba_modeli = 4;
    int a;
    samochod model[] = {{"BMW",   "M2",      2020, "czarny"},
                        {"Ford",  "Mustang", 2021, "szary"},
                        {"Mazda", "6",       2016, "czerwony"},
                        {"Tesla", "Model X", 2016, "zielony"}};

    cout << "Marka\tModel\tRok produkcji\tKolor" << endl;
    cout << "--------------------------------------" << endl;

    for (int i = 0; i < liczba_modeli; i++){
        cout << model[i].marka << "\t" << model[i].model << "\t" << model[i].rok_produkcji << "\t\t" << model[i].kolor << endl;
    }
    cout << "\n";

    liczenie *liczba = new liczenie[liczba_modeli];
    a = najstarszy(model, liczba);
    cout << "Najstarsze samochody:"<< endl;

    for (int i = 0; i < 4; i++){
        if(model[i].rok_produkcji == a){
            cout << model[i].marka << "\t" << model[i].model << "\t" << model[i].rok_produkcji << endl;
        }
    }

    return 0;

}
