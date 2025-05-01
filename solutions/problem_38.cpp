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
        cout << Message << endl;
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
    switch (PrimeChecker(Num))
    {
    case enPrinme::prinme:
        cout << "Prime number!" << endl;
        break;

    case enPrinme::NotPrime:
        cout << "Not a prime number!" << endl;
        break;
    }
}
int main()
{
    PrintNumType(ReadNumber("Enter a positive Number: "));
    return 0;
}