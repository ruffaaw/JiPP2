
#ifndef LAB9_STOP_H
#define LAB9_STOP_H
#include <iostream>

using namespace std;

class Stop {
private:
    long id;
    string name;
    double latitude;
    double longitude;

public:
    Stop(long id, const string &name, double latitude, double longitude);

    Stop() {};

    void print();
};
#endif //LAB9_STOP_H
