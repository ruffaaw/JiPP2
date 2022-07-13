#include "../include/user.h"
#include "../include/payment.h"
#include "../include/finalize.h"

string encrypt(string user, string pass){
    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string us = "UserName=", ps = "Password=";
    for (char x : user)
    {
        if (isalpha(x))
        {
            int y = 0;
            y = letters.find(x);
            us += to_string(y * 2);
            us += "\\";
        }
        else
        {
            us += to_string(x);
            us += "\\";
        }
    }
    for (char x : pass)
    {
        if (isalpha(x))
        {
            int y = 0;
            y = letters.find(x);
            ps += to_string(y * 2);
            ps += "/";
        }
        else
        {
            ps += to_string(x);
            ps += "/";
        }
    }
    return us + ps;
}


int main(int argc, char *argv[]){
    string choose;
    choose = argv[1];
    if (choose == "shopping" | choose == "Shopping" | choose == "SHOPPING") {
        Finalize object;
        object.finalize();
    }
    else{
        cout << "Enter param" << endl;
        return 0;

    }
}