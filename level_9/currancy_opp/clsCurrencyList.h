#pragma once
#include "clsCurrency.h"
#include <iomanip>
#include <vector>
using namespace std;

class clsCurrencyList {
    private:
    static void _ScreenHeader(string Header, string SubHeader = "") {
        cout << "\t\t\t\t\t\t\t\t\t ★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★\n";
        cout << "\t\t\t\t\t\t\t\t\t\t"<< Header ;
        if (SubHeader != "") {
            cout << "\n\t\t\t\t\t\t\t\t " << SubHeader;
        }
        cout << "\n\t\t\t\t\t\t\t\t\t ★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★\n";

    }
    static void _PrintCurrencyList(clsCurrency Currency) {
        cout << "| " << left << setw(30) << Currency.GetCountry();
        cout << "| " << left << setw(10) << Currency.GetCurrencyCode();
        cout << "| " << left << setw(30) << Currency.GetCurrencyName();
        cout << "| " << left << setw(15) << Currency.GetRate();
    }
    public:
    static void ListCurrencyScreen() {
        vector <clsCurrency> vCurrencies =  clsCurrency::GetCurrencyList();
        string Title = "\t Currency List Screen";
        string SubTitle = "\t\t\t (" + to_string(vCurrencies.size()) + ") Currency(s).";

        _ScreenHeader(Title, SubTitle);
        cout << "\n-------------------------------------------------------------------------------"
        "---------------------------\n";
        cout << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(10) << "Code";
        cout << "| " << left << setw(30) << "Name";
        cout << "| " << left << setw(15) << "Rate/(1$)";
        cout << "\n-------------------------------------------------------------------------------------"
                "---------------------\n";
        if (vCurrencies.size() == 0) {
            cout << "\t\t\t\t\t\t No Currencies found \n";
        }
        else {
            for (clsCurrency Currency : vCurrencies) {
                _PrintCurrencyList(Currency);
                cout << endl;
            }

        }
        cout << "\n-------------------------------------------------------------------------------------"
            "---------------------\n";
    }
};