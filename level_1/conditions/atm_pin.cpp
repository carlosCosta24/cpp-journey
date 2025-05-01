#include <iostream>
using namespace std;

void PinChecker(int pin)
{
    int correct = 1234;

    if (pin == correct)
    {
        cout << "your balance is: 7500$" << endl;
    }
    else
    {
        cout << "Wrong Pin" << endl;
    }
}

int main()
{
    int pin;
    cout << "Enter the pin: ";
    cin >> pin;

    PinChecker(pin);

    return 0;
}