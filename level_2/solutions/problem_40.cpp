#include <iostream>
using namespace std;

float ReadNumbers(string Message)
{
    float Num;

    cout << Message;
    cin >> Num;

    return Num;
}

float ServiceCalculator(float Num)
{
    float total = Num * 1.10;
    return total;
}

float TotalBillAmount(float Num)
{
    float Final = Num * 1.16;
    return Final;
}

int main()
{
    float Cost = ReadNumbers("Enter the Bill value:");

    float Total = TotalBillAmount(ServiceCalculator(Cost));

    cout << "Total to pay is:" << Total << endl;
}