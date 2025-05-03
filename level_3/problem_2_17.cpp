#include <iostream>
#include <string>
using namespace std;

string ReadPassword(string Message)
{
    string Password;

    cout << Message;
    cin >> Password;

    return Password;
}
bool PassWordFinder(string password)
{
    string word = "";
    int counter = 0;
    for (int i = 65; i < 91; i++)
    {
        for (int j = 65; j < 91; j++)
        {
            for (int k = 65; k < 91; k++)
            {
                counter++;
                word += char(i);
                word += char(j);
                word += char(k);

                cout << "Trail[" << counter << "]: " << word << endl;
                if (word == password)
                {

                    cout << "password is " << password << " Found after " << counter << " trial(s)" << endl;
                    return true;
                }

                word = "";
            }
        }
        cout << endl;
    }
    return false;
}

int main()
{
    PassWordFinder(ReadPassword("Enter the password all capital letter: "));

    return 0;
}