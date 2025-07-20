#include <iostream>
using namespace std;
struct stDate {
    short Year;
    short Month;
    short Day;
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
bool IsLongMonth(int month) {

    return month == 1 || month == 3 || month == 5 ||
           month == 7 || month == 8 || month == 10 || month == 12;
}
bool YearChecker(int Input) {

    return (Input % 4 == 0 && Input % 100 != 0) || (Input % 400 == 0);
}
short NumberOfDays(int Year , int Month) {

    if (Month < 1 || Month > 12) return 0;
    return(Month == 2)
    ?(YearChecker(Year)?  29 : 28)
    : ((IsLongMonth(Month))? 31: 30);
}
// original solution
/*
 *bool IsValidDate(stDateDate) {
 *if (Date.Day < 1 || Date.Day>31) return false;
 *if (Date.Month < 1 || Date.Month>12) return false;
 *if (Date.Month == 2)  {
 *if (isLeapYear(Date.Year))
 *{
 *if (Date.Day > 29) return false;
 * else
 * {
 * if (Date.Day > 28)
 * return false;
 * }
 * }
 *
 */
bool IsDateValid(stDate Date) {
    short Days= NumberOfDays(Date.Year, Date.Month);
    return (Date.Day >= 1 && Date.Day <= Days &&
            Date.Month >= 1 && Date.Month <= 12 );

}

int main() {
    stDate Date;
    cout << "Please enter a date: "<< endl;
    Date = ReadDate();
    IsDateValid(Date)?
    cout << "Yes, Date is a valid date." << endl:
    cout << "No, Date is not a valid date." << endl;

}
