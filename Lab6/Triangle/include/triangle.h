#ifndef VECTOR_TRIANGLE_H
#define VECTOR_TRIANGLE_H
#include <iostream>

using namespace std;

class Triangle;

class Node{
private:
    double x, y;

public:
    Node();

    Node(double x, double y);

    void display();

    friend ostream &operator<<(ostream &lhs, const Triangle &rhs);

    friend double node_distance(Node a, Node b);
};

class Triangle{
private:
    Node a, b, c;
    string name;

public:
    Triangle(Node a, Node b, Node c, string name);

    void display();

    friend ostream &operator<<(ostream &lhs, const Triangle &rhs);

    double distance(int firstPointIndex, int secondPointIndex);

    void showTriangleData(Triangle triangle);

    void showTriangleData(Triangle &triangle);

    void showTriangleData(Triangle *triangle);
};

#endif //VECTOR_TRIANGLE_H
