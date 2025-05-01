#include <iostream>
using namespace std;

int main()
{

    int i = 1, sum = 0, num;
    cout << "Enter the number: ";
    cin >> num;

    while (i <= num)
    {
        if (i % 2 == 0)
        {
            sum += i;
        }
        i++;
    }
    cout << "The odd even sum is: " << sum << endl;
    return 0;
}