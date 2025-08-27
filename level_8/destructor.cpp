#include <iostream>
using namespace std;

class clsPerson {
    public:
        string FullName;
        //this is the constructor
        clsPerson() {
            FullName = "Carlos costa";
            cout << "FullName: " << FullName << endl;
        }
        //this is the destructor, will be called when object is destroyed
        ~clsPerson() {
            cout << "chau" << endl;
        }
};

void TestFunction() {
    clsPerson FirstPerson;
    //after executing this func, the FirstPerson class will be destroyed
    //and destructor will be called
}

void PointerFunction() {
    // always be careful when using new keyword (pointers)
    // make sure to delete them, otherwise it will remain in the memory
    clsPerson* SecPerson = new clsPerson;
    delete SecPerson;
}

int main() {
    TestFunction();
    PointerFunction();
    return 0;
}