#include <iostream>
#include <cmath>
using namespace std;

void ReadNumber(float &Num1, float &Num2)
{

    cout << "Enter the length: ";
    cin >> Num1;

    cout << "Enter the base: ";
    cin >> Num2;
}

float CircleAreaCalculator(float Num1, float Num2)
{
    const float pi = 3.141592653589793238;

    float area = pi * (pow(Num2, 2) / 4) * ((2 * Num1 - Num2) / (2 * Num1 + Num2));

    return area;
}

void ResultPrinter(float result)
{

    cout << "The Circle area is: " << result << endl;
}

int main()
{
    float Num1, Num2;

    ReadNumber(Num1, Num2);
    ResultPrinter(CircleAreaCalculator(Num1, Num2));

    return 0;
}