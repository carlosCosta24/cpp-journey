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
    int i = 0;
    cout << "Using while loop: " << endl;
    while (i <= N)
    {
        cout << i << endl;
        i++;
    }
}

void PrintNumberToN_usingDoWhile(int N)
{

    int i = 0;
    cout << "Using do while loop: " << endl;
    do
    {
        cout << i << endl;
        i++;
    } while (i <= N);
}

void PrintNumberToN_usingFor(int N)
{

    cout << "Using for loop: " << endl;
    for (int i = 0; i <= N; i++)
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
