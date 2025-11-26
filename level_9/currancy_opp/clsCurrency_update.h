#pragma once
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsString.h"


class clsCurrencyUpdate {
    private:
    static void _PrintCurrencyCard(clsCurrency Currency) {
        cout << "\nCurrency Card:";
        cout << "\n___________________";
        cout << "\nCountry   : " << Currency.GetCountry();
        cout << "\nCode      : " << Currency.GetCurrencyCode();
        cout << "\nName      : " << Currency.GetCurrencyName();
        cout << "\nRate      : " << Currency.GetRate();
        cout << "\n___________________\n";
    }
    static void _UpdateCurrencyRate(string Code , float Rate ) {
        clsCurrency Currency = Currency.FindCurrencyByCode(Code);
        if (Currency.IsEmpty()) {
            cout << "\nCurrency is not available or empty.";
        }else {
            Currency.UpdateRate(Rate);
            cout << "\nCurrency Rate hase been updated successfully :-)" << endl;
            _PrintCurrencyCard(Currency);
        }
    }
    public:
    static void UpdateScreen() {
        cout << "Please enter Currency Code: "<< endl;
        string Code = clsInputValidate::ReadString();
        clsCurrency Currency = Currency.FindCurrencyByCode(Code);
        _PrintCurrencyCard(Currency);
        char Answer;
        cout << "Are you sure you want to update the rate of this currency y/n? "<< endl;
        cin >> Answer ;
        Answer = clsString::Capitalize(Answer);
        if (Answer == 'Y') {
            cout << "\n Update Currency Rate" << endl;
            cout << "_________________________________" << endl;
            cout << "Enter New Rate: " << endl;
            float NewRate = clsInputValidate::ReadFloatNumber();
            _UpdateCurrencyRate(Code, NewRate);
        }else {
            cout << "\n Currency not updated "<< endl;
        }
    }
};