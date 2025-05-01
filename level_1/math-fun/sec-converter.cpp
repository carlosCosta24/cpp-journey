#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int total_seconds;
    int days, hours, minutes, seconds, reminder;
    cout << "Enter the number of seconds: ";
    cin >> total_seconds;
    days = floor(total_seconds / 86400);
    reminder = total_seconds % 86400;
    hours = floor(reminder / 3600);
    reminder = reminder % 3600;
    minutes = floor(reminder / 60);
    reminder = reminder % 60;
    seconds = reminder;

    cout << days << " days " << hours << " hours " << minutes << " minutes " << seconds << " seconds " << endl;

    return 0;
}