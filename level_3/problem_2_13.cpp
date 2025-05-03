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

void InvertedPatternPrinter(int Num)
{

    for (int i = 1; i <= Num; i++)
    {
        for (int j = 0; j < i; j++)
        {

            cout << i;
        }
        cout << "\n";
    }
}
int main()
{
    int Number = ReadNumber("Enter the number to print: ");
    InvertedPatternPrinter(Number);
}