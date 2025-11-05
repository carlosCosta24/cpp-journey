#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

class clsTransferScreen : protected clsScreen {
    private:
    static void _PrintSummaryCard(clsBankClient& Client) {
        cout << "Client Card: "<< endl ;
        cout << "------------------------------------"<<endl;
        cout << "Full Name: "<< Client.FullName()<<endl;
        cout << "Acc. Number: "<< Client.AccountNumber()<<endl;
        cout << "Balance: " << Client.GetBalance()<<endl;
        cout << "------------------------------------"<<endl;
     }
    static string _ReadAccountNumber(string Type) {
        string Account = "";
        cout << "Please Enter Account Number To Transfer " << Type <<" :"<< endl;
        Account = clsInputValidate::ReadString();
        return Account;
    }
    public:
    static void ShowTransferScreen() {
        _ScreenHeader("\t Transfer Screen");
        string FromAccountNumber = _ReadAccountNumber("From");
        while (!clsBankClient::IsClientExist(FromAccountNumber)) {
            cout << "\nPlease enter account number again: ";
            FromAccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient FirstClient = clsBankClient::Find(FromAccountNumber);
        _PrintSummaryCard(FirstClient);

        string ToAccountNumber = _ReadAccountNumber("To");
        while (!clsBankClient::IsClientExist(ToAccountNumber)) {
            cout << "\nPlease enter account number again: ";
            ToAccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient SecondClient = clsBankClient::Find(ToAccountNumber);
        _PrintSummaryCard(SecondClient);

        double Amount = 0;
        cout << "Please enter amount to Transfer: ";
        Amount = clsInputValidate::ReadDNumber();
        while(Amount > FirstClient.GetBalance()) {
            cout << "\nAmount exceeds the available balance, Enter another amount: " << endl;
            Amount = clsInputValidate::ReadDNumber();
        }

        cout << "\n\nAre you sure you want to Transfer this amount? y/n"<< endl;
        char Choice = 'n';
        cin >> Choice;
        Choice = tolower(Choice);
        if (Choice == 'y') {
            if (FirstClient.Transfer(Amount,SecondClient, CurrentUser.GetUserName())) {

                cout << "\nTransfer done successfully \n";
                _PrintSummaryCard(FirstClient);
                _PrintSummaryCard(SecondClient);
            }else {
                cout << "\nTransfer Faild \n";
            }
        }
        else {
            cout << "\nTransfer was canceled:-("<< endl;
        }
    }
};
