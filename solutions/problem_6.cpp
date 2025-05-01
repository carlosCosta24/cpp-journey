#include <iostream>
using namespace std;

struct stPersons
{
    string FirstName;
    string LastName;
};

stPersons ReadPersonDate()
{

    stPersons Person;

    cout << "Enter your firstname: " << endl;
    cin >> Person.FirstName;

    cout << "Enter your lastname: " << endl;
    cin >> Person.LastName;

    return Person;
}

string GetFullName(stPersons person)
{
    string FullName = "";
    FullName = person.FirstName + " " + person.LastName;
    return FullName;
}
void PrintFullName(string Name)

{
    cout << "****************************************:" << endl;

    cout << "FullName is:" << Name << endl;

    cout << "****************************************:" << endl;
}

int main()
{
    PrintFullName(GetFullName(ReadPersonDate()));
}
