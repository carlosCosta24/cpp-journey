#include <iostream>
using namespace std;

struct stTimeComponent
{
    float Days;
    float Hours;
    float Minutes;
    float seconds;
};

int ReadNumbers(string Message)
{
    float Num;

    cout << Message;
    cin >> Num;

    return Num;
}

stTimeComponent Reader()
{
    stTimeComponent Time;

    Time.Days = ReadNumbers("Enter the number of days: ");
    Time.Hours = ReadNumbers("Enter the number of Hours: ");
    Time.Minutes = ReadNumbers("Enter the number of Minutes: ");
    Time.seconds = ReadNumbers("Enter the number of seconds: ");

    return Time;
}

int SecondsConverter(stTimeComponent Time)
{
    int Seconds = 0;

    Seconds = Time.Days * 86400;
    Seconds += Time.Hours * 3600;
    Seconds += Time.Minutes * 60;
    Seconds += Time.seconds;

    return Seconds;
}

int main()
{

    cout << "Task duration in seconds is: " << endl
         << SecondsConverter(Reader()) << endl;
    return 0;
}