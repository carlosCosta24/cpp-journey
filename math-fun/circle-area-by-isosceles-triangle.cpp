#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double length;
    double side;
    const float pi = 3.14;

    cout << "Enter the length: ";
    cin >> length;
    cout << "Enter the side: ";
    cin >> side;
    double area = pi * (pow(side, 2) / 4) * ((2 * length - side) / (2 * length + side));
    cout << "circle area is: " << area << endl;
    return 0;
}