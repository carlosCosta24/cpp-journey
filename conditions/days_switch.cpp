#include <iostream>
using namespace std;

enum enDays
{
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
};

void DayPrinter(int day)
{
    day = (enDays)day;
    switch (day)
    {
    case enDays::Sunday:
        cout << "sunday";
        break;
    case enDays::Monday:
        cout << "monday";
        break;
    case enDays::Tuesday:
        cout << "tuesday";
        break;
    case enDays::Wednesday:
        cout << "wednesday";
        break;
    case enDays::Thursday:
        cout << "thursday";
        break;
    case enDays::Friday:
        cout << "friday";
        break;
    case enDays::Saturday:
        cout << "saturday";
        break;

    default:
        cout << "Not a week day";
        break;
    }
}

int main()
{
    int day;

    cout << "Enter the day number: ";
    cin >> day;

    DayPrinter(day);
}