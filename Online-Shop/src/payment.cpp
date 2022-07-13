#include "../include/payment.h"

int Payment::OrderNumber = rand() % 100 + 1000;

Payment::Payment() {}

Payment::~Payment() {}

void Payment::showCosts()
{

    cout << "Your Order Number is: " << OrderNumber << endl;
    cout << "Item\t\t"
         << "Price/Each\t\t"
         << "Total" << endl;

    for (int i = 0; i < customerList.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << customerList[i][j] << "\t\t";
            if (j == 2)
            {
                stringstream ss(customerList[i][j]);
                int x = 0;
                ss >> x;
                totalCost += x;
                //cout << x;
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << "YOUR TOTAL COST IS: " << totalCost << "$" << endl;
    cout << endl;
}

void Payment::agrii()
{
    cout << "Do you want to continue to Payment step? Y/N: ";
    char y;
    cin >> y;
    if (y == 'Y' || y == 'y')
    {
        done = true;
        OrderNumber += 1;
        cout << "Please Enter your Payment Method 1 or 2" << endl;
        cout << "1: Cash On delivery" << endl;
        cout << "2: Credit Card" << endl;
        cout << endl;
        cout << "Your Method: ";
        int y;
        cin >> y;
        if (y == 1)
        {
            paymentMethod = "Cash On Delivery!";
        }
        else if (y == 2)
        {
            paymentMethod = "Credit Card";
            cout << "Enter Credit Card number: ";
            cin >> card;
            cout << "Enter Your PIN: ";
            cin >> pin;
        }
    }
    else
    {
        done = false;
        cout << "Thank you for using our Service!!" << endl;
    }
}