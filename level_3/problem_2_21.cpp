#include <iostream>
#include <cstdlib>
using namespace std;
int ReadNumber(string Message)
{

    int Number;

    cout << Message;
    cin >> Number;

    return Number;
}

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
        return char(RandomNumber(97, 122));
        break;
    case enChar::capital:
        return char(RandomNumber(65, 90));
        break;
    case enChar::special:
        return char(RandomNumber(33, 47));
        break;
    case enChar::digit:
        return char(RandomNumber(48, 57));
        break;
    default:
        return '?';
    }
    return ' ';
}

string WordGenerator(enChar Char, short Num)
{
    string Word;
    for (int i = 0; i < Num; i++)
    {
        Word += RandomPrinter(Char);
    }
    return Word;
}
string KeysGenerator()
{
    string Key = "";

    Key = WordGenerator(enChar::capital, 4) + "-";
    Key += WordGenerator(enChar::capital, 4) + "-";
    Key += WordGenerator(enChar::capital, 2) + "-";
    Key += WordGenerator(enChar::capital, 4);

    return Key;
}

void KeysPrinter(short Num)
{
    for (int i = 0; i < Num; i++)
    {
        cout << "Key [" << i + 1 << "]: ";
        cout << KeysGenerator() << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    KeysPrinter(ReadNumber("Enter the number of keys: "));

    return 0;
}