#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> li= { 10, 20, 42, 50, 75 };


    list<int>::iterator x;
    cout<<"Wynik: "<<endl;

    for (x = li.begin(); x != li.end(); x++) {
//iterator wyjścia do zmiany lub przypisania nowych wartości do wszystkich
// elementów listy
        *x = 4;
    }
    for (x = li.begin(); x != li.end(); x++) {
//używanie iteratora wejściowego do przechodzenia przez listę
        cout << (*x) << " ";
    }

    return 0;
}