#include <iostream>
using namespace std;

void funkcja(int x, int *wsk_w){
    *wsk_w = x;
}
int main(){
    int x,y;
    cout << "Prosze podac dwie liczby do wczytania:"<< endl;
    cin >> x >> y;

    int *wsk_w = &y;
    cout << "x = "<< x << " " << "y = "<< y << endl;

    funkcja(x, wsk_w);

    cout << "x = "<< x << " " << "y = "<< y << endl;
    return 0;
}

