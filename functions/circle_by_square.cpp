#include <iostream>
#include <cmath>
using namespace std;

float CircleArea(float length)
{
    const float pi = 3.14;

    return (pi * pow(length, 2)) / 4;
}

int main()
{

    float n1;

    cout << "Enter the length of the square: " << endl;
    cin >> n1;

    cout << "Circle area is : " << CircleArea(n1) << endl;

    return 0;
}