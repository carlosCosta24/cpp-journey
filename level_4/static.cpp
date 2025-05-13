#include <iostream>
using namespace std;

void MyFun() {
    static int counter = 0;
    cout<< counter << endl;
    counter++;
}

int main() {
   MyFun();
   MyFun();
   MyFun();
    return 0;
}