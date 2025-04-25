#include <iostream>
using namespace std;

int main()
{

    int day, hours, minutes, seconds, reminder;

    cout << "Enter the number of sec: ";
    cin >> seconds;

    day = seconds / 86400;
    reminder = seconds % 86400;

    hours = reminder / 3600;
    reminder %= 3600;

    minutes = reminder / 60;
    reminder %= 60;

    seconds = reminder;

    cout << day << ":" << hours << ":" << minutes << ":" << seconds << endl;
    return 0;
}