#include <iostream>
#include "../include/triangle.h"
#include <math.h>

Node::Node() {
    x = 0;
    y = 0;
}

Node::Node(double x, double y): x(x), y(y) {};

Triangle::Triangle(Node a, Node b, Node c, string name): a(a), b(b), c(c), name(name){};

void Node::display() {
    cout << "x = " << x << " y = " << y <<endl;
}

void Triangle::display() {
    cout << "name: " << name << endl;
    cout << "a: ";
    a.display();
    cout << "b: ";
    b.display();
    cout << "c: ";
    c.display();
}

ostream &operator<<(ostream &lhs, const Triangle &rhs){
    return lhs << "name: " << rhs.name << "\na: x = " <<rhs.a.x << " y = " << rhs.a.y <<
    "\nb: x = " << rhs.b.x << " y = " << rhs.b.y <<
    "\nc: x = " << rhs.c.x << " y = " << rhs.c.y;
}

double Triangle::distance(int firstPointIndex, int secondPointIndex) {
    Node tab[3] = {a, b, c};
    return node_distance(tab[firstPointIndex], tab[secondPointIndex]);
}

double node_distance(Node a, Node b){
    return sqrt(pow((b.x-a.x), 2) + pow((b.y - a.y), 2));
}

void Triangle::showTriangleData(Triangle triangle) {
    cout << "name: " << name << endl;
    cout << "a: ";
    a.display();
    cout << "b: ";
    b.display();
    cout << "c: ";
    c.display();
}

void Triangle::showTriangleData(Triangle &triangle) {
    cout << "name: " << name << endl;
    cout << "a: ";
    a.display();
    cout << "b: ";
    b.display();
    cout << "c: ";
    c.display();
}

void Triangle::showTriangleData(Triangle *triangle) {
    cout << "name: " << name << endl;
    cout << "a: ";
    a.display();
    cout << "b: ";
    b.display();
    cout << "c: ";
    c.display();
}