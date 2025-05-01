#include <iostream>
using namespace std;

int ReadNumber()
{
    int Num;

    cout << "Enter the number: ";
    cin >> Num;

    return Num;
}

void PrintNumberToN_usingWhile(int N)
{
    int i = N;
    cout << "Using while loop: " << endl;
    while (i > 0)
    {
        cout << i << endl;
        i--;
    }
}

void PrintNumberToN_usingDoWhile(int N)
{

    int i = N;
    cout << "Using do while loop: " << endl;
    do
    {
        i--;
        cout << i << endl;
    } while (i > 0);
}

void PrintNumberToN_usingFor(int N)
{

    cout << "Using for loop: " << endl;
    for (int i = N; i > 0; i--)
    {
        cout << i << endl;
    }
}

int main()
{
    int N = ReadNumber();

    PrintNumberToN_usingDoWhile(N);
    PrintNumberToN_usingWhile(N);
    PrintNumberToN_usingFor(N);
    return 0;
}
