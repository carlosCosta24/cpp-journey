#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsAddNewClientScreen : protected clsScreen {
private:

    static void _ReadClientInfo (clsBankClient& Client) {
        cout << "\nEnter Client FirstName:";
        Client.SetFirstName(clsInputValidate::ReadString());

        cout << "\nEnter Client LastName:";
        Client.SetLastName(clsInputValidate::ReadString());

        cout << "\nEnter Client Email:";
        Client.SetEmail(clsInputValidate::ReadString());

        cout << "\nEnter Client PhoneNumber:";
        Client.SetPhone(clsInputValidate::ReadString());

        cout << "\nEnter Client Password:";
        Client.SetPassword(clsInputValidate::ReadString());

        cout << "\nEnter Client Balance:";
        Client.setBalance(clsInputValidate::ReadFloatNumber());
    }
    static void _PrintClientInfo(clsBankClient &Client) {
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
    static void AddNewClientScreen() {
        string AccountNumber = "";
        cout << "\nEnter Account Number:";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\nAccount Number already exist, Try again:";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient NewClient = clsBankClient::AddNewClientObj(AccountNumber);

        _ReadClientInfo(NewClient);
        clsBankClient::enSaveResult SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult) {
            case clsBankClient::enSaveResult::svSaved: {
                cout << "\nSaved Successfully :-)";
                _PrintClientInfo(NewClient);
                break;
            }
            case clsBankClient::enSaveResult::svFailed: {
                cout << "\nSaved Failed!, object is empty!";
                break;
            }
            case clsBankClient::enSaveResult::svAccountExist:{
                cout << "\nAccount Number already in use, Try again later.";
                break;
            }
        }

    }
};