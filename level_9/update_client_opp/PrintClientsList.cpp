#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>
using namespace std;
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
    ShowClientsList();
    return 0;
}