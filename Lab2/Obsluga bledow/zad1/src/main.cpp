#include <iostream>
using namespace std;

double dzielenie(int a, int b){
    int wynik;
    if (a % b != 0){
        throw invalid_argument("Wynik dzielenia nie jest naturalny");
    }
    return wynik = a / b;

}

int main(){
    int a,b;
    cout << "Podaj dwie liczby:" << endl;
    cin >> a >> b;

    try{
        cout << dzielenie(a,b) << endl;
    }
    catch (invalid_argument& e){
        cerr << e.what() << endl;
        return -1;
    }
    return 0;
}
