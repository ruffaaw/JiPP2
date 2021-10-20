#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int konwertowanie(string ciag_znakow){
    int przekonwertowany_ciag_znakow;
    przekonwertowany_ciag_znakow = stoi(ciag_znakow);

    return przekonwertowany_ciag_znakow;
}
int main(){
    string ciag_znakow;
    int przekonwertowany_ciag_znakow;

    cout << "Podaj ciag znakow do przekonwertowania:"<<endl;
    cin >> ciag_znakow;

    try{
        cout << konwertowanie(ciag_znakow) << endl;

    }
    catch(std::invalid_argument& e)
    {
        cout << "Wprowadzony ciag zawiera nieprawidlowe znaki" << endl;
    }
    catch(std::out_of_range& e)
    {
        cout << "Podana wartosc jest za duza" << endl;
    }
}
