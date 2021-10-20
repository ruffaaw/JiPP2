#include <iostream>

using namespace std;

double pole(int a, int b, int h){
    double wynik;
    return wynik = 0.5 * (a + b) * h;
}

double pole(int a, int h){
    double wynik;
    return wynik = 0.5 * a * h;
}

int main(){
    double pole_1;
    double pole_2;

    pole_1 = pole(1,2,3);
    pole_2 = pole(1,2);

    cout << pole_1 << "\n" << pole_2 << endl;

}

