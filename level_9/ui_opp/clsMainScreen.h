#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionScreen.h"
using namespace std;

class clsMainScreen: protected clsScreen {
    private:
    enum enMainMenuOp{enListClient =1, enAddClient =2, enDeleteClient=3, enUpdateClient=4,
            enFindClient=5, enShowTransactionMenu= 6, enManageUsers= 7, enExit= 8};

    static short _ReadMainMenuOP() {
            cout <<"Choose what you do Want [1 - 8]? ";
            short Choice  = clsInputValidate::ReadIntNumberBetween(1,8, "Invalid input, Try again!: ");
            return Choice;
        }
    static void _GoBackToMainMenu() {
            cout << "\nPress any key to go back to Main Menu...\n";
            
            ShowMainMenu();
        }
    static void _ShowAllClientsScreen()
        {
            clsClientListScreen::ShowClientList();
        }
    static void _ShowAddNewClientsScreen()
        {
            clsAddNewClientScreen::AddNewClientScreen();
        }
    static void _ShowDeleteClientScreen()
        {
            clsDeleteClientScreen::DeleteClientScreen();
        }

    static void _ShowUpdateClientScreen()
        {
            clsUpdateClientScreen::UpdateClient();
        }

    static void _ShowFindClientScreen()
        {
            clsFindClientScreen::FindClientScreen();
        }

    static void _ShowTransactionsMenue()
        {
            clsTransactionScreen::TransactionsMenu();
        }

    static void _ShowManageUsersMenue()
        {
            cout << "\nUsers Menu Will be here...\n";
        }

    static void _ShowEndScreen()
        {
            cout << "\nEnd Screen Will be here...\n";
        }
    static void _PerformMainMenuOp(enMainMenuOp Option) {
        switch (Option) {
            case enMainMenuOp::enListClient: {
                _ShowAllClientsScreen();
                _GoBackToMainMenu();
                break;
            }
            case enMainMenuOp::enAddClient: {
                _ShowAddNewClientsScreen();
                _GoBackToMainMenu();
                break;
            }
            case enMainMenuOp::enDeleteClient: {
                _ShowDeleteClientScreen();
                _GoBackToMainMenu();
                break;
            }
            case enMainMenuOp::enUpdateClient: {
                _ShowUpdateClientScreen();
                _GoBackToMainMenu();
                break;

            }
            case enMainMenuOp::enFindClient: {
                _ShowFindClientScreen();
                _GoBackToMainMenu();
                break;
            }
            case enMainMenuOp::enShowTransactionMenu: {
                _ShowTransactionsMenue();
                _GoBackToMainMenu();
                break;
            }
            case enMainMenuOp::enManageUsers: {
                _ShowManageUsersMenue();
                _GoBackToMainMenu();
                break;
            }
            case enMainMenuOp::enExit: {
                _ShowEndScreen();
                break;

            }
        }
    }
    public:
    static void ShowMainMenu() {
        _ScreenHeader("\t\tMain Screen");
        cout << setw(37) << left <<""<< "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Account.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformMainMenuOp((enMainMenuOp) _ReadMainMenuOP());
    }
};