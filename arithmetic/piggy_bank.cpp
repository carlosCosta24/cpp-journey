#include <iostream>
using namespace std;

int main()
{
    int penny, nickel, dime, quarter, dollar;

    cout << "Enter the number of pennies: ";
    cin >> penny;

    cout << "Enter the number of nickel: ";
    cin >> nickel;

    cout << "Enter the number of dime: ";
    cin >> dime;

    cout << "Enter the number of quarter: ";
    cin >> quarter;

    cout << "Enter the number of dollar: ";
    cin >> dollar;

    float pennies = penny + (nickel * 5) + (dime * 10) + (quarter * 25) + (dollar * 100);
    float dollars = pennies / 100;

    cout << "******************************" << endl;

    cout << pennies << " pennies" << endl;
    cout << dollars << " dollars" << endl;

    cout << "******************************" << endl;

    return 0;
}