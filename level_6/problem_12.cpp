#include <iostream>
#include <string>
using namespace std;
void ReadInput(short& Year, short& Month, short& Day){

    cout << "Please enter a Day? ";
    cin >> Day;
    cout << "Please enter a Month? ";
    cin >> Month;
    cout << "Please enter a Year? ";
    cin >> Year;


}
void ReadInput(short& DaysToAdd) {
    cout << "How many Days to Add? ";
    cin >> DaysToAdd;
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
struct stDate {
    short Year;
    short Month;
    short Day;
};
stDate GetDateFromNumberOfDays (short Days, short Year) {
    stDate Date;
    Date.Year = Year;
    Date.Month = 1;
    short DaysLeft = Days;
    short MonthDays = 0;
    while (true) {
        MonthDays = NumberOfDays(Year, Date.Month);
        if (DaysLeft > MonthDays ) {
            DaysLeft -= MonthDays;
            Date.Month++;

        }else {
            Date.Day = DaysLeft;
            break;
        }
    }
        return Date;
}
stDate DateAfterXNumber(short Days, stDate Date) {
    short DaysLeft = Days + DaysPassed(Date.Year, Date.Month, Date.Day);
    short MonthDays = 0;
    Date.Month = 1;
    while (true) {
        MonthDays = NumberOfDays(Date.Year, Date.Month);
        if (DaysLeft > MonthDays ) {
            DaysLeft -= MonthDays;
            Date.Month++;
            if (Date.Month > 12) {
                Date.Month = 1;
                Date.Year++;
            }

        }   else {
            Date.Day = DaysLeft;
            break;
        }
    }

    return Date;
}
stDate GetCurrentDate() {
    stDate Date;
    short Year;
    short Month;
    short Day;
    ReadInput(Year,Month,Day);
    Date.Year = Year;
    Date.Month = Month;
    Date.Day = Day;
    return Date;
}

int main() {

    stDate Date =  GetCurrentDate();
    short DaysToAdd = 0;
    ReadInput(DaysToAdd);
    Date = DateAfterXNumber(DaysToAdd, Date);
    cout << Date.Day<< "/" << Date.Month << "/" << Date.Year <<endl;
    return 0;
}