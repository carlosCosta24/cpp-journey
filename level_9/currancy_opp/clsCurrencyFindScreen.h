#pragma once
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;

class clsCurrencyFindScreen {
private:
    enum enOption {enFindByCode = 1, enFindByName = 2};
    static void _PrintCurrencyCard(clsCurrency Currency) {
        cout << "\nCurrency Card:";
        cout << "\n___________________";
        cout << "\nCountry   : " << Currency.GetCountry();
        cout << "\nCode      : " << Currency.GetCurrencyCode();
        cout << "\nName      : " << Currency.GetCurrencyName();
        cout << "\nRate      : " << Currency.GetRate();
        cout << "\n___________________\n";
    }
    static short _ReadFindOptions() {
        short Choice  = clsInputValidate::ReadIntNumberBetween
        (1,2, "Invalid input, Try again!: ");
        return Choice;
    }
    static void FindByCode() {
        string Code = clsInputValidate::ReadString
        ("Please Enter Code:");
        clsCurrency Target = clsCurrency::FindCurrencyByCode(Code);
        if (Target.IsEmpty()) {
            cout << "Currency not found :-(" << endl;
        }else {
            _PrintCurrencyCard(Target);
        }
    }
    static void FindByName() {
        string Name = clsInputValidate::ReadString
        ("Please Enter Country name: ");
        clsCurrency Target = clsCurrency::FindCurrencyByName(Name);
        if (Target.IsEmpty()) {
            cout << "Currency not found :-(" << endl;
        }else {
            _PrintCurrencyCard(Target);
        }
    }
    static void _PerformFindOperation(enOption Option) {
        switch (Option) {
            case enOption::enFindByCode: {
                FindByCode();
                break;
            }
            case enOption::enFindByName: {
                FindByName();
                break;
            }
        }
    }
    public:
    static void FindCurrencyScreen() {
        cout << "\nFind By: [1] Code or [2] Country ? "<< endl;
         _PerformFindOperation((enOption)_ReadFindOptions());
    }
};