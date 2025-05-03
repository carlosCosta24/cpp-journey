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

void FrequencyPrinter(int Num)
{
    for (int i = 0; i <= 10; i++)
    {
        short DigitFrequency = 0;
        DigitFrequency = FrequencyOfNumber(Num, i);
        if (DigitFrequency > 0)
        {

            cout << "Digit " << i << " Frequency is: " << DigitFrequency << " Times" << endl;
        }
    }
}

int main()
{

    int Number = ReadNumber("Enter the Number: ");
    FrequencyPrinter(Number);

    return 0;
}