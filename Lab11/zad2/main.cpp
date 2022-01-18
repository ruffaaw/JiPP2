#include <iostream>
#include <memory>
using namespace std;

class MyTheBestClass {
public:
    MyTheBestClass() {
        cout<< "Hello, I'm MyTheBestClass constructor" << endl;
    }

    ~MyTheBestClass() {
        cout<< "Hello, I'm MyTheBestClass destructor" << endl;
    }

    void function() {
        cout<< "Hello, I'm MyTheBestClass method" << endl;
    }
};

int main() {
    {
        shared_ptr<MyTheBestClass> mtbc = make_shared<MyTheBestClass>();
        cout << "Shared count: " << mtbc.use_count() << endl << endl;

        shared_ptr<MyTheBestClass> mtbc_copy1 = mtbc;
        cout << "Shared count base: " << mtbc.use_count() << endl;
        cout << "Shared count copy: " << mtbc_copy1.use_count() << endl << endl;

        {
            shared_ptr<MyTheBestClass> mtbc_copy2 = mtbc;
            cout << "Shared count base: " << mtbc.use_count() << endl;
            cout << "Shared count copy1: " << mtbc_copy1.use_count() << endl;
            cout << "Shared count copy2: " << mtbc_copy2.use_count() << endl << endl;
        }
        cout << "Shared count base: " << mtbc.use_count() << endl;
        cout << "Shared count copy1: " << mtbc_copy1.use_count() << endl;
    }
    cout << "End app" << endl;
}