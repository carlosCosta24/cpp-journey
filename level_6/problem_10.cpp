#include <iostream>
#include <string>
#include <vector>
using namespace std;
void ReadInput(short& Year, short& Month, short& Day){

    cout << "Please enter a Day? ";
    cin >> Day;
    cout << "Please enter a Month? ";
    cin >> Month;
    cout << "Please enter a Year? ";
    cin >> Year;

}
bool YearChecker(short Input) {

    return (Input % 4 == 0 && Input % 100 != 0) || (Input % 400 == 0);
}
bool IsLongMonth(short month) {

    return month == 1 || month == 3 || month == 5 ||
           month == 7 || month == 8 || month == 10 || month == 12;
}
short NumberOfDays(short Year , short Month) {

    if (Month < 1 || Month > 12) return 0;
    return(Month == 2)
    ?(YearChecker(Year)?  29 : 28)
    : ((IsLongMonth(Month))? 31: 30);
}
void DaysPassed(short Year, short Month, short Day) {
    short Days = 0;
    for (short i = 1; i < Month; i ++) {
        Days += NumberOfDays(Year, i);
    }
    Days += Day;
    cout << "Number Of Days From the begining of the year is: "<<  Days <<endl;
}

int main() {
    short Year, Month, Day;
    ReadInput(Year, Month, Day);
    DaysPassed(Year, Month, Day);
    return 0;
}
