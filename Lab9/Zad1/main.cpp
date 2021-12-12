#include <iostream>
#include <list>

using namespace std;

int main(){
    list <string> li = {"a", "b", "c", "d", "e", "f", "g"};
    list <string> :: iterator x;
    cout << "Elementy listy: ";
    for (x = li.begin(); x != li.end(); ++x){
        cout << (*x) << " ";
    }
    cout << endl;

    string c;
    for (x = li.begin(); x!= li.end(); x++){
        for (char &c : (*x))
           c = toupper(c);
    }
    cout << "Duze litery: ";
    for (x = li.begin(); x!=li.end(); ++x){
        cout << (*x) << " ";
    }

    return 0;

}