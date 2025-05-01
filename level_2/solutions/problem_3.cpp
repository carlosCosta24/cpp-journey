#include <iostream>
using namespace std;

enum enNumberType
{
    Odd = 1,
    Even = 2,
};

int ReadNumber()
{

    int Number;

    cout << "Enter the number: " << endl;
    cin >> Number;

    return Number;
}

enNumberType CheckNumberType(int Num)
{
    if (Num % 2 == 0)
        return enNumberType::Even;
    else
        return enNumberType::Odd;
}

void NumberPrinter(enNumberType NumberType)
{

    if (NumberType == enNumberType::Even)
    {
        cout << "Even number" << endl;
    }
    else
    {
        cout << "Odd number" << endl;
    }
}

int main()
{
    NumberPrinter(CheckNumberType(ReadNumber()));
    return 0;
}