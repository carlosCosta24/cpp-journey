#include <iostream>
using namespace std;

float RectArea(float length, float width)
{

    return length * width;
}

int main()
{

    float n1, n2;

    cout << "Enter the length of the rectangle: " << endl;
    cin >> n1;

    cout << "Enter the width of the rectangle: " << endl;
    cin >> n2;

    cout << "Rectangle area is : " << RectArea(n1, n2) << endl;

    return 0;
}