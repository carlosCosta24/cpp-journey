#include <iostream>
using namespace std;

int main()
{
    const float pi = 3.14;
    short length;

    cout << "Enter the length: ";
    cin >> length;

    float area = (pi * (length * length)) / 4;
    cout << "circle area is: " << area << endl;

    return 0;
}