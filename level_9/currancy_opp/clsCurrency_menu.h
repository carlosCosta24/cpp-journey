#pragma once
#include "clsCurrency.h"
#include "clsUtil.h"
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
using namespace std;

class clsCurrencyMenu {
    private:
    static void _ScreenHeader(string Header, string SubHeader = "") {
        cout << "\t\t\t\t\t\t\t\t\t ★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★\n";
        cout << "\t\t\t\t\t\t\t\t\t\t"<< Header ;
        if (SubHeader != "") {
            cout << "\n\t\t\t\t\t\t\t\t " << SubHeader;
        }
        cout << "\n\t\t\t\t\t\t\t\t\t ★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★\n";

    }
    static short _ReadManageUsersOption() {
        short Option = 0;
        cout << "Please enter your choice: ";
        Option = clsInputValidate::ReadIntNumberBetween(1,5,"Invalid Input, Try agin!");
        return Option;
    }
    enum enOptions {enList = 1, enFind = 2, enUpdate = 3, enCalculate = 4, enMainMenu = 5};
    static void _ListAllCurrencies() {
        cout << "\n Listing all currencies" << endl;
        //clsCurrency::GetCurrencyList();
    }
    static void _FindCurrency() {
        cout << "\n Find Currency" << endl;
    }
    static void _UpdateCurrency() {
        cout << "\n Update Currency" << endl;
    }
    static void _CurrencyCalculator() {
        cout << "\n Currency Calculator" << endl;
    }
      static void _PerformMenu(enOptions Option) {
        switch (Option) {
            case enOptions::enList: {
                _ListAllCurrencies();
                PrintMenu();
                break;
            }
            case enOptions::enFind: {
                _FindCurrency();
                PrintMenu();
                break;
            }
            case enOptions::enUpdate: {
                _UpdateCurrency();
                PrintMenu();
                break;
            }
            case enOptions::enCalculate: {
                _CurrencyCalculator();
                PrintMenu();
                break;
            }
            case enOptions::enMainMenu: {
                PrintMenu();
            }
        }
    }
    public:
    static void PrintMenu() {
        clsCurrency Currency = clsCurrency::FindCurrencyByCode("usd");
        _ScreenHeader("\t\t Currency Exchange Main Screen");
        cout << setw(37) << left <<""<< "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\t Currency Exchange Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List All Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformMenu((enOptions) _ReadManageUsersOption());

    }

};