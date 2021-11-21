#include <iostream>

using namespace std;

int main() {
    int cVal = 314;
    int *const p = &cVal;

    *p = 628;

    int cVal2 = 666;
    p = &cVal2;

}

