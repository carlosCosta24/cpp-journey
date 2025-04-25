#include <iostream>
using namespace std;

int main()
{
    float length, hight, area;

    cout << "Enter the length of the triangle: ";
    cin >> length;

    cout << "Enter the hight of the triangle: ";
    cin >> hight;

    area = (length * hight) * 0.5;

    cout << area << endl;
    return 0;
}