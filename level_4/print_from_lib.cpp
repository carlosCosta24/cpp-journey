//
// Created by carlos on 5/12/25.
//
#include <iostream>
#include "library.h"
#include "my_input.h"
using namespace std;
using namespace MyLib;
using namespace MyInput;

int main() {

    int Num1 = ReadNum();
    int Num2 = ReadNum();

    cout << "The sum of your numbers is:  "<<Calculator(Num1,Num2)<< endl;


}