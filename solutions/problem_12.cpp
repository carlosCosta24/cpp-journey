#include <iostream>
using namespace std;

void ReadNumbers(int &Num1, int &Num2)
{

    cout << "Enter the number firstnumber: ";
    cin >> Num1;

    cout << "Enter the number secondnumber: ";
    cin >> Num2;
}

int CheckMax(int Num1, int Num2)
{
    if (Num1 > Num2)
        return Num1;
    else
        return Num2;
}

void ResultPrinter(int max)
{

    cout << "The max number is: " << max << endl;
}

int main()
{
    int Num1, Num2;
    ReadNumbers(Num1, Num2);
    ResultPrinter(CheckMax(Num1, Num2));
}