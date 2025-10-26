#pragma once
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include <iostream>

class clsWithdrawScreen : protected clsScreen {
    private:
    static string _ReadAccountNumber() {
        string Account = "";
        cout << "Please Enter Account Number: ";
        Account = clsInputValidate::ReadString();
        return Account;
    }
    static void _PrintClient(clsBankClient Client) {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.GetFirstName();
        cout << "\nLastName    : " << Client.GetLastName();
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.GetEmail();
        cout << "\nPhone       : " << Client.GetPhone();
        cout << "\nAccount Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.GetPassword();
        cout << "\nBalance     : " << Client.GetBalance();
        cout << "\n___________________\n";
    }
    public:
    static void WithdrawScreen() {
        _ScreenHeader("\t Withdraw Screen");
        string AccountNumber = _ReadAccountNumber();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\nPlease enter account number again: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        double Amount = 0;
        cout << "Please enter amount to Withdraw: ";
        Amount = clsInputValidate::ReadDNumber();

        cout << "\n\nAre you sure you want to deposit this amount? y/n"<< endl;
        char Choice = 'n';
        cin >> Choice;
        Choice = tolower(Choice);
        if (Choice == 'y') {
            if (!Client.Withdraw(Amount)) {
                cout << "Amount exceeds Account balance ( " <<Client.GetBalance()<<
                    " ) Please try again!"<<endl;
                cout << "Please enter amount to Withdraw: ";
                Amount = clsInputValidate::ReadDNumber();
            }
            Client.Withdraw(Amount);
            cout << "\nAmount Withdrawn successfully \n";
            cout << "\n New Balance: " << Client.GetBalance() << endl;

        }
        else {
            cout << "\nWithdraw was canceled:-("<< endl;
        }
    }
};