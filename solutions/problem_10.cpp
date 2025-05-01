#include <iostream>
using namespace std;

void ReadNumbers(int &Num1, int &Num2, int &Num3)
{

    cout << "Enter the number firstnumber" << endl;
    cin >> Num1;

    cout << "Enter the number secondnumber: " << endl;
    cin >> Num2;

    cout << "Enter the number therednumber: " << endl;
    cin >> Num3;
}

int SumOfThree(int Num1, int Num2, int Num3)
{
    return Num1 + Num2 + Num3;
}

float AvgCalculator(int Num1, int Num2, int Num3)
{
    return (float)SumOfThree(Num1, Num2, Num3) / 3;
}

void ResultPrinter(float result)
{
    cout << "The average is: " << result << endl;
}

int main()
{
    int Num1, Num2, Num3;
    ReadNumbers(Num1, Num2, Num3);
    ResultPrinter(AvgCalculator(Num1, Num2, Num3));
    return 0;
}