#include <iostream>
using namespace std;

int main()
{
    short First, second;
    cout << "Enter the first number: ";
    cin >> First;
    cout << "Enter the second number: ";
    cin >> second;

    cout << First << " = " << second << "  is " << (First == second) << endl;
    cout << First << " != " << second << " is " << (First != second) << endl;
    cout << First << " > " << second << "  is " << (First > second) << endl;
    cout << First << " < " << second << "  is " << (First < second) << endl;
    cout << First << " >= " << second << "  is " << (First >= second) << endl;
    cout << First << " <= " << second << "  is " << (First <= second) << endl;

    return 0;
}