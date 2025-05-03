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

void PalindromePrinter(int Num)
{
    if (Num == ReverseNumber(Num))
        cout << "Yes, it's a palindrome number!!" << endl;

    else
        cout << "No, it's not a palindrome " << endl;
}

int main()
{
    int UserInput = ReadNumber("Enter a number: ");
    PalindromePrinter(UserInput);
    return 0;
}