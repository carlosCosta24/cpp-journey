#pragma once
#include <iomanip>

#include "clsBankClient.h"
#include "clsScreen.h"
#include <iostream>
using namespace std;

class clsTransferLogScreen: protected clsScreen {
    private:
    static void _PrintLogRecord(clsBankClient::stTransferLog Log) {
        cout << "| " << left << setw(20)<< Log.Date;
        cout << "| " << left << setw(15) << Log.SourceAccount;
        cout << "| " << left << setw(15) << Log.DestinationAccount;
        cout << "| " << left << setw(12) << Log.Amount;
        cout << "| " << left << setw(15) << Log.SourceBalance;
        cout << "| " << left << setw(15) << Log.DestinationBalance;
        cout << "| " << left << setw(12) << Log.UserName;
    }

    public:
    static void ShowTransferLogScreen() {
        vector <clsBankClient::stTransferLog> vLogsList = clsBankClient::GetTransferList();
        string Title = "\t Transfer Logs List Screen";
        string SubTitle = "\t\t\t (" + to_string(vLogsList.size()) + ") Record(s).";

        _ScreenHeader(Title, SubTitle);
        cout << "\n-------------------------------------------------------------------------------"
                "------------------------------------\n";
        cout << "| " << left << setw(20) << "Date/Time";
        cout << "| " << left << setw(15) << "Src. Account";
        cout << "| " << left << setw(15) << "Dst. Account";
        cout << "| " << left << setw(12) << "Amount";
        cout << "| " << left << setw(15) << "Src. Balance";
        cout << "| " << left << setw(15) << "Dst. Balance";
        cout << "| " << left << setw(12) << "User";
        cout << "\n-------------------------------------------------------------------------------"
                        "------------------------------------\n";
        if (vLogsList.size() == 0) {
            cout << "\n\t\t\t\t\t\t\t\t\tNo Logs data available" << endl;
        }
        else {
            for (clsBankClient::stTransferLog Log : vLogsList) {
                _PrintLogRecord(Log);
                cout << endl;
            }
        }
        cout << "\n-------------------------------------------------------------------------------"
                  "------------------------------------\n";


    }
};