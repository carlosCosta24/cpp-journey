#include <iostream>
using namespace std;

class clsPerson {
    public:
    string FUllName = "Carlos costa";
};

class clsEmployee: public clsPerson{
    public:
    string Title = "junior SWE";
};

int main() {
    clsEmployee employee ;

    cout <<"From the class: " <<employee.FUllName<< endl;

    //upcasting

    clsPerson * Person1 = &employee;
    cout <<"from upcasting: " <<Person1->FUllName<< endl;

    //clsPerson Person2;//
    //cout << Person2.FullName << endl;
    //downcasting : you cannot convert person to employee

    //clsEmployee* Employee2 = &Person1;

    return 0;


}