#pragma once
#include "clsUser.h"
#include "clsScreen.h"
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

class clsLogsScreen: protected clsScreen {
    private:

    static void _PrintLogsLine(clsUser::stUsersLog Log) {

             cout << "| " << left << setw(25)<< Log.Date;
             cout << "| " << left << setw(20) << Log.Name;
             cout << "| " << left << setw(12) << Log.Password;
             cout << "| " << left << setw(28) << Log.Permissions;
    }


    public:
    static void ShowLogsScreen() {
        if (!_AccessChecker(clsUser::enPermissions::pLogs)) {
            return;
        }
        vector <clsUser::stUsersLog> vLogsList = clsUser::GetLogsList();
        string Title = "\t Logs List Screen";
        string SubTitle = "\t\t (" + to_string(vLogsList.size()) + ") Client(s).";

        _ScreenHeader(Title, SubTitle);
        cout << "\n-------------------------------------------------------------------------------"
                "---------------------------\n";
        cout << "| " << left << setw(25) << "Date";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(12) << "Password";
        cout << "| " << left << setw(28) << "Permissions";
        cout << "\n-------------------------------------------------------------------------------------"
                "---------------------\n";
        if (vLogsList.size() == 0) {
            cout << "\n\t\t\t\t\t\t\t\t\tNo Logs data available" << endl;
        }
        else {
            for (clsUser::stUsersLog Log : vLogsList) {
                _PrintLogsLine(Log);
                cout << endl;
            }
        }
        cout << "\n----------------------------------------------------------------------------------"
                "------------------------\n";
    }

};
