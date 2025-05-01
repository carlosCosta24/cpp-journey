#include <iostream>
#include <cmath>
using namespace std;

struct stTimeComponent
{
    int Days;
    int Hours;
    int Minutes;
    int seconds;
};

int ReadNumbers(string Message)
{
    float Num;

    cout << Message;
    cin >> Num;

    return Num;
}

stTimeComponent Reader(int TotalSeconds)
{
    stTimeComponent Time;
    int Reminder;

    Time.Days = floor(TotalSeconds / 86400);
    Reminder = TotalSeconds % 86400;
    Time.Hours = floor(Reminder / 3600);
    Reminder = Reminder % 3600;
    Time.Minutes = floor(Reminder / 60);
    Time.seconds = Reminder;

    return Time;
}

void Printer(stTimeComponent Time)
{
    cout << Time.Days << ":"
         << Time.Hours << ":"
         << Time.Minutes << ":"
         << Time.seconds << endl;
}

int main()
{

    Printer(Reader(ReadNumbers("Please Enter the number of seconds: ")));
    return 0;
}