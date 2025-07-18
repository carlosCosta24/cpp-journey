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
bool IsWithinPeriod(stPeriod Period, stDate Date) {
    /*
    return (IsDateOneAfterDateTwo(Date, Period.Start) &&
        IsDate1BeforeDate2(Date, Period.End));
    */
    // more optimized way
    return !(DateCompare( Date, Period.Start) == enCompare::Before ||
        DateCompare( Date, Period.End) == enCompare::After);
}

int main() {
    stPeriod Period = ReadPeriod();
    cout << "Enter Date to check: "<< endl;
    stDate Day = ReadDate();

    IsWithinPeriod(Period, Day)?
    cout<< "Yes, Date is within period"<< endl:
    cout << "No, Date outside the period "<< endl;

    return 0;

}