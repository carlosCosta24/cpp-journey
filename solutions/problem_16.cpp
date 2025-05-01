#include <iostream>
#include <cmath>
using namespace std;

void ReadNumbers(float &Num1, float &Num2)
{

    cout << "Enter the number side length: ";
    cin >> Num1;

    cout << "Enter the number diagonal: ";
    cin >> Num2;
}

float RectAreaCalculator(float Num1, float Num2)
{

    return (Num1 * sqrt(pow(Num2, 2) - pow(Num1, 2)));
}

void ResultPrinter(float result)
{

    cout << "The Rectangle area is: " << result << endl;
}

int main()
{
    float Num1, Num2;
    ReadNumbers(Num1, Num2);
    ResultPrinter(RectAreaCalculator(Num1, Num2));
    return 0;
}