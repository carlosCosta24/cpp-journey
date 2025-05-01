#include <iostream>
using namespace std;

string ReadPin()
{
    string Pin = "";

    cout << "Enter the pin: " << endl;
    cin >> Pin;

    return Pin;
}

bool Login()
{
    string PinCode = "";
    int Tries = 3;

    do
    {
        PinCode = ReadPin();

        if (PinCode == "1234")
        {
            cout << "\e[32mCorrect Pin! \e[0m" << endl;

            return true;
        }
        else
        {

            Tries--;
            cout << "\e[31mWrong Pin " << Tries << " Tries left! \e[0m" << endl;
        }

    } while (Tries >= 1 && PinCode != "1234");
    return false;
}

int main()
{

    if (Login())
        cout << "Your balance is 7500$" << endl;
    else
        cout << "\e[31mYour card is blocked! \e[0m" << endl;

    return 0;
}