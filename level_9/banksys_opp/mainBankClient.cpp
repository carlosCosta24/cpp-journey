#include <iostream>
#include "clsBankClient.h"
int main() {

    clsBankClient Client = clsBankClient::Find("C333");
    Client.Print();

    clsBankClient Client2 = clsBankClient::Find("H88");
    Client2.Print();

    cout << clsBankClient::IsClientExist("C333") << endl;




}