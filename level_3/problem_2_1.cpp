#include <iostream>
using namespace std;

void Headerprinter()
{

    cout << "\n\n\t\t\t Multiplication table from 1 to 10 \n\n";
    cout << "\t";

    cout << "\n-----------------------------------------------------------------------------------\n";

    for (int i = 0; i <= 9; i++)
    {

        cout << i + 1 << "\t";
    }
    cout << "\n-----------------------------------------------------------------------------------\n";

    cout << endl;
}

string ColumSeparator(int Num)
{
    if (Num < 10)
        return "  |";
    else
        return " |";
}
void MultiplicationPrinter()
{
    Headerprinter();
    for (int i = 1; i <= 10; i++)
    {
        cout << " " << i << ColumSeparator(i) << "\t";
        for (int j = 1; j <= 10; j++)
        {
            cout << i * j << "\t";
        }
        cout << endl;
    }
}

int main()
{

    MultiplicationPrinter();
    return 0;
}