#include <iostream>
using namespace std;

int main()
{
    float Mark1, Mark2, Mark3, avg;

    cout << "Enter your first mark: ";
    cin >> Mark1;

    cout << "Enter your second mark: ";
    cin >> Mark2;

    cout << "Enter your third mark: ";
    cin >> Mark3;

    avg = (Mark1 + Mark2 + Mark3) / 3;

    cout << avg << endl;

    if (avg >= 50)
    {
        cout << "you passed congrats!! " << endl;
    }
    else
    {
        cout << "you failed good luck next time!! " << endl;
    }

    return 0;
}