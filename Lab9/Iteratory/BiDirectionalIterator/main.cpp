#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> li= { 10, 20, 42, 50, 75 };


    list<int>::iterator x;
    cout<<"Przejście po elementach listy do przodu."<<endl;


    for (x = li.begin(); x != li.end(); x++) {
//używanie iteratora wejściowego do przechodzenia przez listę
        cout << (*x) << " ";
    }
    cout<<endl;
    cout<<"Przechodzenie przez elementy listy w kierunku wstecznym"<<endl;

    for (x=li.end();x!=li.begin();--x)
    {
        if (x != li.end())
        {
            cout << (*x) << " ";
        }
    }
    cout << (*x);

    return 0;
}