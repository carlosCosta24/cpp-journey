#include <iostream>
#include <cmath>
using namespace std;

double PowerOf(double num, double power)
{
    return pow(num, power);
}
int main()
{
    double num;

    cout << "Enter the number: ";
    cin >> num;

    cout << PowerOf(num, 2) << endl;
    cout << PowerOf(num, 3) << endl;
    cout << PowerOf(num, 4) << endl;
}
