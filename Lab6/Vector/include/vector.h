#ifndef NODE_VECTOR_H
#define NODE_VECTOR_H
#include <iostream>

using namespace std;

class Vector{
private:
    double x, y;

public:
    Vector() {};

    Vector(double x, double y);

    double length();

    Vector operator+(const Vector &rhs) const;

    Vector operator+=(const Vector &rhs);

    void print();

    Vector operator-(const Vector &rhs) const;

    Vector operator*(double skalar) const;

    Vector operator~() const;

    double operator^(const Vector &rhs) const; //iloczyn skalarny

    bool operator==(const Vector &rhs); //porownywanie wektorow

    friend Vector operator*(const double &lhs, const Vector &rhs);

    friend ostream &operator<<(ostream &lhs, const Vector &rhs);

};

class Imaginary{
private:
    double x, i;
public:
    Imaginary();

    Imaginary (double x, double i);

    double length();

    Imaginary operator+(const Imaginary &rhs) const;

    Imaginary operator+=(const Imaginary &rhs);

    void print_imaginary();

    Imaginary operator-(const Imaginary &rhs) const;

    Imaginary operator*(double skalar) const;

    Imaginary operator~() const;

    double operator^(const Imaginary &rhs) const; //iloczyn skalarny

    bool operator==(const Imaginary &rhs); //porownywanie wektorow

    friend Imaginary operator*(const double &lhs, const Imaginary &rhs);

    friend ostream &operator<<(ostream &lhs, const Imaginary &rhs);
};


#endif //NODE_VECTOR_H