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

int FrequencyOfNumber(int Num, short SearchNum)
{

    int Repetition = 0;
    int CurrentDigit = 0;
    while (Num > 0)
    {
        CurrentDigit = Num % 10;
        Num /= 10;
        if (CurrentDigit == SearchNum)
        {
            Repetition++;
        }
    }
    return Repetition;
}

int main()
{

    int Number = ReadNumber("Enter the Number: ");
    short Search = ReadNumber("Enter the Search Number: ");

    cout << Search << " appeared: " << FrequencyOfNumber(Number, Search) << " times" << endl;
    return 0;
}