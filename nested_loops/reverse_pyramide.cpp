#include <iostream>
using namespace std;

int main()
{

    for (int i = 0; i <= 10; i++)
    {
        for (int j = 10 - i; j >= 1; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
