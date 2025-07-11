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
bool DateIsLessThan(stDate First, stDate Second) {
    if (First.Year < Second.Year) {
        return true;
    }else if (First.Year == Second.Year) {
        if (First.Month < Second.Month) {
            return true;
        }else if (First.Month == Second.Month) {
            return First.Day < Second.Day;
    }
    }
    return false;
}
int main() {
    stDate First;
    stDate Second;
    ReadInput(First.Year, First.Month, First.Day);
    ReadInput(Second.Year, Second.Month, Second.Day);
    if (DateIsLessThan(First, Second)) {
        cout << "Yes, Date1 is less than Date2";
    }else {
        cout << "No, Date1 is Not less than Date2";

    }
}