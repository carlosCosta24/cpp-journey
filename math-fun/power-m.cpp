#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    short num, power;

    cout << "Enter a number: ";
    cin >> num;
    cout << "Enter the power: ";
    cin >> power;
    cout << pow(num, power) << endl;

    return 0;
}