#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
using namespace std;

class Student{
    string imie;
    string nazwisko;
    int numer_albumu;
    double liczba_pytan;
    double poprawne_odpowiedzi;

public:

    void wprowadz();
    double oblicz();
};

#endif //STUDENT_H
