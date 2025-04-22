#include <iostream>
using namespace std;

int main()
{
    // FIRST PART
    string FullName = "carlos costa";
    int Age = 26;
    string City = "Aracaju";
    string Country = "Brazil";
    float MonthlySalary = 10000;
    char Gender = 'M';
    bool IsMarried = false;

    cout << "*******************************" << endl;
    cout << "Name: " + FullName << endl;
    cout << "Age: " << Age << " years" << endl;
    cout << "City: " << City << endl;
    cout << "Country: " << Country << endl;
    cout << "Monthly Salary: " << MonthlySalary << endl;
    cout << "Yearly Salary: " << MonthlySalary * 12 << endl;
    cout << "Gender: " << Gender << endl;
    cout << "Married: " << IsMarried << endl;
    cout << "*******************************" << endl;

    // second part
    int twenty = 20;
    int thirty = 30;
    int ten = 10;

    cout << "20 + \n";
    cout << "30 + \n";
    cout << "10 \n";
    cout << "______________________________\n\n";
    cout << "total = " << twenty + thirty + ten << endl
         << endl;

    // third part

    int _Age = 25;
    cout << "After 5 years you will be " << _Age + 5 << " years old." << endl;

    return 0;
}