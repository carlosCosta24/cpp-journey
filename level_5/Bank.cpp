#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <limits>
#include <unistd.h>
using namespace std;

struct stClient {
    string account;
    string password;
    string phone;
    string name;
    double balance;
    bool selected;
};

void Menu() {
    cout << "\t\t\t================================"<<endl;
    cout << "\t\t\t\t\t\tMain Menu" << endl;
    cout << "\t\t\t================================"<<endl;
    cout<< "\t\t\t[1] Show Client List."<< endl;
    cout<< "\t\t\t[2] Add New Client."<<endl;
    cout<< "\t\t\t[3] Delete Client."<<endl;
    cout<< "\t\t\t[4] Update Client Info."<<endl;
    cout<< "\t\t\t[5] Find Client."<<endl;
    cout<< "\t\t\t[6] Transaction Menu."<<endl;
    cout<< "\t\t\t[7] Exit."<<endl;
    cout << "\t\t\t================================"<<endl;
    cout << "\t\t\tChoose What to do? [1 - 7]?"<<endl;
}
vector<string> vReadFile(string FileName ) {
    vector<string> vFileContent;
    fstream file;
    file.open(FileName, ios::in);
    string Line;
    if (file.is_open()) {
        while (getline(file, Line)) {
            vFileContent.push_back(Line);
        }
        file.close();
    }
    return vFileContent;
}
vector<string> vSpliter(string &s, string delim) {
    vector<string> vResult;
    int pos = 0;
    string Word = "";
    while ((pos = s.find(delim)) != string::npos) {
        Word = s.substr(0, pos);
        vResult.push_back(Word);
        s.erase(0, pos+delim.length());
    }
    if (!s.empty()) {
        vResult.push_back(s);
    }

    return vResult;
}
vector <stClient> vConvertLineToClients(vector<string> Lines) {
    vector <stClient> vClients;
    for (string Line : Lines) {
        vector<string> vClient = vSpliter(Line, "/*/");
        if (vClient.size() >= 5) {
            stClient Client;
            Client.account = vClient[0];
            Client.password = vClient[1];
            Client.name = vClient[2];
            Client.phone = vClient[3];
            Client.balance =stod(vClient[4]);
            Client.selected = false;
            vClients.push_back(Client);
        }
    }
    return vClients;
};
//Show Client list
void clientsListPrinter(vector<stClient>& vClients) {
    for (const stClient& client : vClients) {
        cout << left << setw(18) << "|" + client.account;
        cout << left << setw(15) << "|" + client.password;
        cout << left << setw(30) << "|" + client.name;
        cout << left << setw(15) << "|" + client.phone;
        cout << left << setw(15) << "|" + to_string(client.balance) << endl;
    }
    cout << "-----------------------------------------------------------------------------------------------" << endl;
};
void TablePrinter(short Number) {
    cout << "\t\t\t\t\t\t\t\t Client list (" << Number << ") Client(s)" << endl;
    cout << "-----------------------------------------------------------------------------------------------"<< endl;
    cout << left << setw(18)<<"|Account Number";
    cout << left << setw(15)<<"|Pin code";
    cout << left << setw(30)<<"|Client Name";
    cout << left << setw(15)<<"|Phone";
    cout << left << setw(15)<<"|Balance"<< endl;
    cout << "-----------------------------------------------------------------------------------------------"<< endl;
}
void TransactionMenu() {
    cout << "\t\t\t================================"<<endl;
    cout << "\t\t\t\t\tTransaction Menu" << endl;
    cout << "\t\t\t================================"<<endl;
    cout<< "\t\t\t[1] Deposit."<< endl;
    cout<< "\t\t\t[2] Withdraw."<<endl;
    cout<< "\t\t\t[3] Total Balance."<<endl;
    cout<< "\t\t\t[4] Main Menu."<<endl;
    cout << "\t\t\t================================"<<endl;
    cout << "\t\t\tChoose What to do? [1 - 4]?"<<endl;

}
void PrintClint(stClient& Client ) {
    cout << "Account Number    :"<<Client.account << endl;
    cout << "Phone Number      :"<<Client.phone << endl;
    cout << "Name of Client    :"<<Client.name << endl;
    cout << "Balance of Client :"<<Client.balance << endl;
}
void PrintClint(string AccountNumber, vector<stClient>& vClients) {
    for (stClient& Client : vClients) {
        if (Client.account == AccountNumber) {
            cout << "Account Number    :"<<Client.account << endl;
            cout << "Phone Number      :"<<Client.phone << endl;
            cout << "Name of Client    :"<<Client.name << endl;
            cout << "Balance of Client :"<<Client.balance << endl;
            return;
        }
    }
cout << "Client not found" << endl;
}
void BalancesListHeader(short Number) {
    cout << "\t\t\t\t\t\t\t\t Client list (" << Number << ") Client(s)" << endl;
    cout << "-----------------------------------------------------------------------------------------------"<< endl;
    cout << left << setw(18)<<"|Account Number";
    cout << left << setw(30)<<"|Client Name";
    cout << left << setw(15)<<"|Balance"<< endl;
    cout << "-----------------------------------------------------------------------------------------------"<< endl;
}
void BalacesPrinter(vector<stClient>& vList) {
    double TotalBalance = 0;
    for (const stClient& client : vList) {
        cout << left << setw(18) << "|" + client.account;
        cout << left << setw(30) << "|" + client.name;
        cout << left << setw(15) << "|" + to_string(client.balance) << endl;
        TotalBalance += client.balance;
    }
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t Total balance = " << TotalBalance<<  endl;
}
//Add New client
bool AccountExists(const vector<stClient>& List, const string& Account) {
    for (const auto& client : List) {
        if (client.account == Account) return true;
    }
    return false;
}
void AddClient(vector<stClient>& List) {
    stClient Client;
    cout<< "Enter Account Number: ";
    cin >> Client.account;
    if (AccountExists(List, Client.account)) {
        cout << "Account already exists" << endl;
        return;
    }
    cout<< "Enter Password: ";
    cin >> Client.password;
    cout<< "Enter Client Name: ";
    cin.ignore();
    getline(cin,Client.name);
    cout<< "Enter Client Phone: ";
    getline(cin,Client.phone);
    cout<< "Enter Client Balance: ";
    cin >> Client.balance;
    Client.selected = false;
    List.push_back(Client);
    cout<< "Client Added Successfully!" << endl;
};
//Delete Client
void MarkForDeletion(vector<stClient>& List, string ClientAccount) {
    vector<stClient> vNewList;
    for (stClient& Client : List) {
        if (Client.account == ClientAccount) {
            Client.selected = true;
            cout<< "Deleting....";
            return;
        }
    }
        cout<< "Account Not Found"<<endl;
}
void DeleteClient(vector<stClient>& List) {
    vector<stClient> NewList;
    for (stClient& Client : List) {
        if (!Client.selected) {
            NewList.push_back(Client);
        }
    }
    List = NewList;
 }
//Update Client
void UpdateClintData(stClient &Client) {
    cout << "Enter New Password (current: " << Client.password << "): ";
    cin >> Client.password;
    cout << "Enter New Client Name (current: " << Client.name << "): ";
    cin.ignore();
    getline(cin, Client.name);
    cout << "Enter New Client Phone (current: " << Client.phone << "): ";
    getline(cin, Client.phone);
    cout << "Enter New Client Balance (current: " << Client.balance << "): ";
    cin >> Client.balance;
    cout << "Client Info Updated Successfully!" << endl;
}
void UpdateClient(vector<stClient>& List, string AccountNumber) {
    for (stClient& Client : List) {
        if (Client.account == AccountNumber) {
            UpdateClintData(Client);
            cout << "Client Updated Successfully!" << endl;
            return;
        }
    }
    cout << "Client not found!!" << endl;
}
//Find Client
void ClientCard(stClient Client) {
    cout << "The following are the client details: "<< endl;
    cout<< "-----------------------------------------------"<< endl;
    cout << "Account Number :" << Client.account << endl;
    cout << "Name           :" << Client.name << endl;
    cout << "Phone          :" << Client.phone << endl;
    cout << "Balance        :" << Client.balance << endl;
    cout<< "-----------------------------------------------"<< endl;
    
}
void SearchClient(vector<stClient>& List, string AccountNumber) {
    for (stClient& Client : List) {
        if (Client.account == AccountNumber) {
            ClientCard(Client);
            return;
        }
    }
    cout<< "Client not found!" << endl;
}
void SaveClientsToFile(string fileName, vector<stClient> clients) {
    ofstream file(fileName);
    if (file.is_open()) {
        for (stClient client : clients) {
            file << client.account << "/*/"
                 << client.password << "/*/"
                 << client.name << "/*/"
                 << client.phone << "/*/"
                 << client.balance << endl;
        }
        file.close();
    }
}
void ClearScreen() {
    std::cout << "\033[2J\033[1;1H";
}
//transaction menu operation
void Deposit(vector<stClient>& List ,string AccountNumber) {
    for (stClient& Client : List) {
        if (Client.account == AccountNumber) {
            double Amount;
            cout << "Enter Deposit Amount: ";
            cin >> Amount;
            Client.balance += Amount;
            cout << "Deposit done Successfully -:)"<<endl;
            return;
        }
    }
        cout << "Account not found!" << endl;
}
void Withdraw(vector<stClient>& List ,string AccountNumber) {
    for (stClient& Client : List) {
        if (Client.account == AccountNumber) {
            double Amount;
            cout << "Enter Withdrawal Amount: ";
            cin >> Amount;
            while (Amount > Client.balance) {
                cout << "Amount is exceeding the Limit! (Available: " << Client.balance << "), try again?:" << endl;
                cin >> Amount;
            }
            Client.balance -= Amount;
            cout << "Withdraw done Successfully -:)"<< endl;
            return;
        }
    }
        cout << "Account not found!" << endl;
}

void Start() {
    const string DataBase = "bank.txt";
    vector<string> vData = vReadFile(DataBase);
    vector<stClient> vDataList = vConvertLineToClients(vData);
    while (true) {
        ClearScreen();
        Menu();
        cout << endl;

    short Option;
    cin>> Option;
    cin.ignore();

    switch (Option) {
        case 1: {
            ClearScreen();
            short Length = vDataList.size();
            TablePrinter(Length);
            clientsListPrinter(vDataList);
            cout << "Press any key to back to main menu..."<<endl;
            cin.get();
            break;
        }
        case 2: {

            ClearScreen();
            AddClient(vDataList);
            SaveClientsToFile(DataBase, vDataList);
            cout << "Press any key to back to main menu..."<<endl;
            cin.get();
            break;
        }
        case 3: {

            ClearScreen();
            string AccountNumber;
            cout<< "Enter Account Number to Delete: "<< endl;
            cin >> AccountNumber;
            char Answer ;
            SearchClient(vDataList, AccountNumber);
            cout << "Are you sure You want to delete this account ?";
            cin >> Answer;
            if (Answer == 'Y' || Answer == 'y') {
            MarkForDeletion(vDataList, AccountNumber);
            DeleteClient(vDataList);
            SaveClientsToFile(DataBase, vDataList);
            }
            cout << "Press any key to back to main menu..."<<endl;
            cin.ignore();
            cin.get();
            break;
        }
        case 4: {
            ClearScreen();
            string ClientAccount;
            cout << "Enter Client Account: "<<endl;
            cin >> ClientAccount;
            UpdateClient(vDataList, ClientAccount);
            SaveClientsToFile(DataBase, vDataList);
            cout << "Press any key to back to main menu..."<<endl;
            cin.ignore();
            cin.get();
            break;
        }
        case 5: {

            ClearScreen();
            string ClientIdentifier;
            cout << "Enter Account Number: "<<endl;
            cin >> ClientIdentifier;
            SearchClient(vDataList, ClientIdentifier);
            cout<< "Press any key to back to main menu..."<< endl;
            cin.ignore();
            cin.get();
            break;
        }
        case 6: {
            ClearScreen();
            TransactionMenu();
            short Choice;
            cin >> Choice;
            switch (Choice) {
                case 1: {
                    string ClientAccount;
                    cout << "Enter Account Number: "<<endl;
                    cin >> ClientAccount;
                    SearchClient(vDataList, ClientAccount);
                    Deposit(vDataList, ClientAccount);
                    SaveClientsToFile(DataBase, vDataList);
                    cout<< "Press any key to back to main menu..."<< endl;
                    cin.ignore();
                    cin.get();
                    break;
                }
                case 2: {
                    string ClientAccount;
                    cout<< "Enter Account Number: "<<endl;
                    cin >> ClientAccount;
                    SearchClient(vDataList, ClientAccount);
                    Withdraw(vDataList, ClientAccount);
                    SaveClientsToFile(DataBase, vDataList);
                    cout<< "Press any key to back to main menu..."<< endl;
                    cin.ignore();
                    cin.get();
                    break;

                }
                case 3:
                {
                    BalancesListHeader(vData.size());
                    BalacesPrinter(vDataList);
                    cout<< "Press any key to back to main menu..."<< endl;
                    cin.ignore();
                    cin.get();
                    break;
                }
                case 4: {
                    Menu();
                    break;
                }
                default: {
                    cout << "Invalid Option! Please try again." << endl;
                    cout << "Press any key to continue..."<< endl;
                    cin.ignore();
                    cin.get();
                    break;
                }
            }
            break;

        }
        case 7: {

            cout << "Good bye!" << endl;
            return;;
        }
        default: {

            cout << "Invalid Option! Please try again." << endl;
            cout << "Press any key to continue..."<< endl;
            cin.ignore();
            cin.get();
            break;
        }
    }
}
    }

int main() {
    Start();
    return 0;
}