#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsFindClientScreen: protected clsScreen {
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

    public:
    static void FindClientScreen() {
        _ScreenHeader("\t Find Client Screen ");
        string AccountNumber = "";
        cout << "\nEnter Account Number:";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\nAccount Number doesn't exist, Try again:";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient NewClient = clsBankClient::Find(AccountNumber);

        if (!NewClient.IsEmpty()){
            cout << "Client Data was found :-)"<<endl;
        }else {
            cout << "Client Data was not foud :-("<< endl;

        }
        _PrintClient(NewClient);

    }

};