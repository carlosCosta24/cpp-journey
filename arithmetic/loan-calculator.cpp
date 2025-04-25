#include <iostream>
using namespace std;

int main()
{
    double loan_total, monthly_payment;

    cout << "Enter the desired loan amount: ";
    cin >> loan_total;

    cout << "Enter the monthly payment desired: ";
    cin >> monthly_payment;

    cout << loan_total / monthly_payment << " Months" << endl;

    return 0;
}