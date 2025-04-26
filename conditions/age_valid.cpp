#include <iostream>
using namespace std;

int main()
{

    short age;

    cout << "Enter your age: " << endl;
    cin >> age;

    if (age >= 18 && age <= 45)
    {
        cout << "valid age !" << endl;
    }
    else
    {
        cout << "invalid age!" << endl;
    }
}