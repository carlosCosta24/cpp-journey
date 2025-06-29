#include <iostream>
#include <string>
using namespace std;
int ReadYear(){
    int Input;
    cout << "Please enter a Year? ";
    cin >> Input;
    return Input;
}
/*
short NumberOfDaysInAYear(shortYear) { return  isLeapYear(Year) ? 366 : 365; }
short NumberOfHoursInAYear(shortYear) { return  NumberOfDaysInAYear(Year) * 24; }
int NumberOfMinutesInAYear(shortYear) { return  NumberOfHoursInAYear(Year) * 60; }
int NumberOfSecondsInAYear(shortYear) { return  NumberOfMinutesInAYear(Year) * 60; }
 */
bool YearChecker(int Input) {

    return (Input % 4 == 0 && Input % 100 != 0) || (Input % 400 == 0);
}

void YearDetails(int Input) {
    if (YearChecker(Input)) {
        cout << "Number of Days in" << "[" << Input << "]" << "Is 366" <<endl;
        cout << "Number of Hours in" << "[" << Input << "]" << "Is 8784" <<endl;
        cout << "Number of Minutes in" << "[" << Input << "]" << "Is 527040" <<endl;
        cout << "Number of Minutes in" << "[" << Input << "]" << "Is 31622400" <<endl;

    }else {
        cout << "Number of Days in" << "[" << Input << "]" << "Is 365" <<endl;
        cout << "Number of Hours in" << "[" << Input << "]" << "Is 8760" <<endl;
        cout << "Number of Minutes in" << "[" << Input << "]" << "Is 525600" <<endl;
        cout << "Number of Minutes in" << "[" << Input << "]" << "Is 31536000" <<endl;

    }
}

int main(){
    int Input = ReadYear();
    YearDetails(Input);
    return 0;
};