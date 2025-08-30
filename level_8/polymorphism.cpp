#include <iostream>
#include <string>
using namespace std;

//function overloading
int sum(int First, int Last) {
    return First + Last;
}
int sum(double First, double Last) {
    return First + Last;
}

//operator overloading
void Print() {
    int First, Last;
    string FirstName, LastName;
    FirstName = "Carlos";
    LastName = "Costa";
    First = 1000;
    Last = 1500;
    cout << FirstName + " " + LastName << "\n";
    cout << First + Last << endl;
}

//function overloading
//virtual function
class clsPerson
{

public:

    virtual  void Print()

    {
        cout << "Hi, i'm a person!\n ";

    }

};

class clsEmployee : public clsPerson
{
public:
    void Print()
    {
        cout << "Hi, I'm an Employee\n";
    }
};

