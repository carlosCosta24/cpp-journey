#include <iostream>
#include <locale>
using namespace std;

int main()
{

    double day, hours, minutes, second;

    cout << "Enter the number of days: ";
    cin >> day;

    cout << "Enter the number of hours: ";
    cin >> hours;

    cout << "Enter the number of minutes: ";
    cin >> minutes;

    cout << "Enter the number of sec: ";
    cin >> second;

    double total = (day * 86400) + (hours * 3600) + (minutes * 60) + second;
    cout.imbue(std::locale("en_US.UTF-8"));
    cout << total << endl;

    return 0;
}