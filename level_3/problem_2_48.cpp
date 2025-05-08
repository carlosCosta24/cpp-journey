#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
float ReadNumber(string Message)
{

    float Number;

    cout << Message;
    cin >> Number;

    return Number;
}

int CustomFloor(float Number)
{
    int IntPart = int(Number);

    int result = 0;
    if (Number > 0)
    {
        result = IntPart;
    }
    else
    {
        result = --IntPart;
    }
    return result;
}

int main()
{
    float number = ReadNumber("Enter the number: ");

    cout << "My floor function is: " << CustomFloor(number) << endl;
    cout << "C++ floor function is: " << floor(number) << endl;
}