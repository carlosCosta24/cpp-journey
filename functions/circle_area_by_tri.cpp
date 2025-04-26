#include <iostream>
#include <cmath>
using namespace std;

float CircleArea(float length, float width)
{
    const float pi = 3.14;

    return pi * (pow(width, 2) / 4) * ((2 * length - width) / (2 * length + width));
}

int main()
{

    float n1, n2;

    cout << "Enter the length of the triangle: " << endl;
    cin >> n1;

    cout << "Enter the width of the triangle: " << endl;
    cin >> n2;

    cout << "Circle area is : " << CircleArea(n1, n2) << endl;

    return 0;
}