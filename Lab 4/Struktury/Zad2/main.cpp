#include <iostream>
using namespace std;
struct samochod{
    string marka;
    string model;
    int rok_produkcji;
    string kolor;
    int przebieg;
};

int main(){
    int liczba_modeli = 4;
    samochod model[] = {{"BMW", "M2", 2020, "czarny", 50000},
                        {"Ford", "Mustang", 2021, "szary", 70000},
                        {"Mazda", "6", 2016, "bialy", 90000},
                        {"Tesla", "Model X", 2021, "zielony", 5}};

    cout << "Marka\tModel\tRok produkcji\tKolor\t\tPrzebieg" << endl;
    cout << "-----------------------------------------------------------" << endl;

    for (int i = 0; i < liczba_modeli; i++){
        cout << model[i].marka << "\t" << model[i].model << "\t" << model[i].rok_produkcji << "\t\t"
        << model[i].kolor << "\t\t" << model[i].przebieg << endl;
    }
    return 0;
}

