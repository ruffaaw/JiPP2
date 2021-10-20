//
// Created by Rafal on 20.10.2021.
//
#include <iostream>
using namespace std;

void funkcja(int *tablica, int rozmiar_tablicy){
    cout << "Liczby wieksze od 0: ";
    for (int i = 0; i < rozmiar_tablicy; i++){
        if(tablica[i] > 0){
            cout << tablica[i] << " ";
        }
    }
}

int main(){
    int rozmiar_tablicy;
    int* tablica;

    cout << "Podaj rozmiar tablicy: ";
    cin >> rozmiar_tablicy;

    tablica = new int[rozmiar_tablicy]();

    cout << "Podaj liczby do wczytania: " << endl;
    for(int i = 0; i < rozmiar_tablicy; i++){
        cin >> tablica[i];
    }

    funkcja(tablica, rozmiar_tablicy);

    delete[] tablica;

    return 0;

}
