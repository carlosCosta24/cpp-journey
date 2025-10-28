#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDeleteClientScreen: protected clsScreen {
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
    static void DeleteClientScreen() {

        _ScreenHeader("\t Delete Client Screen");
        string AccountNumber = "";
        cout << "\nPlease enter client account number:";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\nPlease enter account number again: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);
        cout << "\n\nAre you sure you want to delete this client? y/n"<< endl;
        char Choice = 'n';
        cin >> Choice;
        Choice = tolower(Choice);
        if (Choice == 'y') {
            bool Deleted = Client.Delete();
            if (Deleted){
                cout << "\nClient deleted successfully :-)" << endl;
                _PrintClient(Client);

        }
        }else {cout << "\nClient not deleted :-("<< endl;
        }
    }

};