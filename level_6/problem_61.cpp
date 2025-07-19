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
enum enCompare {
    Before = -1,
    After = 1,
    Equal = 0

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
bool IsDate1BeforeDate2(stDate First, stDate Second) {
    return  (First.Year < Second.Year) ? true :
    ((First.Year == Second.Year) ? (First.Month < Second.Month ? true :
    (First.Month == Second.Month ? First.Day < Second.Day : false)) : false);
}
bool DateIsEqual(stDate First, stDate Second) {
    return (First.Year == Second.Year) ?
    ((First.Month == Second.Month) ? ((First.Day == Second.Day) ? true : false) : false) : false;
}
bool IsDateOneAfterDateTwo(stDate First, stDate Second) {
    return (!IsDate1BeforeDate2(First, Second)) && !DateIsEqual(First, Second);
}
enCompare DateCompare(stDate First, stDate Second) {

    if (IsDate1BeforeDate2(First, Second)) return enCompare::Before;
    if (DateIsEqual(First, Second)) return enCompare::Equal;
    return enCompare::After;
}
bool IsOverlap(stPeriod First, stPeriod Second) {
    // make sure to check both cases
    return !(DateCompare(First.End, Second.Start) == enCompare::Before ||
        DateCompare(Second.Start, First.End) == enCompare::After);

}
bool YearChecker(short Input) {

    return (Input % 4 == 0 && Input % 100 != 0) || (Input % 400 == 0);
}
bool IsLongMonth(short month) {

    return month == 1 || month == 3 || month == 5 ||
           month == 7 || month == 8 || month == 10 || month == 12;
}
bool IsLastMonth(short Month) {
    return (Month == 12 ) ? true : false;
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
stDate DecreaseDayByOne(stDate Date) {
    if (Date.Day == 1 ) {
        if (Date.Month == 1) {
            Date.Year --;
            Date.Month = 12;
            Date.Day = 31;
        }else {
            Date.Month --;
            Date.Day = NumberOfDays(Date.Year, Date.Month);
        }
    }else {
        Date.Day --;
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
short PeriodCalculator(stPeriod Period, bool IncludeLastDay = false) {
    return DiffCalculate(Period.Start, Period.End, IncludeLastDay);
}
bool IsWithinPeriod(stPeriod Period, stDate Date) {
    return !(DateCompare( Date, Period.Start) == enCompare::Before ||
        DateCompare( Date, Period.End) == enCompare::After);
}
short OverlapCounter(stPeriod First, stPeriod Second) {
    short OverLapDays = 0 ;
    int Period1Length = PeriodCalculator(First);
    int Period2Length = PeriodCalculator(Second);
    if (!IsOverlap(First, Second)) return 0;

    if (Period1Length < Period2Length) {
        while (IsDate1BeforeDate2(First.Start, First.End)) {
            if (IsWithinPeriod(Second,First.Start )) OverLapDays ++;
            First.Start = IncreaseDayByOne(First.Start);
        }
    }else {
        while (IsDate1BeforeDate2(Second.Start, Second.End)) {
            if (IsWithinPeriod(First, Second.Start)) OverLapDays ++;
            Second.Start = IncreaseDayByOne(Second.Start);
        }
    }
    return OverLapDays;

}

int main() {
    stPeriod First, Second;
    cout << "Enter Period 1:"<< endl;
    First = ReadPeriod();

    cout << "Enter Period 2:"<< endl;
    Second = ReadPeriod();

    cout<< "Overlap Day Count is: "<< OverlapCounter(First, Second) << endl;
    return 0;


}