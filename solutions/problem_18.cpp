#include <iostream>
#include <cmath>
using namespace std;

float ReadNumbers()
{
    float Num1;

    cout << "Enter the radius length: ";
    cin >> Num1;

    return Num1;
}

float CircleAreaCalculator(float Num1)
{
    const float pi = 3.141592653589793238;

    return pi * pow(Num1, 2);
}

void ResultPrinter(float result)
{

    cout << "The Circle area is: " << result << endl;
}

int main()
{

    ResultPrinter(CircleAreaCalculator(ReadNumbers()));
    return 0;
}