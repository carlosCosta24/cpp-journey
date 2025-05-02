#include <iostream>
#include <cmath>
using namespace std;

int ReadNumber()
{

    int Number;

    cout << "Enter the number: ";
    cin >> Number;

    return Number;
}

bool PerfectChecker(int Num)
{
    int Sum = 0;

    for (int i = 1; i < Num; i++)
    {
        if (Num % i == 0)
            Sum += i;
    }

    return Num == Sum;
}

void PerfectPrinter(int Num)
{
    for (int i = 1; i < Num; i++)
    {

        if (PerfectChecker(i))
            cout << i << endl;
    }
}

int main()
{
    PerfectPrinter(ReadNumber());
    return 0;
}