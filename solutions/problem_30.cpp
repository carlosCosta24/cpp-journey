#include <iostream>
using namespace std;

int ReadPositiveNumber()
{
    int Num;

    do
    {

        cout << "Enter the number: ";
        cin >> Num;
    } while (Num < 0);

    return Num;
}

int CalculateFactorial(int Num)
{
    int Sum = 1;

    for (int i = Num; i >= 1; i--)
    {

        Sum *= i;
    }

    return Sum;
}

void ResultPrinter(int Result)
{
    cout << "the factorial is: " << Result << "!" << endl;
}

int main()
{
    int Num = ReadPositiveNumber();
    ResultPrinter(CalculateFactorial(Num));
}
