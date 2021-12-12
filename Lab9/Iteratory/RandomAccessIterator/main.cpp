#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> li= {10, 20, 42, 50, 75};
    list<int>::iterator x;

    cout<<"Przejscie po elementach listy do przodu "<<endl;


    for (x = li.begin(); x != li.end(); x++) {

        cout << (*x) << " "; //używanie iteratora wejściowego do przechodzenia przez listę
    }
    cout<<endl;

    list<int>::iterator ee = li.begin();

    advance(ee, 3);
    cout << "Element wskazywany przez iterator po uzyciu metody Advance():";
    cout << *ee << " ";
    cout<<endl;
    list<int>::iterator A = li.begin();
    list<int>::iterator B = li.end();

    auto aa = next(A, 2);


    auto  bb = prev(B, 2);

    cout << "Element wskazany za pomoca next() to : ";
    cout << *aa << " ";
    cout << endl;

    cout << "Element wskazany za pomoca prev() to : ";
    cout << *bb << " ";
    cout << endl;

    return 0;
}