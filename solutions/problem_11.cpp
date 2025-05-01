#include <iostream>
using namespace std;

enum enStatus
{
    pass,
    fail
};

void ReadNumbers(int &Num1, int &Num2, int &Num3)
{

    cout << "Enter the number firstnumber: ";
    cin >> Num1;

    cout << "Enter the number secondnumber: ";
    cin >> Num2;

    cout << "Enter the number therednumber: ";
    cin >> Num3;
}

int SumOfThree(int Num1, int Num2, int Num3)
{
    return Num1 + Num2 + Num3;
}

float AvgCalculator(int Num1, int Num2, int Num3)
{
    return (float)SumOfThree(Num1, Num2, Num3) / 3;
}

enStatus CheckAvg(float avg)
{

    if (avg >= 50)
        return enStatus::pass;
    else
        return enStatus::fail;
}
void ResultPrinter(float result)
{
    cout << "Your average is: " << result << endl;
    if (CheckAvg(result) == enStatus::pass)
        cout << "You passed!" << endl;
    else
        cout << "Your failed" << endl;
}

int main()
{
    int Num1, Num2, Num3;
    ReadNumbers(Num1, Num2, Num3);
    ResultPrinter(AvgCalculator(Num1, Num2, Num3));
    return 0;
}