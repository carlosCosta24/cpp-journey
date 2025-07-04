#include <iostream>
#include <string>
#include <vector>
using namespace std;

void ReadInput(short& Year, short& Month){

    cout << "Please enter a Year? ";
    cin >> Year;
    cout << "Please enter a Month? ";
    cin>> Month;
}
bool YearChecker(int Input) {

    return (Input % 4 == 0 && Input % 100 != 0) || (Input % 400 == 0);
}
short DayFinder(int Year, int Month, int Day ) {
    const int A = (14 - Month) / 12;
    const int Y = Year - A;
    const int M = Month + (12 * A) - 2;
    const int D = (Day + Y + (Y/4)-(Y/100)+(Y/400)+ ((31 * M)/ 12 )) % 7;
    return D ;
}
bool IsLongMonth(int month) {

    return month == 1 || month == 3 || month == 5 ||
           month == 7 || month == 8 || month == 10 || month == 12;
}
short NumberOfDays(int Year , int Month) {

    if (Month < 1 || Month > 12) return 0;
    return(Month == 2)
    ?(YearChecker(Year)?  29 : 28)
    : ((IsLongMonth(Month))? 31: 30);
}

void MonthCalenderPrinter(int Year , int Month) {
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
int main() {
    short Year = 0, Month = 0;

    do {
        ReadInput(Year, Month);
        if (Year < 1 || Month < 1 || Month > 12)
            cout << "Invalid input. Try again.\n";
    } while (Year < 1 || Month < 1 || Month > 12);

    MonthCalenderPrinter(Year, Month);
    return 0;

}

/*
 * bool isLeapYear(shortYear)
 * { // if year is divisible by 4 AND not divisible by 100
 * // OR if year is divisible by 400
 * // then it is a leap year
 * return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0); }
 * short DayOfWeekOrder(shortDay, shortMonth, shortYear) {
 * short a, y, m;
 * a = (14 - Month) / 12;
 * y = Year - a;
 * m = Month + (12 * a) - 2;
 * // Gregorian://0:sun, 1:Mon, 2:Tue...etc
 * return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7; }
 * string DayShortName(shortDayOfWeekOrder) { string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" }; return arrDayNames[DayOfWeekOrder]; }
 * short NumberOfDaysInAMonth(shortMonth, shortYear) {
 * if (Month < 1 || Month>12) return  0;
 * int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
 * return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1]; }
 * string MonthShortName(shortMonthNumber) {
 * string Months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" }; return (Months[MonthNumber - 1]); }
 * void PrintMonthCalendar(shortMonth, shortYear) {
 * int NumberOfDays;
 * // Index of the day from 0 to 6
 * int current = DayOfWeekOrder(1, Month, Year);
 * NumberOfDays = NumberOfDaysInAMonth(Month, Year);
 * // Print the current month name
 * printf("\n  _______________%s_______________\n\n",MonthShortName(Month).c_str());
 * // Print the columns    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
 * // Print appropriate spacesint i; for (i = 0; i < current; i++)
 * printf("     "); for (int j = 1; j <= NumberOfDays; j++) {         printf("%5d", j);
 * if (++i == 7){i = 0;printf("\n");}}
 * printf("\n  _________________________________\n"); }
 * short ReadMonth() { short Month;     cout << "\nPlease enter a Month? ";
 * cin >> Month; return Month; }
 * short ReadYear() { short Year;
 * cout << "\nPlease enter a year? ";
 * cin >> Year; return Year; }
 * int main() {
 * short Year = ReadYear();
 * short Month = ReadMonth();
 * PrintMonthCalendar(Month, Year);
 * system("pause>0"); return 0;
 * }
 * */