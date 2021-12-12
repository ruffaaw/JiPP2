#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> li= { 10, 20, 42, 50, 75 };


    list<int>::iterator x;
    cout<<"Przejście po elementach lsty"<<endl;
    for (x = li.begin(); x != li.end(); ++x) {

        cout << (*x) << " "; //używanie iteratora wejściowego do przechodzenia przez listę
    }


    for (x = li.begin(); x != li.end(); x++) {
// użycie iteratora wyjścia do zmiany lub przypisania nowych wartości do wszystkich
// elementów listy
        *x = 4;
    }
    cout<<endl;
    cout<<"Traversing elements of the list after assigning a new value to the list.."<<endl;
    for (x = li.begin(); x != li.end(); ++x) {

        cout << (*x) << " "; //używanie iteratora wejściowego do przechodzenia przez listę
    }

    return 0;
}