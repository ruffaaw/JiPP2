#include <iostream>
using namespace std;
struct samochod{
    string marka;
    string model;
    int rok_produkcji;
    string kolor;
};

int main(){
    int liczba_modeli = 4;
    samochod model[] = {{"BMW", "M2", 2020, "czarny"},
                          {"Ford", "Mustang", 2021, "szary"},
                          {"Mazda", "6", 2016, "czerwony"},
                          {"Tesla", "Model X", 2021, "zielony"}};

    cout << "Marka\tModel\tRok produkcji\tKolor" << endl;
    cout << "--------------------------------------" << endl;

    for (int i = 0; i < liczba_modeli; i++){
        cout << model[i].marka << "\t" << model[i].model << "\t" << model[i].rok_produkcji << "\t\t" << model[i].kolor << endl;
    }
    return 0;
}