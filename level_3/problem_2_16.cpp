#include <iostream>
#include <string>
using namespace std;

void PatternPrinter()
{
    string word = "";
    for (int i = 65; i < 91; i++)
    {
        for (int j = 65; j < 91; j++)
        {
            for (int k = 65; k < 91; k++)
            {
                word += char(i);
                word += char(j);
                word += char(k);

                cout << word << endl;

                word = "";
            }
        }
        cout << endl;
    }
}

int main()
{
    PatternPrinter();
    return 0;
}