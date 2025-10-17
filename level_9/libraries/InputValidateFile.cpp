#include "clsInputValidate.h"
#include <iostream>
using namespace std;

int main(){
    // cout << clsInputValidate::IsNumberBetween(6,6,10) << endl;
    // cout << clsInputValidate::IsNumberBetween(6.2,6.0,10.5) << endl;
    // cout << clsInputValidate::IsDateBetween(clsMyDate(),clsMyDate(14,10,2025),clsMyDate(20,10,2025)) << endl;
    // cout << clsInputValidate::IsDateBetween(clsMyDate(),clsMyDate(20,10,2025),clsMyDate(14,10,2025)) << endl;
    cout << "enter a number between 1 and 5";
    int Number = clsInputValidate::IsNumberBetween(1,5,"Number is not in the range!!");
    cout << Number << endl;

}
