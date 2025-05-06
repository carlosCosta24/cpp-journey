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

float CustomRound(int Number)
{
    int result = 0;
    int Decimal = Number % 1;

    if (Decimal >= 5)
    {
        if (Number < 0)
            result = Number - 1;
        result = Number + 1;
    }
    else
    {
        result = Number - Decimal;
    }
    return result;
}

int main()
{
    int number = ReadNumber("Enter the negative number: ");

    cout << "My round function is: " << CustomRound(number) << endl;
    cout << "C++ round function is: " << round(number) << endl;
}