#include <iostream>
using namespace std;

int ReadNumber(string Message)
{

    float Num;
    do
    {

        cout << Message;
        cin >> Num;

    } while (Num < 0);

    return Num;
}

float TotalMonths(float Loan, float installment)
{
    return Loan / installment;
}

int main()
{

    float loan = ReadNumber("Enter the Amount of loan: ");
    float installment = ReadNumber("Enter the Monthly payment: ");

    cout << TotalMonths(loan, installment) << " Months" << endl;

    return 0;
}