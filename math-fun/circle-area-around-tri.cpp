#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    double a, b, c;
    const float pi = 3.14;
    float area;
    float p;

    cout << "Enter the first value: ";
    cin >> a;
    cout << "Enter the second value: ";
    cin >> b;
    cout << "Enter the third value: ";
    cin >> c;
    p = (a + b + c) / 2;
    area = pi * pow(((a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c)))), 2);
    cout << "The area is: " << area << endl;
    return 0;
}