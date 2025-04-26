#include <iostream>
using namespace std;

struct stInfo
{
    string FirstName;
    string LastName;
    string Phone;
    short Age;
};

int main()
{

    stInfo persons[2];

    persons[0].FirstName = "carlos";
    persons[1].FirstName = "costa";

    cout << persons[0].FirstName << endl;
    cout << persons[1].FirstName << endl;
}