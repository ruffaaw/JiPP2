#include <iostream>
#include "../include/vector.h"
#include <math.h>

Vector::Vector(double x, double y) : x(x), y(y) {};

double Vector::length() {
    return sqrt(x * x + y * y);
}

Vector Vector::operator+(const Vector &rhs) const {
    return {x + rhs.x, y + rhs.y};
}

Vector Vector::operator+=(const Vector &rhs) {
    this->x = this->x + rhs.x;
    this->y = this->y + rhs.y;
    return *this;
}

void Vector::print() {
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

Vector Vector::operator-(const Vector &rhs) const {
    return{x-rhs.x, y - rhs.y};
}

Vector Vector::operator*(double skalar) const{
    return {x*skalar, y*skalar};
}
Vector Vector::operator~() const {
    return{-x, -y};
}

double Vector::operator^(const Vector &rhs) const {
    return {x*rhs.x + y*rhs.y};
}

bool Vector::operator==(const Vector &rhs) {
    if(x = rhs.x && y == rhs.y)
        return true;
    else
        return false;
}

Vector operator*(const double &lhs, const Vector &rhs){
    return {rhs.x*lhs, rhs.y*lhs};
}

ostream &operator<<(ostream &lhs, const Vector &rhs) {
    return cout << rhs.x << " " << rhs.y;
}

Imaginary::Imaginary(double x, double i): x(x), i(i) {};

double Imaginary::length() {
    return sqrt(x * x + i * i);
}

Imaginary Imaginary::operator+(const Imaginary &rhs) const {
    return {x + rhs.x, i + rhs.i};
}

Imaginary Imaginary::operator+=(const Imaginary &rhs) {
    this->x = this->x + rhs.x;
    this->i = this->i + rhs.i;
    return *this;
}

void Imaginary::print_imaginary() {
    if(i > 0)
        cout << x << "+" << i << "i" << endl;
    else if (i == 0)
        cout << x << endl;
    else
        cout << x << i << endl;
}

Imaginary Imaginary::operator-(const Imaginary &rhs) const {
    return{x-rhs.x, i - rhs.i};
}

Imaginary Imaginary::operator*(double skalar) const{
    return {x*skalar, i*skalar};
}
Imaginary Imaginary::operator~() const {
    return{-x, -i};
}

double Imaginary::operator^(const Imaginary &rhs) const {
    return {x*rhs.x + i*rhs.i};
}

bool Imaginary::operator==(const Imaginary &rhs) {
    if(x = rhs.x && i == rhs.i)
        return true;
    else
        return false;
}

Imaginary operator*(const double &lhs, const Imaginary &rhs){
    return {rhs.x*lhs, rhs.i*lhs};
}

ostream &operator<<(ostream &lhs, const Imaginary &rhs) {
    return cout << rhs.x << " " << rhs.i << endl;
}