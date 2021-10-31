#include <iostream>
#include "../include/student.h"

using namespace std;

int main(){
    Student student;
    student.wprowadz();
    student.oblicz();
    cout << "Wynik studenta to: " << student.oblicz() << "%" << endl;
    return 0;
}
