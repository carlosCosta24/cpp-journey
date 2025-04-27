#include <iostream>
using namespace std;

void MonthPrinter(int Num)

{
    string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};
    if (Num <= 11)
    {
        cout << "we are in: " << months[Num] << endl;
    }
    else
    {
        cout << "Wrong number!!!!" << endl;
    }
}

int main()
{
    int MonthNum;

    cout << "Enter the number of the Month (1-12): ";
    cin >> MonthNum;

    MonthPrinter(MonthNum - 1);

    return 0;
}