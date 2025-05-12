#include <iostream>
#include "my_input.h"

using namespace std;

void NumberChecker() {
    int Number = MyInput::ReadNum("Please enter a  number: ? ");
     (Number < 0) ? cout<< "This is a negative number!  " : (Number == 0 )? cout<< "This is a zero. ":
    cout<< "This is a positive number";
}

int main() {
    NumberChecker();

}