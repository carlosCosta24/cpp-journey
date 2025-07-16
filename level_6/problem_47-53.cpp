#include <iostream>
using namespace std;
struct stDate {
    short Year;
    short Month;
    short Day;
};
void DayFinder(int Year, int Month, int Day , string& Output) {
    string Days [7] = {"Sun", "Mon", "Tus",
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
stDate SystemDate() {
    stDate Date;
    const time_t t = time(nullptr);
    const tm* Time = localtime(&t);
    Date.Year = Time->tm_year + 1900;
    Date.Month = Time->tm_mon + 1;
    Date.Day = Time->tm_mday;
    return Date;
}
bool IsDate1BeforeDate2(stDate First, stDate Second) {
    return  (First.Year < Second.Year) ? true :
    ((First.Year == Second.Year) ? (First.Month < Second.Month ? true :
    (First.Month == Second.Month ? First.Day < Second.Day : false)) : false);
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
bool IsEndOfWeek(stDate Date) {
    short Day = DayFinder(Date);
    if (Day == 6) {
        return true;
    }
    return false;
}

bool IsWeekEnd(stDate Date) {
    short Day = DayFinder(Date);
    return (Day == 0 || Day == 6);
}

bool IsBusinessDay(stDate Date) {
    return IsWeekEnd(Date) ? false: true;
}

short DayUntilEndOfWeek(stDate Date) {
    /*short Day = DayFinder(Date);
    short DaysLeft = 0;
    for (Day ; Day <= 5 ; Day++ ) {
        DaysLeft ++;
    }
    return DaysLeft;*/
    return 6 - DayFinder(Date);
}
short DaysUntilEndOfMonth(stDate Date) {
    /*short Day = Date.Day;
    short DaysInMonth = NumberOfDays(Date.Year, Date.Month);
    short DaysLeft = DaysInMonth - Day;
    */
    stDate Last;
    Last.Day = NumberOfDays(Date.Year, Date.Month);
    Last.Month = Date.Month;
    Last.Year = Date.Year;
    short DaysLeft = DiffCalculate(Date, Last, true);
    return DaysLeft;
}
short DaysUntilEndOfYear(stDate Date) {
    stDate End;
    End.Year = Date.Year;
    End.Month = 12;
    End.Day = 31;
    return DiffCalculate(Date, End);

}

int main() {
stDate Date = SystemDate();
    string Output;
    DayFinder(Date.Year, Date.Month, Date.Day, Output );
    cout << "Today is: " << Output << ", "<< Date.Day << "/" << Date.Month << "/"<< Date.Year << endl;
    cout << endl;

    cout << "Is it End of the week?"<< endl;
    IsEndOfWeek(Date)?
    cout<<"Yes, today is end of the week!! have a nice weekend :-) " << endl:
    cout<<"No, today is not the end of week"<< endl;
    cout << endl;

    cout << "Is it weekend?"<< endl;
    IsWeekEnd(Date)?
    cout << "Yes, it is a weekend"<< endl:
    cout << "No, it is not a weekend"<< endl;
    cout << endl;

    cout << "Is it Business Day?"<< endl;
    IsBusinessDay(Date)?
    cout << "Yes, it is a business day"<< endl:
    cout << "No, it is not a business day"<< endl;
    cout << endl;

    cout << endl;
    cout << "Days until end of Week: " << DayUntilEndOfWeek(Date)   << " Day (s)" << endl;
    cout << "Days until end of month: " << DaysUntilEndOfMonth(Date)<< " Day (s)"  << endl;
    cout << "Days until end of year: " << DaysUntilEndOfYear(Date)  << " Day (s)"  << endl;
    return 0;

}
