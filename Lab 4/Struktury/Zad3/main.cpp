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
int liczenie_samochodow(samochod *tab, liczenie *liczba){
    int a = 0;
    bool bul = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(tab[i].marka == liczba[j].marka){
                liczba[j].liczba++;
                bul = 1;
            }
        }
        if(bul == 0){
            liczba[a].liczba = 1;
            liczba[a].marka = tab[i].marka;
            a++;
        }
        bul = 0;
    }
    for(int i = 0; i < a; i++){
        cout <<liczba[i].marka << "-" << liczba[i].liczba <<endl;
    }
    return 0;
}


int main() {
    int liczba_modeli = 4;
    samochod model[] = {{"BMW",   "M2",      2020, "czarny"},
                        {"Ford",  "Mustang", 2021, "szary"},
                        {"Mazda", "6",       2016, "czerwony"},
                        {"Tesla", "Model X", 2021, "zielony"}};

    cout << "Marka\tModel\tRok produkcji\tKolor" << endl;
    cout << "--------------------------------------" << endl;

    for (int i = 0; i < liczba_modeli; i++){
        cout << model[i].marka << "\t" << model[i].model << "\t" << model[i].rok_produkcji << "\t\t" << model[i].kolor << endl;
    }
    cout << "\n";

    liczenie *liczba = new liczenie[liczba_modeli];
    cout << liczenie_samochodow(model, liczba) << endl;

    return 0;

}
