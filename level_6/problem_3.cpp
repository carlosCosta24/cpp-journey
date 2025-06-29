#include <iostream>
#include <string>
using namespace std;


bool YearChecker(int Input) {

return (Input % 4 == 0 && Input % 100 != 0) || (Input % 400 == 0);
}

int ReadYear(){
    int Input;
    cout << "Please enter a Year? ";
    cin >> Input;
    return Input;
}

int main(){
    int Input = ReadYear();
    bool Result = YearChecker(Input);
    if (Result) {
        cout << "Leap Year";
    }else {
        cout << "Not a Leap Year";
    };
    return 0;
};
