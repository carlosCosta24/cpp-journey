#pragma once
#include "clsCurrency.h"
#include "clsUtil.h"
#include <iostream>
using namespace std;

class clsCurrencyMenu {
    private:
    enum enOptions {enList = 1, enFind = 2, enUpdate = 3, enCalculate = 4};
    void _ListAllCurrencies() {
        cout << "\n Listing all currencies" << endl;
        //clsCurrency::GetCurrencyList();
    }
    void _FindCurrency() {
        cout << "\n Find Currency" << endl;
    }
    void _UpdateCurrency() {
        cout << "\n Update Currency" << endl;
    }
    void _CurrencyCalculator() {
        cout << "\n Currency Calculator" << endl;
    }
    void _PerformMenu(enOptions Option) {
        switch (Option) {
            case enOptions::enList: {
                _ListAllCurrencies();
                break;
            }
            case enOptions::enFind: {
                _FindCurrency();
                break;
            }
            case enOptions::enUpdate: {
                _UpdateCurrency();
                break;
            }
            case enOptions::enCalculate: {
                _CurrencyCalculator();
                break;
            }
        }
    }
    public:
    void PrintMenu() {

    }

};