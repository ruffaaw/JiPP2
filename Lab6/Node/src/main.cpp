#include <iostream>
#include "../include/node.h"

using namespace std;

int main(){
    int a_x, a_y, b_x, b_y;
    cout << "Podaj wspolrzedne punktu A:\nx = ";
    cin >> a_x;
    cout << "y = ";
    cin >> a_y;

    cout << "Podaj wspolrzedne punktu B:\nx = ";
    cin >> b_x;
    cout << "y = ";
    cin >> b_y;

    Node a(a_x, a_y);
    Node b(b_x, b_y);
    cout << pointsDistance(a,b) << endl;
}