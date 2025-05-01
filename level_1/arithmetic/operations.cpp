#include <iostream>
using namespace std;

int main()
{
    short FirstNum, SecondNum;

    cout << "Enter the first number: ";
    cin >> FirstNum;

    cout << "Enter the second number: ";
    cin >> SecondNum;
    cout << endl;

    cout << FirstNum << " + " << SecondNum << " = " << FirstNum + SecondNum << endl;
    cout << FirstNum << " - " << SecondNum << " = " << FirstNum - SecondNum << endl;
    cout << FirstNum << " * " << SecondNum << " = " << FirstNum * SecondNum << endl;
    cout << FirstNum << " / " << SecondNum << " = " << FirstNum / SecondNum << endl;
    cout << FirstNum << " % " << SecondNum << " = " << FirstNum % SecondNum << endl;

    return 0;
}