#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int ReadNumber(string Message)
{

    int Number;

    cout << Message;
    cin >> Number;

    return Number;
}

int CustomAbs(int Number)
{
    int result = 0;
    if (Number <= 0)
    {
        result = sqrt(Number * Number);
    }
    return result;
}
/*float MyABS(float Number)
{

    if (Number > 0)
        return Number;
    else
        return Number * -1;
}*/

int main()
{
    int number = ReadNumber("Enter the negative number: ");

    cout << "My abs function is: " << CustomAbs(number) << endl;
    cout << "C++ abs function is: " << abs(number) << endl;
}