#include <iostream>
using namespace std;

struct strInfo
{
    string FirstName;
    string LastName;
    short Age;
    string Phone;
};

void ReadInfo(strInfo &Info)
{
    cout << "Enter your firstName: ";
    cin >> Info.FirstName;

    cout << "Enter your LastName: ";
    cin >> Info.LastName;

    cout << "Enter your Age: ";
    cin >> Info.Age;

    cout << "Enter your Phon number: ";
    cin >> Info.Phone;
}

void PrintInfo(strInfo Info)
{
    cout << "\n*************************************\n";
    cout << "FirstName: " << Info.FirstName << endl;
    cout << "LastName: " << Info.LastName << endl;
    cout << "Age: " << Info.Age << endl;
    cout << "Phone: " << Info.Phone << endl;
    cout << "*************************************\n";
}

int main()
{

    strInfo carlos;
    ReadInfo(carlos);
    PrintInfo(carlos);
    return 0;
}