#include <iostream>
using namespace std;

void ReadNumbers(int &Num1, int &Num2, int &Num3)
{

    cout << "Enter the number firstnumber: ";
    cin >> Num1;

    cout << "Enter the number secondnumber: ";
    cin >> Num2;

    cout << "Enter the number therednumber: ";
    cin >> Num3;
}

int CheckMax(int Num1, int Num2, int Num3)
{
    if (Num1 > Num2)
    {

        if (Num1 > Num3)
            return Num1;
        else
            return Num3;
    }
    else
    {
        if (Num2 > Num3)
            return Num2;
        else
            return Num3;
    }
}

void ResultPrinter(int max)
{

    cout << "The max number is: " << max << endl;
}

int main()
{
    int Num1, Num2, Num3;
    ReadNumbers(Num1, Num2, Num3);
    ResultPrinter(CheckMax(Num1, Num2, Num3));
}