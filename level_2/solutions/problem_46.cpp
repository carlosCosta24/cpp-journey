#include <iostream>
using namespace std;

void LetterPrinter()
{
    for (int i = 65; i <= 90; i++)
    {
        cout << char(i) << endl;
    }
}

int main()
{
    LetterPrinter();
    return 0;
}