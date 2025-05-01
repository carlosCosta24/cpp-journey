#include <iostream>
using namespace std;

float ReadNumbers(string Message)
{
    float Num;

    cout << Message;
    cin >> Num;

    return Num;
}

float ReminderCalculator(float CashPaid, float BillTotal)
{
    float Reminder = CashPaid - BillTotal;

    return Reminder;
}

int main()
{
    float CashPaid = ReadNumbers("Enter the paid Cash: ");
    float TotalAmount = ReadNumbers("Enter the Total Bill amount: ");

    cout << "---------------------------------------" << endl;

    cout << "Reminder is: " << ReminderCalculator(CashPaid, TotalAmount) << endl;

    return 0;
}
