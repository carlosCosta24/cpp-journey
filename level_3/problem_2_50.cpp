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
int MySqrt(int Number)
{
    return pow(Number, 0.5);
}

int main()
{
    int Number = ReadNumber("Enter the number to get the square root: ");

    cout << "My square root function result: " << MySqrt(Number) << endl;
    cout << "C++ square root function result: " << sqrt(Number) << endl;
}