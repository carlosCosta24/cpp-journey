#pragma once
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsString.h"
using namespace std;

class clsCurrencyCalculator {
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
    static float _ExchangeToUsd(clsCurrency Currency, float Amount) {
        return Amount / Currency.GetRate();
    }
    static float _ExchangeFromUsdToForeign(clsCurrency Currency, float Amount) {
        return Amount * Currency.GetRate();
    }
    static clsCurrency _ReadCurrencyCode(string Message) {
        string Code = "";
        cout << Message << endl;
        cin >> Code;
        while (!clsCurrency::IsCurrencyExist(Code)) {
            cout << "Invalid Code! Try Again." << endl;
            cin >> Code;
        }
        return clsCurrency::FindCurrencyByCode(Code);
    }
    void static _ExchangeCalculator() {
        string Answer;
        do {
            clsCurrency From = _ReadCurrencyCode("Please Enter Currency 1 Code: ");
            clsCurrency To = _ReadCurrencyCode("Please Enter Currency 2 Code: ");
            cout << "Enter Amount to Exchange : ";
            float Amount = clsInputValidate::ReadFloatNumber();
            cout << "\nExchange Calculator:";
            cout << "\n___________________";

            if (To.GetCurrencyCode() == "USD") {

                float Rate = _ExchangeToUsd(From, Amount);
                _PrintCurrencyCard(From);
                cout << Amount << " " <<From.GetCurrencyCode() << " = " << Rate << " USD"<<endl;

            }else {

                float FirstRateToUsd = _ExchangeToUsd(From, Amount);
                cout << "\nconvert From: "<< endl;
                cout << "\n___________________";
                _PrintCurrencyCard(From) ;
                cout << Amount << From.GetCurrencyCode() << " = " << FirstRateToUsd << " USD" <<endl;
                cout << "converting from usd to: "<< endl;
                cout << "To: ";
                cout << "\n___________________";
                _PrintCurrencyCard(To);
                float ExchangeResult = _ExchangeFromUsdToForeign(To,FirstRateToUsd);
                cout << Amount <<" "<< From.GetCurrencyCode() << " = "
                << ExchangeResult << " "<<To.GetCurrencyCode()<<endl;
            }
                cout << "Do you want to perform another calculation y/n ? "<< endl;
                Answer = clsInputValidate::ReadString();
                Answer = clsString::Capitalize(Answer);
        } while (Answer == "Y");
    };
    public:
    static void CurrencyCalculatorScreen() {
        _ExchangeCalculator();
    }
};