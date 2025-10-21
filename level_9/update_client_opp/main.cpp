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

void AddNewClient() {
    string AccountNumber = "";
    cout << "\nEnter Account Number:";
    AccountNumber = clsInputValidate::ReadString();
    while (clsBankClient::IsClientExist(AccountNumber)) {
        cout << "\nAccount Number already exist, Try again:";
        AccountNumber = clsInputValidate::ReadString();
    }
    clsBankClient NewClient = clsBankClient::AddNewClientObj(AccountNumber);

    ReadClientInfo(NewClient);
    clsBankClient::enSaveResult SaveResult;

    SaveResult = NewClient.Save();

    switch (SaveResult) {
        case clsBankClient::enSaveResult::svSaved: {
            cout << "\nSaved Successfully :-)";
            NewClient.Print();
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

int main() {
    AddNewClient();
    return 0;
}