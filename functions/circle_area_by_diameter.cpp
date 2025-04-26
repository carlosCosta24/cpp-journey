#include <iostream>
#include <cmath>
using namespace std;

float CircleArea(float diameter)
{
    const float pi = 3.14;

    return (pi * pow(diameter, 2)) / 4;
}

int main()
{

    float n1;

    cout << "Enter the diameter of the circle: " << endl;
    cin >> n1;

    cout << "Circle area is : " << CircleArea(n1) << endl;

    return 0;
}