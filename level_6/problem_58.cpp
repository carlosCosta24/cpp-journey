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
bool DateIsEqual(stDate First, stDate Second) {
    return (First.Year == Second.Year) ?
    ((First.Month == Second.Month) ? ((First.Day == Second.Day) ? true : false) : false) : false;
}
bool IsDate1BeforeDate2(stDate First, stDate Second) {
    return  (First.Year < Second.Year) ? true :
    ((First.Year == Second.Year) ? (First.Month < Second.Month ? true :
    (First.Month == Second.Month ? First.Day < Second.Day : false)) : false);
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
int main() {
    cout << "Please enter a First period: ";
    cout << endl;
    stPeriod First = ReadPeriod();
    cout << "Please enter a Second period: ";
    cout << endl;
    stPeriod Second = ReadPeriod();


    (IsOverlap(First, Second))?
    cout << "Yes, Period overlaps":
    cout<< "No, There is no overlaps";

}