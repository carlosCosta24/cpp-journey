#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
enum enChar
{
    small = 1,
    capital = 2,
    special = 3,
    digit = 4,

};

char RandomPrinter(enChar Char)
{
    switch (Char)
    {
    case enChar::small:
        cout << char(RandomNumber(97, 122));
        break;
    case enChar::capital:
        cout << char(RandomNumber(65, 90));
        break;
    case enChar::special:
        cout << char(RandomNumber(33, 47));
        break;
    case enChar::digit:
        cout << char(RandomNumber(48, 57));
        break;
    }
    return '\0';
}

int main()
{
    srand((unsigned)time(NULL));

    cout << RandomPrinter(enChar::capital) << endl;
    cout << RandomPrinter(enChar::small) << endl;
    cout << RandomPrinter(enChar::special) << endl;
    cout << RandomPrinter(enChar::digit) << endl;

    return 0;
}