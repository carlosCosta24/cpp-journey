#include <iostream>
using namespace std;

int MPower(int num, int m)
{

    int result = 1;

    for (int i = m; i >= 1; i--)
    {
        result *= num;
    }
    return result;
}

int main()
{
    int num, m;

    cout << "Enter the number: ";
    cin >> num;

    cout << "Enter the power: ";
    cin >> m;

    cout << MPower(num, m) << endl;
}