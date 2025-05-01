#include <iostream>
using namespace std;

int ReadNumbers()
{
    int Num;

    cout << "Enter the number: ";
    cin >> Num;

    return Num;
}

int PowerCalculator(int Num, int Power)
{

    int Result = 1;

    for (int i = 1; i <= Power; i++)
    {
        Result *= Num;
    }
    return Result;
}

void PrintResult(int Num)
{

    cout << PowerCalculator(Num, 2) << endl;
    cout << PowerCalculator(Num, 3) << endl;
    cout << PowerCalculator(Num, 4) << endl;
}

int main()
{

    int Num = ReadNumbers();
    PrintResult(Num);
}
