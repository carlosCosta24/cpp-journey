#include <iostream>
using namespace std;

void NUmberPrinter(int N)
{
    for (int i = 0; i <= N; i++)
    {
        cout << i << endl;
    }
}
int main()
{
    int num;
    cout << "Enter the number to print: ";
    cin >> num;

    NUmberPrinter(num);
}