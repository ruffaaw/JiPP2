#include "../include/finalize.h"

Finalize::Finalize() {}

Finalize::~Finalize() {}

void Finalize::finalize()
{
    time_t now = time(0);
    char *dt = ctime(&now);
    Customer::working();
    Customer::customerData();
    if (Customer::returnAuthorized())
    {
        Payment::showItems(username);
        Payment::showCosts();
        Payment::agrii();
    }
    if (done)
    {
        cout << endl;
        cout << "Your Order Number is: " << OrderNumber << endl;
        cout << endl;
        cout << "Your Total Cost is: " << totalCost << "$" << endl;

        cout << "Your Order will be delivered soon to you at address: " << address << endl;
        cout << endl;
        cout << "For any compliance call us on +923223132233." << endl;

        cout << "Your Order Placed on local date and time: " << dt << endl;
        cout << endl;
        // writing the whole data into the file for record;

        ofstream fout;
        fout.open("RECORDS.txt", ios::app);

        fout << "===================================================\n";
        fout << "User: " << username << "\n";
        fout << "User Record ID: " << number << "\n";
        fout << "Order Number: " << OrderNumber << "\n";
        fout << "\n";
        fout << "Item\t\t"
             << "Price/Each\t\t"
             << "Total" << endl;
        for (int i = 0; i < customerList.size(); i++)
        {
            for (int j = 0; j < 3; j++)
            {
                fout << customerList[i][j] << "\t\t";
            }
            fout << endl;
        }
        fout << endl;

        fout << "Address: " << address << "\n";
        fout << "Payment Method: " << paymentMethod << "\n";

        fout << "The local date and time: " << dt << endl;
        fout << "\n";

        fout.close();
    }
}