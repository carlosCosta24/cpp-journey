#pragma once
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include <iomanip>
class clsTotalBalancesScreen: protected clsScreen {
    private:
    static void PrintClientRecordBalanceLine(clsBankClient Client) {
        cout << "| " << setw(25) << left << Client.AccountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.GetBalance();
    }
public:
    static void TotalBalancesScreen() {
        vector<clsBankClient> ClientsList = clsBankClient::GetClientsList();
        short ClientsListSize = ClientsList.size();
        _ScreenHeader("\t Balance List Screen ", "\t\t\t ( " + to_string(ClientsListSize) + " ) Client(s)");
        double TotalBalance = clsBankClient::GetTotalBalances(ClientsList);
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << "| " << left << setw(25) << "Account Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (ClientsList.size() == 0) {
            cout << "\n\t\t\t\t\t\t\t\t\tNo Clients data are available" << endl;
        }

        for (clsBankClient Client : ClientsList) {
            PrintClientRecordBalanceLine(Client);
            cout << endl;
        }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "\t\t\t\t\t\tTotal Balance: " << TotalBalance << endl;
        cout << "\t\t\t\t\t\t( " << clsUtil::NumberToText(TotalBalance)<<")"<< endl;


    }

};