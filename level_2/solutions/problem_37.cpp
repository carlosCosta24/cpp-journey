#include <iostream>
using namespace std;

int ReadNumber()
{
    float Num = 0;

    cout << "Enter the number to add, -99 to exit and print: ";
    cin >> Num;

    return Num;
}

int Calculator()
{
    int Sum = 0, Num = 0;

    while (Num != -99)
    {
        Sum += Num;

        Num = ReadNumber();
    };

    return Sum;
}

int main()
{

    cout << Calculator() << endl;

    return 0;
}