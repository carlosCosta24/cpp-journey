#include <iostream>
#include <cmath>
using namespace std;

int ReadNumber()
{

    int Number;

    cout << "Enter the number: " << endl;
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
    if (PerfectChecker(Num))
        cout << Num << " is a perfect number. " << endl;
    else
        cout << Num << " is't a perfect number. " << endl;
}

int main()
{
    PerfectPrinter(ReadNumber());
    return 0;
}
