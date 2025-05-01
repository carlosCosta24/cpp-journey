#include <iostream>
using namespace std;

int main()
{
    double total, cashPaid;

    cout << "Enter the total of bill: ";
    cin >> total;

    cout << "Enter the cash paid: ";
    cin >> cashPaid;

    cout << cashPaid - total << endl;

    return 0;
}