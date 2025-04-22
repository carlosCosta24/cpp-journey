#include <iostream>
using namespace std;

int main()
{
    string FirstName;
    string LastName;
    int Age;
    string City;
    string Country;
    float MonthlySalary;
    char Gender;
    bool IsMarried;

    // taking input from user
    cout << "Enter your name:";
    cin >> FirstName;
    cout << "Enter your last name:";
    cin >> LastName;
    cout << "Enter your age:";
    cin >> Age;
    cout << "Enter your city:";
    cin >> City;
    cout << "Enter your country:";
    cin >> Country;
    cout << "Enter your monthly salary:";
    cin >> MonthlySalary;
    cout << "Enter your gender :";
    cin >> Gender;
    cout << "Are you married (1 for yes / 0 for no ):";
    cin >> IsMarried;

    cout << "*******************************" << endl;
    cout << "Name: " << FirstName << " " << LastName << endl;
    cout << "Age: " << Age << endl;
    cout << "City: " << City << endl;
    cout << "Country: " << Country << endl;
    cout << "Monthly Salary:" << MonthlySalary << endl;
    cout << "Yearly Salary:" << MonthlySalary * 12 << endl;
    cout << "Gender: " << Gender << endl;
    cout << "Married: " << IsMarried << endl;
    cout << "*******************************" << endl;

    return 0;
}