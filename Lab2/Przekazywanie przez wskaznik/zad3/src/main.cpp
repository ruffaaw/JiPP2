#include <iostream>

using namespace std;
void sortowanie(int *tablica, int n){
    //sortowanie babelkowe
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n; j++){
            if(tablica[j-1] > tablica[j]){
                swap(tablica[j-1], tablica[j]);
            }
        }
    }
}

int main() {
    int rozmiar_tablicy;
    int *tablica;

    cout << "Podaj rozmiar tablicy: ";
    cin >> rozmiar_tablicy;

    tablica = new int[rozmiar_tablicy]();

    cout << "Podaj liczby do wczytania: " << endl;
    for (int i = 0; i < rozmiar_tablicy; i++) {
        cin >> tablica[i];
    }

    sortowanie(tablica, rozmiar_tablicy);

    cout << "Liczby posortowane rosnaco: ";

    for (int i = 0; i < rozmiar_tablicy; i++){
        cout << tablica[i] << " ";
    }
    delete[] tablica;
    return 0;

}