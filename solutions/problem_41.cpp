#include <iostream>
using namespace std;

float ReadNumbers(string Message)
{
    float Num;

    cout << Message;
    cin >> Num;

    return Num;
}

float DaysCalculator(float Hour)
{

    const int HourPerDay = 24;
    return Hour / HourPerDay;
}

float WeekCalculator(float Day)
{
    const int DaysPerWeek = 7;
    return Day / DaysPerWeek;
}

int main()
{

    float EnteredHours = ReadNumbers("Enter the number of hours: ");
    float Days = DaysCalculator(EnteredHours);
    float Weeks = WeekCalculator(Days);

    cout << "Weeks: " << Weeks << endl;
    cout << "Days: " << Days << endl;

    return 0;
}
