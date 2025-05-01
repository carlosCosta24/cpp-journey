#include <iostream>
using namespace std;

int main()
{
    int num, sum = 0;

    while (true)
    {
        cout << "Enter a number or (-99 to exit): ";
        cin >> num;

        if (num == -99)
        {
            break;
        }
        sum += num;
    }

    cout << "The sum is: " << sum << endl;

    return 0;
}