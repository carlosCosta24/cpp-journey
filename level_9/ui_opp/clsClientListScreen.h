#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"

class clsClientListScreen : protected clsScreen {
    private:
    static void _PrintClientRecordLine(clsBankClient Client) {
        cout << "| " << left << setw(15) << Client.AccountNumber();
        cout << "| " << left << setw(20) << Client.FullName();
        cout << "| " << left << setw(12) << Client.GetPhone();
        cout << "| " << left << setw(28) << Client.GetEmail();
        cout << "| " << left << setw(12) << Client.GetBalance();

    }

    public:
    static void ShowClientList() {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "\t Client List Screen";
        string SubTitle = "\t\t (" + to_string(vClients.size()) + ") Client(s).";

        _ScreenHeader(Title, SubTitle);
        cout << "\n-------------------------------------------------------------------------------"
                "---------------------------\n";
        cout << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(28) << "Email";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n-------------------------------------------------------------------------------------"
                "---------------------\n";
        if (vClients.size() == 0) {
            cout << "\n\t\t\t\t\t\t\t\t\tNo Clients data are available" << endl;
        }
        else {
            for (clsBankClient Client : vClients) {
                _PrintClientRecordLine(Client);
                cout << endl;
            }
        }
        cout << "\n----------------------------------------------------------------------------------"
                "------------------------\n";
    }
};