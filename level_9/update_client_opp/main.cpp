#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"

void DeleteClient() {
    string AccountNumber = "";

    cout << "\nPlease enter client account number:";
    AccountNumber = clsInputValidate::ReadString();
    while (!clsBankClient::IsClientExist(AccountNumber)) {
        cout << "\nPlease enter account number again: ";
        AccountNumber = clsInputValidate::ReadString();
    }
    clsBankClient Client = clsBankClient::Find(AccountNumber);
    Client.Print();

    cout << "\n\nAre you sure you want to delete this client? y/n";
    char Choice = 'n';
    cin >> Choice;
    Choice = tolower(Choice);
    if (Choice == 'y') {
        if (Client.Delete()) {

            cout << "\nClient deleted successfully :-)" << endl;
            Client.Print();
        }else {

            cout << "\nClient not deleted :-("<< endl;
        }

    }
}

int main() {
    DeleteClient();
    return 0;
}