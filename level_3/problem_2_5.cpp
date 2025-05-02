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

void Printer(int Num)
{
    int Remainder = 0;
    while (Num > 0)
    {
        Remainder = Num % 10;
        Num /= 10;
        cout << Remainder << endl;
    }
}

int main()
{

    Printer(ReadNumber());
    return 0;
}