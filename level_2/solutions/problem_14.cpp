#include <iostream>
using namespace std;

void ReadNumbers(int &Num1, int &Num2)
{

    cout << "Enter the number firstnumber: ";
    cin >> Num1;

    cout << "Enter the number secondnumber: ";
    cin >> Num2;
}

void NumberSwapper(int &Num1, int &Num2)
{

    int Temp = Num1;
    Num1 = Num2;
    Num2 = Temp;
}

void ResultPrinter(int Num1, int Num2)
{

    cout << "Number one is: " << Num1 << " and number tow is: " << Num2 << endl;
}
int main()
{
    int Num1, Num2;

    ReadNumbers(Num1, Num2);
    ResultPrinter(Num1, Num2);
    NumberSwapper(Num1, Num2);
    ResultPrinter(Num1, Num2);
    return 0;
}