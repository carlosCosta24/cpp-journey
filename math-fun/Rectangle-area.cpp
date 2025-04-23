#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    short diagonal;
    short length;

    cout << "Enter the diagonal: ";
    cin >> diagonal;
    cout << "Enter the length: ";
    cin >> length;
    short area = length * sqrt(pow(diagonal, 2) - pow(length, 2));
    cout << "Rectangle area is: " << area << endl;
    return 0;
}