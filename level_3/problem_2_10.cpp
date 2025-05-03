#include <iostream>
#include <string>
using namespace std;

int ReadNumber(string Message)
{

    int Number;

    cout << Message;
    cin >> Number;

    return Number;
}

int ReverseNumber(int Num)
{
    int Reminder = 0, ReversedNumber = 0;
    while (Num > 0)
    {
        Reminder = Num % 10;
        Num /= 10;
        ReversedNumber = ReversedNumber * 10 + Reminder;
    }
    return ReversedNumber;
}

void InOrderNumberPrinter(int Num)
{
    int Reminder = 0;
    while (Num > 0)
    {
        Reminder = Num % 10;
        Num /= 10;
        cout << Reminder << endl;
    }
}

int main()
{
    int UserInput = ReadNumber("Enter a number: ");
    InOrderNumberPrinter(ReverseNumber(UserInput));
    return 0;
}