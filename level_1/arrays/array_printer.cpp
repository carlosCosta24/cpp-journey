#include <iostream>
using namespace std;

struct stPersonInfo
{
    string FirstName;
    string LastName;
    string Phone;
    short Age;
};
void PersonReader(stPersonInfo &Info)
{
    cout << "Enter your firstName: ";
    cin >> Info.FirstName;

    cout << "Enter your LastName: ";
    cin >> Info.LastName;

    cout << "Enter your Phon number: ";
    cin >> Info.Phone;

    cout << "Enter your Age: ";
    cin >> Info.Age;
}
void PersonPrinter(stPersonInfo Info)
{
    cout << "**************************************" << endl;
    cout << "firstName: " << Info.FirstName << endl;

    cout << "LastName: " << Info.LastName << endl;

    cout << "Phon number: " << Info.Phone << endl;

    cout << "Age: " << Info.Age << endl;
    cout << "**************************************" << endl;
}

void StructReader(stPersonInfo persons[2])
{
    PersonReader(persons[0]);
    PersonReader(persons[1]);
}
void StructPrinter(stPersonInfo persons[2])
{
    PersonPrinter(persons[0]);
    PersonPrinter(persons[1]);
}

int main()
{

    stPersonInfo persons[2];

    PersonReader(persons[0]);
    PersonReader(persons[1]);
    StructPrinter(persons);
    return 0;
}