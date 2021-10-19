
#include <iostream>
#include "../include/calc.h"
using namespace std;

int main(int argc, char *argv[]) {
    string wybor = argv[1];

    if (wybor == "add"){
        cout<<add()<<endl;
        return 0;
    }
    else if(wybor == "subtract"){
        cout<<subtract()<<endl;
        return 0;
    }
    else if(wybor == "volume"){
        cout<<volume()<<endl;
        return 0;
    }
    else if (wybor == "help"){
        help();
        return 0;
    }
    help();
    return 0;
}

