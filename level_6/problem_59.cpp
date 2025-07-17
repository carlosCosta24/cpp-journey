#include <iostream>
using namespace std;
struct stDate {
    short Year;
    short Month;
    short Day;
};
struct stPeriod {
    stDate Start;
    stDate End;
};
stDate ReadDate() {
    stDate Date;
    cout << "Please enter a day: ";
    cin >> Date.Day;
    cout << "Please enter a month: ";
    cin >> Date.Month;
    cout << "Please enter a year: ";
    cin >> Date.Year;
    return Date;
}
stPeriod ReadPeriod() {
    stPeriod Period;
    cout << "Enter starting date??"<< endl;
    Period.Start = ReadDate();
    cout << "Enter ending date??" << endl;
    Period.End = ReadDate();
    return Period;
};
struct stPeriodLength {
    short Length;
    short LengthLastDayIncluded;
};
bool IsDate1BeforeDate2(stDate First, stDate Second) {
    return  (First.Year < Second.Year) ? true :
    ((First.Year == Second.Year) ? (First.Month < Second.Month ? true :
    (First.Month == Second.Month ? First.Day < Second.Day : false)) : false);
}
bool IsLongMonth(short month) {

    return month == 1 || month == 3 || month == 5 ||
           month == 7 || month == 8 || month == 10 || month == 12;
}
bool YearChecker(int Input) {

    return (Input % 4 == 0 && Input % 100 != 0) || (Input % 400 == 0);
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
stDate IncreaseDayByOne(stDate Date) {
    if (IsLastDay(Date.Year, Date.Month, Date.Day) && IsLastMonth(Date.Month)) {
        Date.Year ++;
        Date.Month = 1;
        Date.Day = 1;
    }else {
        short TotalDaysInMonth = NumberOfDays(Date.Year, Date.Month);
        if (Date.Day < TotalDaysInMonth) {
            Date.Day ++;
        }else {
            Date.Month ++;
            Date.Day = 1;
        }
    }
    return Date;
}
int DiffCalculate(stDate Date1, stDate Date2, bool IncludeLastDay = false) {
    int DiffDays = 0;
    while (IsDate1BeforeDate2(Date1, Date2)) {
        DiffDays ++;
        Date1 = IncreaseDayByOne(Date1);
    }
    return IncludeLastDay ? ++DiffDays : DiffDays;
}

stPeriodLength PeriodCalculator(stPeriod Period) {
    stPeriodLength Result;
    Result.Length = DiffCalculate(Period.Start, Period.End);
    Result.LengthLastDayIncluded = DiffCalculate(Period.Start, Period.End, true);
    return Result;
}


int main() {
    stPeriod Period = ReadPeriod();
    stPeriodLength PeriodLength = PeriodCalculator(Period);
    cout << "Period Length: " << PeriodLength.Length << endl;
    cout << "Period Length ( Including last day ): " << PeriodLength.LengthLastDayIncluded;
   return 0;

}