#include <iostream>
using namespace std;

int main()
{

    int num, fact = 1;

    cout << "Enter the number to calculate number! ";
    cin >> num;

    while (num <= 0)
    {
        cout << "Wrong number enter a positive number: ";
        cin >> num;
    }
    for (int i = num; i >= 1; i--)
    {
        fact *= i;
    }

    cout << num << "! is: " << fact << endl;
}