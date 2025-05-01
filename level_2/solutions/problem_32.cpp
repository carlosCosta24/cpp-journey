#include <iostream>
using namespace std;

void ReadNumbers(int &Num, int &Power)
{

    cout << "Enter the number: ";
    cin >> Num;

    cout << "Enter the power: ";
    cin >> Power;
}

int PowerCalculator(int Num, int Power)
{

    int Result = 1;

    if (Power == 0)
    {
        return 1;
    }

    for (int i = 1; i <= Power; i++)
    {
        Result *= Num;
    }

    return Result;
}

int main()
{

    int Num, Power;
    ReadNumbers(Num, Power);
    cout << PowerCalculator(Num, Power) << endl;
}