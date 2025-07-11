#include <iostream>
#include <string>
using namespace std;

struct stDate {
    short Year;
    short Month;
    short Day;
};
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
bool IsLastDay(short Year, short Month, short Day) {
    short NumberOfDaysInMonth = NumberOfDays(Year, Month);
    return (NumberOfDaysInMonth == Day) ? true : false;
}
bool IsLastMonth(short Month) {
    return (Month == 12 ) ? true : false;
}

int main() {
    short Year;
    short Month;
    short Day;
    ReadInput(Year, Month, Day);
    IsLastDay(Year, Month, Day) ? cout<< "Yes, Day is Last in Month" << endl: cout << "Not Last in Month" << endl;
    IsLastMonth(Month)? cout << "Yes, Month is Last in Year" << endl: cout << "Not Last in Year" << endl;
    return 0;

}