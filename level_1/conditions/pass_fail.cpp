#include <iostream>
using namespace std;

int main()
{
    int Mark;

    cout << "Enter your mark: ";
    cin >> Mark;

    if (Mark >= 50)
    {
        cout << "you passed congrats!! " << endl;
    }
    else
    {
        cout << "you failed good luck next time!! " << endl;
    }

    return 0;
}