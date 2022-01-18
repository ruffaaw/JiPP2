#include <iostream>
using namespace std;
int main ()
{
    double y;
    int x;
    cout << "Podaj wymiar kwadratu: ";
    cin >> y;
    cout << "x = " << y << endl;
    x = (int) y;
    cout << "Po konwersji:\n" << "x = " << x << endl;

    //liczenie pola kwadratu
    int pole;
    pole = x * x;
    cout << "Pole wynosi: " << pole << endl;
}