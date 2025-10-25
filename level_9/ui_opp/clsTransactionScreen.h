#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include <iomanip>

class clsTransactionScreen : protected clsScreen {
    private:
    enum enTransationMenuOptions {
        enDeposit = 1, enWithdraw = 2, enShowTotalBalance = 3,
        enShowMainMenu = 4
    };
    static short _ReadTransactionMenuOption() {
        cout << setw(37)<< left << "Chose your option: " << endl;
        short Option = 0;
        return Option = clsInputValidate::ReadIntNumberBetween(1,4,"Invalid option, Try again!");
    }
    static void _DepositScreen()
    {
        clsDepositScreen::DepositScreen();
    }

    static void _WithdrawScreen()
    {
        cout << "\n Withdraw Screen will be here.\n";
    }

    static void _TotalBalancesScreen()
    {
        cout << "\n Balances Screen will be here.\n";
    }

    static void _GoBackToTransactionsScreen()
    {
        cout << "\n\nPress any key to go back to Transactions Menu...";
        TransactionsMenu();

    }
    static void _PerformTransactionMenuOption(enTransationMenuOptions Options) {
        switch (Options) {
            case enTransationMenuOptions::enDeposit: {
                _DepositScreen();
                _GoBackToTransactionsScreen();
                break;
            }
            case enTransationMenuOptions::enWithdraw: {
                _WithdrawScreen();
                _GoBackToTransactionsScreen();
                break;
            }
            case enTransationMenuOptions::enShowTotalBalance: {
                _TotalBalancesScreen();
                _GoBackToTransactionsScreen();
                break;
            }
            case enTransationMenuOptions::enShowMainMenu: {
                cout << "Will be here soon "<<endl;
            }
        }
    }
    public:
    static void TransactionsMenu() {

        _ScreenHeader("\t Transaction Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformTransactionMenuOption((enTransationMenuOptions) _ReadTransactionMenuOption());

    }
};