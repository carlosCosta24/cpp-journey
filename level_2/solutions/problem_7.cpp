#include <iostream>
using namespace std;

int ReadNumber()
{

    int num;

    cout << "Enter the number: " << endl;
    cin >> num;

    return num;
}

float GetHalfNumber(int num)
{
    return (float)num / 2;
}

void ResultPrinter(float num)
{
    string Result = "Half of " + to_string(num) + " is " + to_string(GetHalfNumber(num));

    cout << endl
         << Result
         << endl;
}

int main()
{
    ResultPrinter(ReadNumber());
    return 0;
}