#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const float pi = 3.14;
    short diagonal;

    cout << "Enter the diagonal: ";
    cin >> diagonal;
    float area = (pi * pow(diagonal, 2)) / 4;
    cout << "circle area is: " << area << endl;
    return 0;
}