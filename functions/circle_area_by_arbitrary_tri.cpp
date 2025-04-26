#include <iostream>
#include <cmath>

using namespace std;

float AreaCalculator(float a, float b, float c)
{
    const float pi = 3.14;
    float p = (a + b + c) / 2;

    return pi * pow(((a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c)))), 2);
}

int main()
{

    float n1, n2, n3;

    cout << "Enter the first value: ";
    cin >> n1;

    cout << "Enter the second value: ";
    cin >> n2;

    cout << "Enter the third value: ";
    cin >> n3;

    cout << "circle area is: " << AreaCalculator(n1, n2, n3) << endl;

    return 0;
}