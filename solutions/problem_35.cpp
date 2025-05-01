#include <iostream>
using namespace std;

struct stPiggyBankContent
{
    int Pennies, Nickel, Dimes, Quarters, Dollars;
};

stPiggyBankContent ReadPiggyBank()
{
    stPiggyBankContent bank;

    cout << "Enter the number of pennies: " << endl;
    cin >> bank.Pennies;

    cout << "Enter the number of nickel: " << endl;
    cin >> bank.Nickel;

    cout << "Enter the number of dimes: " << endl;
    cin >> bank.Dimes;

    cout << "Enter the number of quarters: " << endl;
    cin >> bank.Quarters;

    cout << "Enter the number of dollars: " << endl;
    cin >> bank.Dollars;

    return bank;
}

int CalculateTotalPennies(stPiggyBankContent PiggyBank)
{
    int Total = PiggyBank.Pennies * 1 +
                PiggyBank.Nickel * 5 +
                PiggyBank.Dimes * 10 +
                PiggyBank.Quarters * 25 +
                PiggyBank.Dollars * 100;
    return Total;
}

int main()
{
    int totalPennies = CalculateTotalPennies(ReadPiggyBank());
    cout << "Total Pennies = " << totalPennies << endl;
    cout << "Total Dollars = " << (float)totalPennies / 100 << endl;
}