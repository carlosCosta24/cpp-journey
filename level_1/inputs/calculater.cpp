#include <iostream>
using namespace std;

int main()
{
     short FirstNum, SecondNum, ThirdNum;

     cout << "Enter the first number: ";
     cin >> FirstNum;
     cout << "Enter the second number: ";
     cin >> SecondNum;
     cout << "Enter the third number: ";
     cin >> ThirdNum;
     cout << endl;

     cout << FirstNum << " +" << endl;
     cout << SecondNum << " +" << endl;
     cout << ThirdNum << endl
          << endl;
     cout << "------------------------" << endl
          << endl;
     cout << "Total = " << FirstNum + SecondNum + ThirdNum << endl;

     return 0;
}