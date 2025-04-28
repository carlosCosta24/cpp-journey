#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    int num = 0;

    for (int i = 0; i <= 5; i++)
    {
        cout << "Enter a number below 50: " << endl;
        cin >> num;

        if (num > 50)
        {
            cout << "This value will not be calculated" << endl;
            continue;
        }
        sum += num;
    }

    cout << "the sum is: " << sum << endl;

    return 0;
}