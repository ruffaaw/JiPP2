#ifndef USER_H
#define USER_H
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;
string encrypt(string, string);

class User
{
protected:
    string username, password;
    string formatedString;

public:
    User();
    ~User();
    static int number;
    virtual string getData()
    {
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
        formatedString = encrypt(username, password);
        //cout << formatedString << endl;
        return formatedString;
    }

    void createAccount(string userData);

    virtual bool checkData(string userData)
    {
        int offset;
        string line;
        ifstream Myfile;
        Myfile.open("Users.txt");

        if (Myfile.is_open())
        {
            while (!Myfile.eof())
            {
                getline(Myfile, line);
                if ((offset = line.find(userData, 0)) != string::npos)
                {
                    cout << "ACCOUNT FOUND" << endl;
                    return true;
                }
                else if (Myfile.eof())
                {
                    cout << "ACCOUNT NOT FOUND, PLEASE CREATE ACCOUNT!!" << endl;
                }
            }
            Myfile.close();
        }
        else
            cout << "Unable to open this file." << endl;

        return false;
    }
};



#endif //USER_H
