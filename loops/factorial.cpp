#include <iostream>
using namespace std;

int Factorial(int N)
{
    int result = 1;
    if (N >= 0)
    {
        for (int i = N; i >= 1; i--)
        {
            result *= i;
        }
    }
    else
    {
        cout << "the number must be greater than 0 ";
    }
    return result;
}

int main()
{
    int Number;

    cout << "Enter the number: ";
    cin >> Number;

    cout << "The factorial is: " << Factorial(Number) << endl;
}