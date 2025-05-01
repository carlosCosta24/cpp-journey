#include <iostream>
using namespace std;

void DayPrinter(int Num)

{
    string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    if (Num <= 6)
    {
        cout << "today is: " << days[Num] << endl;
    }
    else
    {
        cout << "Wrong number!!!!" << endl;
    }
}

int main()
{
    int DayNum;

    cout << "Enter the number of the day(0-6): ";
    cin >> DayNum;

    DayPrinter(DayNum);

    return 0;
}