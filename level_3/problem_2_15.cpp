#include <iostream>
#include <string>
using namespace std;

int ReadNumber(string Message)
{

    int Number;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number < 1 || Number > 26);

    return Number;
}

void PatternPrinter(int Num)
{
    for (int i = 65; i <= 65 + Num - 1; i++)
    {
        for (int j = 1; j <= i - 65 + 1; j++)
        {
            cout << char(i);
        }
        cout << endl;
    }
}
int main()
{
    int Number = ReadNumber("Enter the number to print(1-26): ");
    PatternPrinter(Number);
}