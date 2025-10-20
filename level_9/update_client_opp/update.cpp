#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"

void ReadClientInfo(clsBankClient& Client) {

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

void UpdateClient() {
    string AccountNumber = "";

    cout << "\nPlease enter client account number:";
    AccountNumber = clsInputValidate::ReadString();
    while (!clsBankClient::IsClientExist(AccountNumber)) {
        cout << "\nPlease enter account number again: ";
        AccountNumber = clsInputValidate::ReadString();
    }
    clsBankClient Client = clsBankClient::Find(AccountNumber);
    Client.Print();

    cout << "\n\nUpdate Client Info";
    cout << "\n---------------------\n";

    ReadClientInfo(Client);

    clsBankClient::enSaveResult SaveResult = Client.Save();

    switch (SaveResult) {
        case clsBankClient::enSaveResult::svSaved: {
            cout << "\n\nUpdated Successfully ";
            Client.Print();
            break;
        }
        case clsBankClient::enSaveResult::svFailed: {
            cout << "\n\nUpdated Failed ";
            break;
        }
    }



}

int main() {
    UpdateClient();
    return 0;
}