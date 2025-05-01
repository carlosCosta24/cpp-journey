#include <iostream>
using namespace std;

int main()
{
    float length, width, area;

    cout << "Enter the length of the rectangle: ";
    cin >> length;

    cout << "Enter the width of the rectangle: ";
    cin >> width;

    area = length * width;

    cout << area << endl;
    return 0;
}