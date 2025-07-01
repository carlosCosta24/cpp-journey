#include <iostream>
#include <string>
#include <vector>
using namespace std;
void ReadInput(int& Year, int& Month){

    cout << "Please enter a Year? ";
    cin >> Year;
    cout << "Please enter a Month? ";
    cin>> Month;
}
bool YearChecker(int Input) {

    return (Input % 4 == 0 && Input % 100 != 0) || (Input % 400 == 0);
}

bool IsLongMonth(int Input) {
    vector<int> vMonthOf31 = {1,3,5,7,8,10,12};
    for (int Element : vMonthOf31) {
        if (Input == Element) return true;
    }
    return false;
}

short NumberOfDays(int Year , int Month) {

    if (Month < 1 || Month > 12) return 0;
    return(Month == 2)
    ?(YearChecker(Year)?  29 : 28)
    : ((IsLongMonth(Month))? 31: 30);
}

short NumberOfHours(int Year , int Month) {
    return NumberOfDays(Year , Month) * 24;
}

int NumberOfMinutes(int Year , int Month) {
    return NumberOfHours(Year , Month) * 60;
}

int NumberOfSeconds(int Year , int Month) {
    return NumberOfMinutes(Year , Month) * 60;
}

int main() {
    int Year, Month;
    ReadInput(Year, Month);

    cout << "Number of Days in Month [" << Month << "] is "
    << NumberOfDays(Year, Month) << endl;
    cout << "Number of Hours in Month [" << Month << "] is "
    << NumberOfHours(Year, Month) << endl;
    cout << "Number of Minutes in Month [" << Month << "] is "
    << NumberOfMinutes(Year, Month) << endl;
    cout << "Number of seconds in Month [" << Month << "] is "
    << NumberOfSeconds(Year, Month) << endl;
    return 0;

}
