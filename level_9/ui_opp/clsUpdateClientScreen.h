#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"

#include <iomanip>
#include "clsBankClient.h"

class clsUpdateClientScreen : protected clsScreen {
    private:
    static void _PrintClientRecordLine(clsBankClient Client) {
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

public:
    static void UpdateClient() {
        _ScreenHeader("\t  Update Client Screen");
        string AccountNumber = "";

        cout << "\nPlease enter client account number:";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\nPlease enter account number again: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClientRecordLine(Client);
        cout << "\n\nAre you sure you want to update this client? y/n"<< endl;
        char Choice = 'n';
        cin >> Choice;
        Choice = tolower(Choice);
        if (Choice == 'y') {
            cout << "\n\nUpdate Client Info";
            cout << "\n---------------------\n";
            _ReadClientInfo(Client);
            clsBankClient::enSaveResult SaveResult = Client.Save();

            switch (SaveResult) {
                case clsBankClient::enSaveResult::svSaved: {
                    cout << "\n\nUpdated Successfully ";
                    _PrintClientRecordLine(Client);
                    break;
                }
                case clsBankClient::enSaveResult::svFailed: {
                    cout << "\n\nUpdated Failed ";
                    break;
                }
            }
        }else {
            cout << "\n\nUpdate Failed "<<endl;
        }

    }
};