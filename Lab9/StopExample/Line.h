
#ifndef LAB9_LINE_H
#define LAB9_LINE_H
#include "Line.h"

#include <iostream>
#include <vector>
#include "Stop.h"

using namespace std;

class Line {
private:
    string number;
    string direction;
    vector<Stop *> stops;

public:
    Line(const string &number, const string &direction);

    void addStop(Stop * stop);

    void print();

    void iterator(vector<Stop> :: iterator A);
};

#endif //LAB9_LINE_H
