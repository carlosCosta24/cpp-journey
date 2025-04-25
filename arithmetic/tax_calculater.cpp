#include <iostream>
using namespace std;

int main()
{
    double bill_value, ten_percentage, sales_percentage, total;

    cout << "Enter the bill value: ";
    cin >> bill_value;

    ten_percentage = bill_value * 0.10;
    total = bill_value + ten_percentage;
    sales_percentage = total * 0.16;
    total = total + sales_percentage;

    cout << total << endl;

    return 0;
}