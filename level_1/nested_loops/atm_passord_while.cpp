#include <iostream>
using namespace std;

int main()
{
    int password = 1234, user_input, tries = 3;

    cout << "Enter your password: ";
    cin >> user_input;

    if (user_input == password)
    {
        cout << "Your balance is: 75000$" << endl;
    }
    else
    {
        while (tries > 0)
        {
            cout << "Wrong password, you have " << tries << " tries left!" << endl;
            cout << "Enter your password again!" << endl;
            cin >> password;
            tries--;
        }
        cout << "Card is blocked!" << endl;
    }
}