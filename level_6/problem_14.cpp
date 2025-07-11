#include <iostream>
#include <string>
using namespace std;

struct stDate {
    short Year;
    short Month;
    short Day;
};
void ReadInput(short& Year, short& Month, short& Day){

    cout << "Please enter a Day? ";
    cin >> Day;
    cout << "Please enter a Month? ";
    cin >> Month;
    cout << "Please enter a Year? ";
    cin >> Year;


}
bool DateIsEqual(stDate First, stDate Second) {
    return (First.Year == Second.Year) ?
    ((First.Month == Second.Month) ? ((First.Day == Second.Day) ? true : false) : false) : false;
}
int main() {
    stDate First;
    stDate Second;
    ReadInput(First.Year, First.Month, First.Day);
    ReadInput(Second.Year, Second.Month, Second.Day);
    if (DateIsEqual(First, Second)) {
        cout << "Yes, Date1 equal Date2";
    }else {
        cout << "No, Date1 doesn't equal Date2";
    }
}