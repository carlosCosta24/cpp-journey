#include <iostream>
#include <cmath>
using namespace std;

enum enPrinme
{
    prinme = 1,
    NotPrime = 2,
};

int ReadNumber(string Message)
{
    float Num = 0;
    do
    {
        cout << Message;
        cin >> Num;
    } while (Num <= 0);

    return Num;
}

enPrinme PrimeChecker(int Num)
{
    int M = round(Num / 2);

    for (int i = 2; i <= M; i++)
    {

        if (Num % i == 0)
            return enPrinme::NotPrime;
    }
    return enPrinme::prinme;
}

void PrintNumType(int Num)
{
    cout << "prime number from 1 to " << Num << endl;
    for (int i = 1; i <= Num; i++)
    {
        if (PrimeChecker(i) == enPrinme::prinme)
            cout << i << endl;
    }
}
int main()
{
    PrintNumType(ReadNumber("Enter a positive Number: "));
    return 0;
}