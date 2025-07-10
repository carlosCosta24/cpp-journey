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
short DaysPassed(short Year, short Month, short Day) {
    short Days = 0;
    for (short i = 1; i < Month; i ++) {
        Days += NumberOfDays(Year, i);
    }
    Days += Day;
    return Days;
}
void DateFromNumberOfDays(short Days, short Month, short Year) {
    short TotalDays = Days ;
    short DaysLeft;
    for (short i = 1; i < Month; i ++) {
        if (Days >= 28) {
            Days -= NumberOfDays(Year, i);
        }
        DaysLeft = Days;
    }
    cout << "Date for [" << TotalDays << "] is: "<< DaysLeft << "/" << Month << "/" << Year <<endl;
}
/*
  // model solution:
    structsDate{
    short Year;
    short Month;
    short Day;
    };

sDate GetDateFromDayOrderInYear(shortDateOrderInYear, shortYear) {
    sDate Date;
    short RemainingDays = DateOrderInYear;
    short MonthDays = 0;
    Date.Year = Year;
    Date.Month = 1;
    while (true){
        MonthDays = NumberOfDaysInAMonth(Date.Month, Year);
        if (RemainingDays > MonthDays) {
            RemainingDays -= MonthDays;
            Date.Month++;
        } else
    {
        Date.Day = RemainingDays; break;
    }
} return Date;
}
 */
int main() {
    short Year, Month, Day;
    ReadInput(Year, Month, Day);
    cout << "Number Of Days From the beginning of the year is: "<<  DaysPassed(Year, Month, Day) <<endl;
    short NumberOfDays = DaysPassed(Year, Month, Day);
    DateFromNumberOfDays(NumberOfDays, Month, Year);
    return 0;
}
