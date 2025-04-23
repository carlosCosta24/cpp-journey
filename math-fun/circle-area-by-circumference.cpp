#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const float pi = 3.14;
    short length;

    cout << "Enter the length: ";
    cin >> length;
    float area = pow(length, 2) / (4 * pi);
    cout << "circle area is: " << area << endl;
    return 0;
}