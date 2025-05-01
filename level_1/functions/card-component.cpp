#include <iostream>
using namespace std;

struct strId
{
    string name;
    short age;
    string city;
    string country;
    double monthly_salary;
    double yearly_salary;
    char gender;
    bool is_married;
};
void ReadId(strId &Id)
{
    cout << "Enter your Name: ";
    cin.ignore(1, '\n');
    getline(cin, Id.name);

    cout << "Enter your Age: ";
    cin >> Id.age;

    cout << "Enter your City: ";
    cin.ignore(1, '\n');
    getline(cin, Id.city);

    cout << "Enter your country: ";
    cin.ignore(1, '\n');
    getline(cin, Id.country);

    cout << "Enter your Monthly salary: ";
    cin >> Id.monthly_salary;

    cout << "Enter your Yearly salary: ";
    cin >> Id.yearly_salary;

    cout << "Enter your Gender(M/F): ";
    cin >> Id.gender;

    cout << "Enter your Marital status(0:single / 1:married): ";
    cin >> Id.is_married;
}
void PrintId(strId Id)

{
    cout << "*********************************" << endl;
    cout << "name: " << Id.name << endl;
    cout << "age: " << Id.age << endl;
    cout << "city: " << Id.city << endl;
    cout << "country: " << Id.country << endl;
    cout << "monthly_salary: " << Id.monthly_salary << endl;
    cout << "yearly_salary: " << Id.yearly_salary << endl;
    cout << "gender: " << Id.gender << endl;
    cout << "is_married: " << Id.is_married << endl;
    cout << "*********************************" << endl;
}

int main()
{

    strId person;
    ReadId(person);
    PrintId(person);
}