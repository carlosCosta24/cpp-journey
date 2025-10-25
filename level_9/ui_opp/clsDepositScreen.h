#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iostream>

class clsDepositScreen : protected clsScreen {
private:
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
    static string _ReadAccountNumber() {
        string Account = "";
        cout << "Please Enter Account Number: ";
        cin >> Account;
        return Account;
    }
    public:
    static void DepositScreen() {
        _ScreenHeader("\t Deposit Screen");
        string AccountNumber = _ReadAccountNumber();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\nPlease enter account number again: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        double Amount = 0;
        cout << "Please enter amount to deposit: ";
        Amount = clsInputValidate::ReadDNumber();

        cout << "\n\nAre you sure you want to deposit this amount? y/n"<< endl;
        char Choice = 'n';
        cin >> Choice;
        Choice = tolower(Choice);
        if (Choice == 'y') {
            Client.Deposit(Amount);
            cout << "\nAmount deposited successfully \n";
            cout << "\n New Balance: " << Client.GetBalance() << endl;

        }
        else {
            cout << "\nDeposit was canceled:-("<< endl;
        }
    }
};