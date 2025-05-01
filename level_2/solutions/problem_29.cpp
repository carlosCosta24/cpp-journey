#include <iostream>
using namespace std;

enum enOddOrEven
{
    Odd,
    Even,
};
int ReadNumber()
{
    int Num;

    cout << "Enter the number: ";
    cin >> Num;

    return Num;
}

enOddOrEven Checker(int Num)
{
    if (Num % 2 == 0)
        return enOddOrEven::Even;

    else
        return enOddOrEven::Odd;
}

int CalculateSum(int Num)
{
    int Sum = 0;

    for (int i = 0; i <= Num; i++)
    {
        if (Checker(i) == enOddOrEven::Even)
        {
            Sum += i;
        }
    }

    return Sum;
}

void ResultPrinter(int Result)
{
    cout << "the sum of odd numbers is: " << Result << endl;
}

int main()
{
    int Num = ReadNumber();

    ResultPrinter(CalculateSum(Num));

    return 0;
}
