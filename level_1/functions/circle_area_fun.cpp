#include <iostream>
#include <cmath>
using namespace std;

float CircleArea(float radius)
{
    const float pi = 3.14;

    return pi * pow(radius, 2);
}

int main()
{

    float n1;

    cout << "Enter the radius of the circle: " << endl;
    cin >> n1;

    cout << "Circle area is : " << CircleArea(n1) << endl;

    return 0;
}