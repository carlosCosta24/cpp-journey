#include <iostream>
#include <string>
using namespace std;

int ReadNumber()
{

    int Number;

    cout << "Enter the number: ";
    cin >> Number;

    return Number;
}

int NumbersSum(int Num)
{
    int Sum = 0;
    int CurrentDigit = 0;
    while (Num > 0)
    {
        CurrentDigit = Num % 10;
        Num /= 10;
        Sum += CurrentDigit;
    }
    return Sum;
}

int main()
{

    int UserNumber = ReadNumber();
    cout << NumbersSum(UserNumber) << endl;
    return 0;
}