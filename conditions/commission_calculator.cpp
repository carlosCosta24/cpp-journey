#include <iostream>
using namespace std;

float CommissionChecker(float TotalSales)
{

    if (TotalSales >= 1000000)
    {
        return TotalSales * 0.01;
    }
    else if (TotalSales <= 1000000 && TotalSales >= 500000)
    {
        return TotalSales * 0.02;
    }
    else if (TotalSales <= 500000 && TotalSales >= 100000)
    {
        return TotalSales * 0.03;
    }
    else if (TotalSales <= 100000 && TotalSales >= 50000)
    {
        return TotalSales * 0.05;
    }
    else
    {
        return TotalSales * 0;
    }
}

int main()
{

    float TotalSales;

    cout << "Enter your TotalSales: ";
    cin >> TotalSales;

    cout << "Your commission is: " << CommissionChecker(TotalSales) << endl;

    return 0;
}
