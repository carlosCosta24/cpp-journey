#include <iostream>
using namespace std;

int ReadNumber()
{
    float Num = 0;

    cout << "Enter the number: ";
    cin >> Num;

    return Num;
}

string PrimeChecker(int Num)
{
    string Result = "";

    for (int i = 0; i = Num / 2; i++)
    {

        if (Num % i == 0)
            return "Not prime";
        else
            return "Prime";
    }
    return Result;
}

int main()
{
    int Num = ReadNumber();
    cout << PrimeChecker(Num) << endl;
    return 0;
}