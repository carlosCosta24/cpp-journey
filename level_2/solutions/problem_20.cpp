#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber()
{
    float Num1;

    cout << "Enter the length of square side: ";
    cin >> Num1;

    return Num1;
}

float CircleAreaCalculator(float Num1)
{
    const float pi = 3.141592653589793238;

    float area = (pi * pow(Num1, 2)) / 4;

    return area;
}

void ResultPrinter(float result)
{

    cout << "The Circle area is: " << result << endl;
}

int main()
{

    ResultPrinter(CircleAreaCalculator(ReadNumber()));
    return 0;
}