#include <iostream>

using namespace std;

int main() {
    try       {
        throw"tekst z obszaru try"; // wyrzuć tekst
        return 0;
    }
    catch(const char * msg) // złap wyrzucony tekst i przypisz do wskaźnika msg
    {
        cout << msg << endl;
        return 1;
    }
}