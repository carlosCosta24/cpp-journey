#include <iostream>
using namespace std;

int SecCalculator(int day, int hours, int minutes, int sec)
{
    day *= 86400;
    hours *= 3600;
    minutes *= 60;
    int total = day + hours + minutes + sec;
    return total;
}

int main()
{
    int days, hours, minutes, sec;

    cout << "Enter the number of days: ";
    cin >> days;

    cout << "Enter the number of hours: ";
    cin >> hours;

    cout << "Enter the number of minutes: ";

    cin >> minutes;

    cout << "Enter the number of sec: ";
    cin >> sec;

    cout << SecCalculator(days, hours, minutes, sec) << endl;
}
