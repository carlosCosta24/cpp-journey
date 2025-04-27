#include <iostream>
using namespace std;

enum enMonths
{
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December,
};

void MonthPrinter(int Num)
{
    Num = (enMonths)Num;

    switch (Num)
    {
    case enMonths::January:
        cout << "jan" << endl;
        break;

    case enMonths::February:
        cout << "feb" << endl;
        break;
    case enMonths::March:
        cout << "mar" << endl;
        break;
    case enMonths::April:
        cout << "apr" << endl;
        break;
    case enMonths::May:
        cout << "may" << endl;
        break;
    case enMonths::June:
        cout << "jun" << endl;
        break;
    case enMonths::July:
        cout << "july" << endl;
        break;
    case enMonths::August:
        cout << "ugt" << endl;
        break;
    case enMonths::September:
        cout << "sep" << endl;
        break;
    case enMonths::October:
        cout << "oct" << endl;
        break;
    case enMonths::November:
        cout << "nov" << endl;
        break;
    case enMonths::December:
        cout << "dec" << endl;
        break;
    default:
        cout << "Not a month" << endl;
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