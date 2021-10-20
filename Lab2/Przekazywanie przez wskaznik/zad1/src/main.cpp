
#include <iostream>

using namespace std;

double srednia(double* x, double* y){
    return ((*x + *y)/2);
}

int main(){

    double x, y;

    cout << "Podaj dwie liczby: " << endl;
    cin >> x >> y;

    double *wsk_x = &x;
    double *wsk_y = &y;

    cout << srednia(wsk_x, wsk_y) << endl;

}
