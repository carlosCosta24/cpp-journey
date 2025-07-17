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
bool IsDate1BeforeDate2(stDate First, stDate Second) {
    return  (First.Year < Second.Year) ? true :
    ((First.Year == Second.Year) ? (First.Month < Second.Month ? true :
    (First.Month == Second.Month ? First.Day < Second.Day : false)) : false);
}
bool DateIsEqual(stDate First, stDate Second) {
    return (First.Year == Second.Year) ?
    ((First.Month == Second.Month) ? ((First.Day == Second.Day) ? true : false) : false) : false;
}
/*bool IsDateOneAfterDateTwo(stDate First, stDate Second) {
    if (First.Year > Second.Year) {
        return true;
    }
    else if (First.Year == Second.Year) {
        if (First.Month > Second.Month)
            return true;
        else if (First.Month == Second.Month) {
            return First.Day > Second.Day;
        }
        return false;
    }
    return false;
}*/
// optimized version
bool IsDateOneAfterDateTwo(stDate First, stDate Second) {
    return (!IsDate1BeforeDate2(First, Second)) && !DateIsEqual(First, Second);
}

int main() {
    cout << "Please enter a First Date: ";
    cout << endl;
    stDate First = ReadDate();
    cout << "Please enter a Second Date: ";
    cout << endl;
    stDate Second = ReadDate();


    (IsDateOneAfterDateTwo(First, Second))?
    cout<< "Yes, date one is after date tow ":
    cout << "No, date one is before date tow";


}