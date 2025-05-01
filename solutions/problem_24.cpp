#include <iostream>
using namespace std;

int ReadAge()
{

    int Age;

    cout << "please enter your age: ";
    cin >> Age;

    return Age;
}

bool ValidateNumberInRange(int Num, int From, int To)
{
    return (Num >= From && Num <= To);
}

void ResultPrinter(int Age)
{

    if (ValidateNumberInRange(Age, 18, 45))
        cout << Age << " Is valid age!! " << endl;
    else
        cout << Age << " Is not valid age!! " << endl;
}

int main()
{

    ResultPrinter(ReadAge());
    return 0;
}