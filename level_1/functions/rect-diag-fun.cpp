#include <iostream>
#include <cmath>
using namespace std;

float RectArea(float length, float diagonal)
{

    return length * sqrt(pow(diagonal, 2) - pow(length, 2));
}

int main()
{

    float n1, n2;

    cout << "Enter the length of the rectangle: " << endl;
    cin >> n1;

    cout << "Enter the diagonal of the rectangle: " << endl;
    cin >> n2;

    cout << "Rectangle area is : " << RectArea(n1, n2) << endl;

    return 0;
}