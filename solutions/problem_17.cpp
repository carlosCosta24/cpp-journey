#include <iostream>
#include <cmath>
using namespace std;

void ReadNumbers(float &Num1, float &Num2)
{

    cout << "Enter the base length: ";
    cin >> Num1;

    cout << "Enter the hight length: ";
    cin >> Num2;
}

float TriAreaCalculator(float Num1, float Num2)
{

    return 0.5 * Num1 * Num2;
}

void ResultPrinter(float result)
{

    cout << "The Triangle area is: " << result << endl;
}

int main()
{
    float Num1, Num2;
    ReadNumbers(Num1, Num2);
    ResultPrinter(TriAreaCalculator(Num1, Num2));
    return 0;
}