#include <iostream>
#include <cmath>
using namespace std;

void ReadNumber(float &Num1, float &Num2, float &Num3)
{

    cout << "Enter the length: ";
    cin >> Num1;

    cout << "Enter the base: ";
    cin >> Num2;

    cout << "Enter the diagonal: ";
    cin >> Num3;
}

float CircleAreaCalculator(float Num1, float Num2, float Num3)
{
    const float pi = 3.141592653589793238;

    float p = (Num1 + Num2 + Num3) / 2;

    float area = pi * pow(((Num1 * Num2 * Num3) / (4 * sqrt(p * (p - Num1) * (p - Num2) * (p - Num3)))), 2);

    return area;
}

void ResultPrinter(float result)
{

    cout << "The Circle area is: " << result << endl;
}

int main()
{
    float Num1, Num2, Num3;

    ReadNumber(Num1, Num2, Num3);
    ResultPrinter(CircleAreaCalculator(Num1, Num2, Num3));

    return 0;
}