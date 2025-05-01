#include <iostream>
using namespace std;

int ReadCommission()
{
    int Num;

    cout << "Enter the total sales: ";
    cin >> Num;

    return Num;
}

float GetCommissionPercentage(float TotalSales)
{
    if (TotalSales >= 1000000)
    {
        return 0.01;
    }
    else if (TotalSales <= 1000000 && TotalSales >= 500000)
    {
        return 0.02;
    }
    else if (TotalSales <= 500000 && TotalSales >= 100000)
    {
        return 0.03;
    }
    else if (TotalSales <= 100000 && TotalSales >= 50000)
    {
        return 0.05;
    }
    else
    {
        return 0;
    }
}

float CalculateTotalCommission(float TotalSales)
{
    return TotalSales * GetCommissionPercentage(TotalSales);
}
int main()
{

    float TotalSales = ReadCommission();

    cout << "Your commission percentage: " << GetCommissionPercentage(TotalSales) << endl;

    cout << "Your commission is: " << CalculateTotalCommission(TotalSales) << endl;

    return 0;
}