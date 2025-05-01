#include <iostream>
using namespace std;

int main()
{
    int num;
    do
    {
        cout << "Enter a number between 10 and 20: " << endl;
        cin >> num;

    } while (num >= 10 && num <= 20);

    return 0;
}