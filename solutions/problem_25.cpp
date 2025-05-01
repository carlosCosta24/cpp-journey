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

int ReadUntilTrue(int start, int End)
{

    int Age = 0;
    do
    {
        Age = ReadAge();

    } while (!ValidateNumberInRange(Age, start, End));

    return Age;
}

void ResultPrinter(int Age)
{

    cout << "Your age is: " << Age << endl;
}

int main()
{

    ResultPrinter(ReadUntilTrue(18, 45));
    return 0;
}