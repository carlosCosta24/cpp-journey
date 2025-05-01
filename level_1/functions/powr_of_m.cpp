#include <iostream>
#include <cmath>
using namespace std;

double PowerOfM(double num, double m)
{
    return pow(num, m);
}
int main()
{
    double num, m;

    cout << "Enter the number: ";
    cin >> num;

    cout << "Enter the desired power: ";
    cin >> m;

    cout << PowerOfM(num, m) << endl;
}