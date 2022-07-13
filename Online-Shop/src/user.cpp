#include "../include/user.h"

User::User(){}

User::~User(){};

void User::createAccount(string userData)
{
    ofstream fout; // object for writing into the file

    fout.open("Users.txt", ios::app); // opening the file in apppend mode

    fout << userData << "\n";

    cout << "Your Account has been Created" << endl;
    // number += 1;

    fout.close();
}

int User::number = rand() % 100 + 10000;