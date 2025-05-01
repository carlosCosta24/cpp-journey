#include <iostream>
using namespace std;

string SecCalculator(int input_sec)
{
    int day, hours, minutes, sec, reminder;

    day = input_sec / 86400;
    reminder = input_sec % 86400;
    hours = reminder / 3600;
    reminder %= 3600;
    minutes = reminder / 60;
    reminder %= 60;
    sec = reminder;

    return to_string(day) + ":" + to_string(hours) + ":" + to_string(minutes) + ":" + to_string(sec);
}

int main()
{
    int sec;

    cout << "Enter the number of sec: ";
    cin >> sec;

    cout << SecCalculator(sec) << endl;
}
