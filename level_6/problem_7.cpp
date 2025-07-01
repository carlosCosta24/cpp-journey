#include <iostream>
#include <string>
#include <vector>
using namespace std;

void ReadInput(int& Year, int& Month, int& Day){

    cout << "Please enter a Year? ";
    cin >> Year;
    cout << "Please enter a Month? ";
    cin>> Month;
    cout << "Please enter a Day? ";
    cin >> Day;
}

void DateFormat(int Year, int Month, int Day) {
    cout << "Date: "<< Day << " / " << Month << " / " << Year << endl;
}

void DayFinder(int Year, int Month, int Day , string& Output , int& Order) {
    string Days [7] = {"Sunday", "Monday", "Tuesday",
        "Wednesday", "Thursday", "Friday", "Saturday"};
    const int A = (14 - Month) / 12;
    const int Y = Year - A;
    const int M = Month + (12 * A) - 2;
    const int D = (Day + Y + (Y/4)-(Y/100)+(Y/400)+ ((31 * M)/ 12 )) % 7;
    Output = Days[D];
    Order = D;
}

int main() {
    int Year, Month, Day, Order;
    string Output;
    ReadInput(Year, Month, Day);
    DateFormat(Year, Month, Day);
    DayFinder(Year, Month, Day, Output, Order);
    cout << "Day Name: " << Output << endl;
    cout << "Order Number: " << Order << endl;
    return 0;
}