#include <iostream>
#include <cmath>
using namespace std;

float CircleArea(float length)
{
    const float pi = 3.14;

    return pow(length, 2) / (4 * pi);
}

int main()
{

    float n1;

    cout << "Enter the length of the circle: " << endl;
    cin >> n1;

    cout << "Circle area is : " << CircleArea(n1) << endl;

    return 0;
}