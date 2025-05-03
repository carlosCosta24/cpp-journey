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

    for (int i = Num; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}
int main()
{
    int Number = ReadNumber("Enter the number to print ");
    InvertedPatternPrinter(Number);
}