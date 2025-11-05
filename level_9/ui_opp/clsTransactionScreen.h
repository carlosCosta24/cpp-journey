#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
#include <iomanip>

class clsTransactionScreen : protected clsScreen {
    private:
    enum enTransationMenuOptions {
        enDeposit = 1, enWithdraw = 2, enShowTotalBalance = 3,
        enShowTransferMenu = 4, enShowTransferLogs =5, enShowMainMenu = 6
    };
    static short _ReadTransactionMenuOption() {
        cout << setw(37)<< left << "Chose your option? [1 to 6]: " << endl;
        short Option = 0;
        return Option = clsInputValidate::ReadIntNumberBetween(1,6,"Invalid option, Try again!");
    }
    static void _DepositScreen()
    {
        clsDepositScreen::DepositScreen();
    }

    static void _WithdrawScreen()
    {
        clsWithdrawScreen::WithdrawScreen();
    }

    static void _TotalBalancesScreen()
    {
        clsTotalBalancesScreen::TotalBalancesScreen();
    }
    static void _ShowTransferScreen() {
        clsTransferScreen::ShowTransferScreen();
    }
    static void _ShowTransferLogScrrn() {
        clsTransferLogScreen::ShowTransferLogScreen();
    }

    static void _GoBackToTransactionsScreen()
    {
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
            case enTransationMenuOptions::enShowTransferMenu: {
                _ShowTransferScreen();
                _GoBackToTransactionsScreen();
                break;
            }
            case enTransationMenuOptions::enShowTransferLogs: {
                _ShowTransferLogScrrn();
                _GoBackToTransactionsScreen();
                break;
            }
            case enTransationMenuOptions::enShowMainMenu: {

            }
        }
    }
    public:
    static void TransactionsMenu() {
        if (!_AccessChecker(clsUser::enPermissions::pTransactions)) {
            return;
        }
        _ScreenHeader("\t Transaction Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformTransactionMenuOption((enTransationMenuOptions) _ReadTransactionMenuOption());

    }
};
