#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct stClint {
    string AccountNumber;
    string Pin;
    string Name;
    string Phone;
    double Amount;
};

stClint Filler() {
    stClint stNewClint;
    cout<< "Please enter account Data\n"<< endl;
    cout<< "Enter Account Number: ";
    getline(cin, stNewClint.AccountNumber) ;

    cout<< "Enter Account Pin: ";
    getline(cin, stNewClint.Pin);

    cout<< "Enter Account Holder Name: ";
    getline(cin,stNewClint.Name) ;

    cout<< "Enter Account Holder Phone: ";
    getline(cin,stNewClint.Phone) ;

    cout<< "Enter Account Balance: ";
    cin >> stNewClint.Amount;

    return stNewClint;
}

string AccoutRecrd(stClint stClint, string Sep) {
    string AccountRecord="";

    AccountRecord+= stClint.AccountNumber + Sep;
    AccountRecord+= stClint.Pin + Sep;
    AccountRecord+= stClint.Name + Sep;
    AccountRecord+= stClint.Phone + Sep;
    AccountRecord+= to_string(stClint.Amount);

    return AccountRecord;
}

int main() {
    stClint NewClint = Filler();
    cout << AccoutRecrd(NewClint, "//")<< endl;

    return 0;

}