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
            cout << "\e[31mWrong Pin, Try again! \e[0m" << endl;
        }

    } while (PinCode != "1234");
    return false;
}

int main()
{

    if (Login())
        cout << "Your balance is 7500$" << endl;
}