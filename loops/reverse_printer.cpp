#include <iostream>
using namespace std;

void NUmberPrinter(int N)
{
    for (int i = N; i >= 1; i--)
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