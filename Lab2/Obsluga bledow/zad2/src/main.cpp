#include <iostream>
#include <string>
#include <stdexcept> //biblioteka zawierajaca rozne typy bledow

using namespace std;

int main()
{
    string value;
    int converted_value;

    cout << "Podaj liczbe ktora chcesz zamienic na int:" << endl;
    cin >> value;

    try
    {
        converted_value = stoi(value);
        cout << converted_value << endl;
    }
    catch(std::invalid_argument& e)
    {
        cout << "Zostal wprowadzon niewlasciwy" << endl;
    }
    catch(std::out_of_range& e)
    {
        cout << "Podana wartosc jest za duza" << endl;
    }

    return 0;
}

