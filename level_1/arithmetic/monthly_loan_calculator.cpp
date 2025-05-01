#include <iostream>
using namespace std;

int main()
{
    double loan_total, months;

    cout << "Enter the desired loan amount: ";
    cin >> loan_total;

    cout << "Enter the desired paying months : ";
    cin >> months;

    cout << loan_total / months << "$ Dollar" << endl;

    return 0;
}