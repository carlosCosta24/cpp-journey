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

float GetFractionPart(float Number)
{
    return Number - int(Number);
}

int CustomCeil(float Number)
{
    int IntPart = int(Number);

    int result = 0;

    if (abs(GetFractionPart(Number)) > 0)
    {
        if (Number > 0)
            result = ++IntPart;
        else
            result = IntPart;
    }
    else
    {
        result = Number;
    }
    return result;
}

int main()
{
    float number = ReadNumber("Enter the number: ");

    cout << "My ceil function is: " << CustomCeil(number) << endl;
    cout << "C++ ceil  function is: " << ceil(number) << endl;
}