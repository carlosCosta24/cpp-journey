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

int NumberReverser(int Num)
{
    int Reversed = 0;
    int CurrentDigit = 0;
    while (Num > 0)
    {
        CurrentDigit = Num % 10;
        Num /= 10;
        Reversed = Reversed * 10 + CurrentDigit;
    }
    return Reversed;
}

int main()
{

    int UserNumber = ReadNumber();
    cout << "Reversed Number Is: " << NumberReverser(UserNumber) << endl;
    return 0;
}