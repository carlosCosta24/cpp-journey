#include <iostream>
#include <memory>
#include <string>
using namespace std;

int ReadYear(){
    int Input;
    cout << "Please enter a Year? ";
    cin >> Input;
    return Input;
}

bool CheckYear(int Input) {

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

int main(){
    int Input = ReadYear();
    bool Result = CheckYear(Input);
    if (Result) {
        cout << "Leap Year";
    }else {
        cout << "Not a Leap Year";
    };
        return 0;
};
