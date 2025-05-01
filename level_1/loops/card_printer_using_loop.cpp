#include <iostream>
using namespace std;

struct stPerson
{
    string FirstName;
    string LastName;
    short Age;
    string Phone;
};

void ReadPerson(stPerson &Info)
{
    cout << "Please enter FirstName?\n";
    cin >> Info.FirstName;

    cout << "Please enter LastName?\n";
    cin >> Info.LastName;

    cout << "Please enter Age?\n";
    cin >> Info.Age;

    cout << "Please enter Phone?\n";
    cin >> Info.Phone;
}

void PrintPerson(stPerson Info)
{
    cout << "\n**********************************\n";

    cout << "FirstName: " << Info.FirstName << endl;
    cout << "LastName: " << Info.LastName << endl;
    cout << "Age: " << Info.Age << endl;
    cout << "Phone: " << Info.Phone << endl;

    cout << "\n**********************************\n";
}

void ReadPersonsInfo(stPerson Persons[100], int length)

{
    for (int i = 0; i <= length - 1; i++)
    {
        cout << "Please enter the person's " << i + 1 << " info" << endl;
        ReadPerson(Persons[i]);
    }
}
void PrintPersonsInfo(stPerson persons[100], int length)
{
    cout << "\n**********************************\n";
    for (int i = 0; i <= length - 1; i++)
    {
        cout << "person's " << i + 1 << " info" << endl;
        PrintPerson(persons[i]);
    }
}
int main()
{
    int length = 0;
    stPerson Persons[100];

    cout << "Enter number of persons (1 - 100); ";
    cin >> length;

    ReadPersonsInfo(Persons, length);
    PrintPersonsInfo(Persons, length);

    return 0;
}