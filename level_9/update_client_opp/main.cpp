#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>

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

void PrintClientRecord(clsBankClient Client) {
    cout << "| " << left << setw(15) << Client.AccountNumber();
    cout << "| " << left << setw(20) << Client.FullName();
    cout << "| " << left << setw(12) << Client.GetPhone();
    cout << "| " << left << setw(28) << Client.GetEmail();
    cout << "| " << left << setw(10) << Client.GetPassword();
    cout << "| " << left << setw(12) << Client.GetBalance();
}

void ShowClientsList() {
    vector <clsBankClient> vClients = clsBankClient::GetClientsList();
    cout << "\n\t\t\t\tClients List(" << vClients.size() << ") Client/s" << endl;
    cout << "\n----------------------------------------------------------------------------------------------------------\n";
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(28) << "Email";
    cout << "| " << left << setw(10) << "Password";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n----------------------------------------------------------------------------------------------------------\n";
    if (vClients.size() == 0) cout << "\n\t\t\t\t\t\t\t\t\tNo Clients data are available" << endl;
    else {
        for (clsBankClient Client : vClients) {
            PrintClientRecord(Client);
            cout << endl;
        }
    }
    cout << "\n----------------------------------------------------------------------------------------------------------\n";


}

int main() {
    UpdateClient();
    return 0;
}