#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> li= { 10, 20, 42, 50, 75 };


    list<int>::iterator x;
    cout<<"Wynik: ."<<endl;

    for (x = li.begin(); x != li.end(); x++) {

        cout << (*x) << " ";
    }
    return 0;
}