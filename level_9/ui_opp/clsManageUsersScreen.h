#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iostream>
#include <iomanip>
using namespace std;

class clsManageUsersScreen : protected clsScreen {
private:
    enum enManageUsersOptions {enListUsers =1, enAddUser = 2, enDeleteUser = 3,
        enUpdateUser = 4, enFindUser =5, enMainMenu = 6};

    static short _ReadManageUsersOption() {
        short Option = 0;
        cout << "Please enter your choice: ";
        Option = clsInputValidate::ReadIntNumberBetween(1,6,"Invalid Input, Try agin!");
        return Option;
    }

    static void _GoBackToManageUsersMenu() {
        ManageUsersScreen();

    };
    static void _ListUsersMenu() {
        cout << "List Users Menu will be here soon"<<endl;
    }
    static void _AddNewUsersMenu() {
        cout << "Add Users Menu will be here soon"<<endl;
    }
    static void _DeleteUsersMenu() {
        cout << "Delete Users Menu will be here soon"<<endl;
    }
    static void _UpdateUsersMenu() {
        cout << "Update Users Menu will be here soon"<<endl;
    }
    static void _FinsUsersMenu() {
        cout << "Find Users Menu will be here soon"<<endl;
    }
    static void _PerformManageUsersMenu(enManageUsersOptions Option) {
        switch (Option) {
            case enManageUsersOptions::enListUsers: {
                _ListUsersMenu();
                _GoBackToManageUsersMenu();
                break;
            }
            case enManageUsersOptions::enAddUser: {
                _AddNewUsersMenu();
                _GoBackToManageUsersMenu();
                break;
            }
            case enManageUsersOptions::enDeleteUser: {
                _DeleteUsersMenu();
                _GoBackToManageUsersMenu();
                break;
            }
            case enManageUsersOptions::enUpdateUser: {
                _UpdateUsersMenu();
                _GoBackToManageUsersMenu();
                break;
            }
            case enManageUsersOptions::enFindUser: {
                _FinsUsersMenu();
                _GoBackToManageUsersMenu();
                break;
            }
            case enManageUsersOptions::enMainMenu: {

            }

        }
    }
    public:
     static void ManageUsersScreen() {
        _ScreenHeader("\t\t Manage users Screen");
        cout << setw(37) << left <<""<< "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\t Manage users Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show users List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New user.\n";
        cout << setw(37) << left << "" << "\t[3] Delete user.\n";
        cout << setw(37) << left << "" << "\t[4] Update user.\n";
        cout << setw(37) << left << "" << "\t[5] Find user.\n";
        cout << setw(37) << left << "" << "\t[6] main menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformManageUsersMenu((enManageUsersOptions) _ReadManageUsersOption());
    }

};