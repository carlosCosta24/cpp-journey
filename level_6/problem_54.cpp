#include <iostream>
using namespace std;
struct stDate {
    short Year;
    short Month;
    short Day;
};
void DayFinder(int Year, int Month, int Day , string& Output) {
    string Days [7] = {"Sun", "Mon", "Tue",
        "Wed", "Thu", "Fri", "Sat"};
    const int A = (14 - Month) / 12;
    const int Y = Year - A;
    const int M = Month + (12 * A) - 2;
    const int D = (Day + Y + (Y/4)-(Y/100)+(Y/400)+ ((31 * M)/ 12 )) % 7;
    Output = Days[D];
}
int DayFinder(stDate Date) {
    //when using overload in future make sure to call the
    //function not to copy & edit it in the overloaded one
    const int A = (14 - Date.Month) / 12;
    const int Y = Date.Year - A;
    const int M = Date.Month + (12 * A) - 2;
    const int D = (Date.Day + Y + (Y/4)-(Y/100)+(Y/400)+ ((31 * M)/ 12 )) % 7;
    return D;
}
bool IsWeekEnd(stDate Date) {
    short Day = DayFinder(Date);
    return (Day == 0 || Day == 6);
}
bool IsBusinessDay(stDate Date) {
    return IsWeekEnd(Date) ? false: true;
}
bool YearChecker(short Input) {

    return (Input % 4 == 0 && Input % 100 != 0) || (Input % 400 == 0);
}
bool IsLongMonth(short month) {

    return month == 1 || month == 3 || month == 5 ||
           month == 7 || month == 8 || month == 10 || month == 12;
}
bool IsDate1BeforeDate2(stDate First, stDate Second) {
    return  (First.Year < Second.Year) ? true :
    ((First.Year == Second.Year) ? (First.Month < Second.Month ? true :
    (First.Month == Second.Month ? First.Day < Second.Day : false)) : false);
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
short VacationCalculator(stDate Start, stDate End) {
    short Vacation = 0;
    while (IsDate1BeforeDate2(Start,End))
    {
        if (IsBusinessDay(Start)) Vacation ++;
        Start = IncreaseDayByOne(Start);
    }
    return Vacation;
}

int main() {
    stDate Start = ReadDate();
    stDate End = ReadDate();
    string Output;
    cout << endl;
    DayFinder(Start.Year, Start.Month, Start.Day, Output);
    cout << "Vacation form: " << Output << ", "<<Start.Day << "/" << Start.Month << "/"<< Start.Year << endl;
    cout << endl;
    DayFinder(End.Year, End.Month, End.Day, Output);
    cout << "Vacation to: "<< Output<<", "<<End.Day << "/" << End.Month << "/"<< End.Year << endl;
    cout << endl;

    cout << "Actual Vacation Days is: " << VacationCalculator(Start, End) << endl;
    cout << endl;
    return 0;


}