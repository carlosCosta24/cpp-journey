#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    short days;
    short hours;
    short minutes;
    short seconds;

    cout << "Enter the number of days: ";
    cin >> days;

    cout << "Enter the number of hours: ";
    cin >> hours;

    cout << "Enter the number of minutes: ";
    cin >> minutes;

    cout << "Enter the number of seconds: ";

    cin >> seconds;

    cout << "Number of seconds: " << days * 86400 + hours * 3600 + minutes * 60 + seconds << " seconds" << endl;
    return 0;
}