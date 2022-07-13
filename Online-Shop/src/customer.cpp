#include "../include/customer.h"

void Customer::working(){
    while (!ans)
    {
        string addedString; // this contains username+password

        addedString = User::getData();

        if (checkData(addedString))
        {
            ans = true;
        }

        else
        {
            cout << "Your Account doesn't exist in out records,\nDo you want to CREATE ACCOUNT? Y/N: ";
            char select;
            cin >> select;
            if (select == 'y' || select == 'Y')
            {
                User::createAccount(addedString);
            }
            else
            {
                cout << "Thank for using our service!!" << endl;
                ans = false;
                break;
            }
            ans = true;
        }
    }
}

bool Customer::returnAuthorized(){
    return ans;
}

void Customer::customerData(){
    if (ans == true)
    {
        number += 1;
        cout << "Dear " << username << " , Please enter your Billing address: ";
        cin.ignore();
        getline(cin, this->address);
        cout << endl;
        cout << "Thank You for the moment!!" << endl
             << "Your id is: " << number << endl;
        cout << endl;
    }
}