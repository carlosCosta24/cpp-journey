#include <iostream>
using namespace std;

int main()
{
    int num, power, result = 1;

    cout << "Enter the number: ";
    cin >> num;

    cout << "Enter the power: ";
    cin >> power;

    while (power > 0)
    {
        result *= num;
        power--;
    }

    cout << result << endl;

    return 0;
}