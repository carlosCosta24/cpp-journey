#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include "clsString.h"
using namespace std;

class clsMyDate {
    private:
    short _Year;
    short _Month;
    short _Day;

    public:
    void SetYear(short Input) {
        _Year = Input;
    }
    void SetMonth(short Input) {
        _Month = Input;
    }
    void SetDay(short Input) {
        _Day = Input;
    }
    short GetYear() {
        return _Year;
    }
    short GetMonth() {
        return _Month;
    }
    short GetDay() {
        return _Day;
    }
    short GetNumberOfMonth(string Month){
        short NumberOfMonth = 0;
        const string Months[] {
            "Jan" , "Feb", "Mar", "Apr",
            "May" , "Jun",  "Jul", "Aug",
            "Sep" , "Oct" ,"Nov", "Dec"
        };
        for (int i = 0; i <= 11; i++) {
            if (Month == Months[i]) {
                NumberOfMonth =  i + 1;
                break;
            }
        }
        return NumberOfMonth;
    }
    clsMyDate() {
        time_t t = time(0);
        const char * Time = ctime(&t);
        vector <string> DateElements = clsString::StringSplitter(Time, " ");
        _Year = stoi(DateElements[4]);
        _Month = GetNumberOfMonth(DateElements[1]);
        _Day = stoi(DateElements[2]);
    }
    clsMyDate(string date) {
        vector<string> DateElements = clsString::StringSplitter(date, "/");
        if (DateElements.size() >= 3) {
            _Day = stoi(DateElements[0]);

            _Month = stoi(DateElements[1]);

            _Year = stoi(DateElements[2]);
        }
    }
    clsMyDate(int Day, int Month, int Year) {
        _Year = Year;
        _Month = Month;
        _Day = Day;
    }
    static bool IsLeapYear(int Input) {

        // leap year if perfectly divisible by 400
        if (Input % 400 == 0) {
            return true;
        }
        // not a leap year if divisible by 100// but not divisible by 400
        else if (Input % 100 == 0) {
            return false;
        }
        // leap year if not divisible by 100// but divisible by 4
        else if (Input % 4 == 0) {
            return true;
        }
        // all other years are not leap years
        else {
            return false;
        }
    }
    bool IsLeapYear() {
        return IsLeapYear(_Year);
    }
    static void YearDetails(int Input) {
        if (IsLeapYear(Input)) {
            cout << "Number of Days in" << "[" << Input << "]" << "Is 366" <<endl;
            cout << "Number of Hours in" << "[" << Input << "]" << "Is 8784" <<endl;
            cout << "Number of Minutes in" << "[" << Input << "]" << "Is 527040" <<endl;
            cout << "Number of Seconds in" << "[" << Input << "]" << "Is 31622400" <<endl;

        }else {
            cout << "Number of Days in" << "[" << Input << "]" << "Is 365" <<endl;
            cout << "Number of Hours in" << "[" << Input << "]" << "Is 8760" <<endl;
            cout << "Number of Minutes in" << "[" << Input << "]" << "Is 525600" <<endl;
            cout << "Number of Seconds in" << "[" << Input << "]" << "Is 31536000" <<endl;

        }
    }
    void YearDetails() {
        YearDetails(_Year);
    }
    static short NumberOfDays(int Year , int Month) {
        if (Month < 1 || Month > 12) {
            return 0;
        }
        if (Month == 2) {
            return IsLeapYear(Year)?  29 : 28;
        }
        int LongMonth [7] = {1,3,5,7,8,10,12};
        for (int i = 1; i < 7; i++) {
            if (Month == LongMonth[i - 1]) {
                return 31;
            }
        }
        return 30;
    }
    short NumberOfDays() {
        return NumberOfDays(_Year, _Month);
    }
    static short NumberOfHours(int Year , int Month) {
        return NumberOfDays(Year , Month) * 24;
    }
    static int NumberOfMinutes(int Year , int Month) {
        return NumberOfHours(Year , Month) * 60;
    }
    static int NumberOfSeconds(int Year , int Month) {
        return NumberOfMinutes(Year , Month) * 60;
    }
    short NumberOfHours() {
        return NumberOfHours(_Year, _Month);
    }
    int NumberOfMinutes() {
        return NumberOfMinutes(_Year, _Month);
    }
    int NumberOfSeconds() {
        return NumberOfSeconds(_Year, _Month);
    }
    static bool IsLongMonth(int Input) {
        vector<int> vMonthOf31 = {1,3,5,7,8,10,12};
        for (int Element : vMonthOf31) {
            if (Input == Element) return true;
        }
        return false;
    }
    bool IsLongMonth() {
        return IsLongMonth(_Month);
    }
    static void PrintDate(int Year, int Month, int Day) {
        cout << "Date: "<< Day << " / " << Month << " / " << Year << endl;
    }
    void PrintDate() {
        PrintDate(_Year, _Month, _Day);
    }
    static short DayFinder(int Year, int Month, int Day) {
        string Days [7] = {
            "Sunday", "Monday", "Tuesday",
            "Wednesday", "Thursday", "Friday", "Saturday"
        };
        const int A = (14 - Month) / 12;
        const int Y = Year - A;
        const int M = Month + (12 * A) - 2;
        const int D = (Day + Y + (Y/4)-(Y/100)+(Y/400)+ ((31 * M)/ 12 )) % 7;
        return D;
    }
    short DayFinder() {
        return DayFinder(_Year, _Month, _Day);
    }
    //need refactor
    static void MonthCalenderPrinter(int Year , int Month) {
    const string Months [12] = {"Jan", "Feb", "Mar", "Apr","May",
        "Jun", "Jul", "Aug", "Sep","Oct", "Nov", "Dec"};
    int CurrentDay = DayFinder(Year, Month, 1);
    short Days = NumberOfDays(Year, Month);

    printf("\n___________________%s____________________\n",
        Months[Month-1].c_str());
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
    int Start = CurrentDay % 7;
    for (Start =0; Start < CurrentDay ; Start++ ) {
        printf("     ");
    }

    for (int i = 1; i <= Days ; i++) {
        printf("%5d", i);
        Start ++;
        if (Start == 7) {
            Start = 0;
            printf("\n");
        }
    }
    if (Start != 0) {
        printf("\n");
    }
    printf("\n _________________________________________\n");

}
    void MonthCalenderPrinter() {
        MonthCalenderPrinter(_Year, _Month);
    }
    static void YearCalenderPrinter(int Year) {
        printf("\n___________________________________\n");
        printf("\t\t Calendar - %d ", Year);
        printf("\n___________________________________\n");

        for (short Month = 1; Month <= 12; Month++) {
            MonthCalenderPrinter(Year, Month);
            printf("\n");
        }

    }
    void YearCalenderPrinter() {
        YearCalenderPrinter(_Year);
    }
    static short DaysPassed(short Year, short Month, short Day) {
        short Days = 0;
        for (short i = 1; i < Month; i ++) {
            Days += NumberOfDays(Year, i);
        }
        Days += Day;
        return Days;
    }
    short DaysPassed() {
        return DaysPassed(_Year, _Month, _Day);
    }
    static void DateFromNumberOfDays(short Days, short Month, short Year) {
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
    void DateFromNumberOfDays() {
        DateFromNumberOfDays(_Day, _Month, _Year);
    }
    clsMyDate DateAfterXNumber(short Days, clsMyDate Date) {
    short DaysLeft = Days + DaysPassed(_Year, _Month, _Day);
    short MonthDays = 0;
    Date = *this;
    while (true) {
        MonthDays = NumberOfDays(Date._Year, Date._Month);
        if (DaysLeft > MonthDays ) {
            DaysLeft -= MonthDays;
            Date._Month++;
            if (Date._Month > 12) {
                Date._Month = 1;
                Date._Year++;
            }

        }   else {
            Date._Day = DaysLeft;
            break;
        }
    }

    return Date;
}
    void DateAfterXNumberOfDays(short Number) {
        clsMyDate Date = DateAfterXNumber(Number, clsMyDate());
        cout << _Year << "/" << _Month << "/" << _Day << endl;
    }
    static bool DateIsLessThan(clsMyDate First, clsMyDate Second) {
        if (First._Year < Second._Year) {
            return true;
        }else if (First._Year == Second._Year) {
            if (First._Month < Second._Month) {
                return true;
            }else if (First._Month == Second._Month) {
                return First._Day < Second._Day;
            }
        }
        return false;
    }
    bool DateIsLessThan(clsMyDate Second) {
        return DateIsLessThan(*this,Second);
    }
    static bool DateIsLessThanOrEqual(clsMyDate First, clsMyDate Second) {
        if (First._Year <= Second._Year) {
            return true;
        }else if (First._Year == Second._Year) {
            if (First._Month <= Second._Month) {
                return true;
            }else if (First._Month == Second._Month) {
                return First._Day <= Second._Day;
            }
        }
        return false;
    }
    bool DateIsLessThanOrEqual(clsMyDate Second) {
        return DateIsLessThanOrEqual(*this,Second);
    }
    static bool IsLastDay(short Year, short Month, short Day) {
        short NumberOfDaysInMonth = NumberOfDays(Year, Month);
        return (NumberOfDaysInMonth == Day) ? true : false;
    }
    bool IsLastDay() {
        return IsLastDay(_Year, _Month, _Day);
    }
    static bool IsLastMonth(short Month) {
        return (Month == 12 ) ? true : false;
    }
    bool IsLastMonth() {
        return IsLastMonth(_Month);
    }
    static clsMyDate IncreaseDayByOne(clsMyDate Date) {
        if (IsLastDay(Date._Year, Date._Month, Date._Day) && IsLastMonth(Date._Month)) {
            Date._Year += 1;
            Date._Month = 1;
            Date._Day = 1;
        }else {
            short TotalDaysInMonth = NumberOfDays(Date._Year, Date._Month);
            if (Date._Day < TotalDaysInMonth) {
                Date._Day += 1;
            }else {
                Date._Month += 1;
                Date._Day = 1;
            }
        }
        return Date;
    }

    static bool IsDate1BeforeDate2(clsMyDate First, clsMyDate Second) {
        return  (First._Year < Second._Year) ? true :
        ((First._Year == Second._Year) ? (First._Month < Second._Month ? true :
        (First._Month == Second._Month ? First._Day < Second._Day : false)) : false);
    }
    bool IsDateBeforeDate2(clsMyDate Date2) {
        return IsDate1BeforeDate2(*this, Date2);
    }
    static int DiffCalculate(clsMyDate Date1, clsMyDate Date2, bool IncludeLastDay = false) {
        int DiffDays = 0;
        while (IsDate1BeforeDate2(Date1, Date2)) {
            DiffDays ++;
            Date1 = IncreaseDayByOne(Date1);
        }
        return IncludeLastDay ? ++DiffDays : DiffDays;
    }
    int DiffCalculator(clsMyDate Date2) {
        return DiffCalculate(*this, Date2);
    }
    static short AgeCalculateInDays(clsMyDate BirthDate){
        clsMyDate Current;
        return DiffCalculate(BirthDate,Current);

    }
    short AgeCalculateInDays(clsMyDate BirthDate, clsMyDate Current, bool IncludeLastDay) {
        return DiffCalculate(BirthDate, Current, IncludeLastDay);
    }
    static	bool IsValidDate(clsMyDate Date)
    {
        if (Date._Day < 1 || Date._Day>31)
            return false;

        if (Date._Month < 1 || Date._Month>12)
            return false;

        if (Date._Month == 2)
        {
            if (IsLeapYear(Date._Year))
            {
                if (Date._Day > 29)
                    return false;
            }
            else
            {
                if (Date._Day > 28)
                    return false;
            }
        }

        short DaysInMonth = NumberOfDays(Date._Month, Date._Year);

        if (Date._Day > DaysInMonth)
            return false;

        return true;

    }
    static void PrintDateFromObj(clsMyDate Date) {
        cout << Date._Day << "/" << Date._Month << "/" << Date._Year << endl;
    }
};