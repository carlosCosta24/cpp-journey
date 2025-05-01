#include <iostream>
using namespace std;

void ReadNumbers(float &Num1, float &Num2)
{

    cout << "Enter the number firstnumber: ";
    cin >> Num1;

    cout << "Enter the number secondnumber: ";
    cin >> Num2;
}

float RectAreaCalculator(float Num1, float Num2)
{

    return (float)Num1 * Num2;
}

void ResultPrinter(float result)
{

    cout << "The rectangle area is: " << result << endl;
}

int main()
{
    float Num1, Num2;
    ReadNumbers(Num1, Num2);
    ResultPrinter(RectAreaCalculator(Num1, Num2));
    return 0;
}