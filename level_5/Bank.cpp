#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <limits>
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
    cout<< "\t\t\t[6] Exit."<<endl;
    cout << "\t\t\t================================"<<endl;
    cout << "\t\t\tChoose What to do? [1 - 6]"<<endl;
    system("pause");

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
    string Line;
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
vector<string> vSplitedFile(vector<string> &L, string delim) {
    vector<string> vResult;
    for (string s : L) {
        vSpliter(s, delim);
        vResult.push_back(s);
    }
    return vResult;

}
//Show Client list
void clientsListPrinter(vector<stClient> &vClients) {
    for (const stClient& client : vClients) {
        cout<<"|" <<left <<client.account<<endl;
        cout<<"|" <<left <<client.name<<endl;
        cout<<"|" <<left <<client.phone<<endl;
        cout<<"|" <<left <<client.balance<<endl;
    }
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
void PrintClint(stClient& Client ) {
    cout << "Account Number    :"<<Client.account << endl;
    cout << "Phone Number      :"<<Client.phone << endl;
    cout << "Name of Client    :"<<Client.name << endl;
    cout << "Balance of Client :"<<Client.balance << endl;
}
//Add New client
void AddClient(vector<stClient>& List) {
    stClient Client;
    cout<< "Enter Account Number: ";
    cin >> Client.account;
    cout<< "Enter Password: ";
    cin >> Client.password;
    cout<< "Enter Client Name: ";
    cin >> Client.name;
    cout<< "Enter Client Phone: ";
    cin >> Client.phone;
    cout<< "Enter Client Balance: ";
    cin >> Client.balance;
    List.push_back(Client);
};
//Delete Client
void MarkForDeletion(stClient& Target) {
    Target.selected = true;
}
void DeleteClient(vector<stClient>& List) {
    vector<stClient> NewList;
    for (stClient& Client : List) {
        if (Client.selected != true) {
            NewList.push_back(Client);
        }
    }

 }
//Update Client
void ReadClint(vector<stClient>& ClientList) {
    stClient Client;
    cout<< "Enter Password: ";
    getline(cin, Client.password);
    cout<< "Enter Client Name: ";
    getline(cin, Client.name);
    cout<< "Enter Client Phone: ";
    getline(cin, Client.phone);
    cout<< "Enter Client Balance: ";
    cin>> Client.balance;
    ClientList.push_back(Client);

}
void UpdateClient(vector<stClient>& List, string AccountNumber) {
    for (stClient& Client : List) {
        if (Client.account == AccountNumber) {
            ReadClint(List);
        }
    }
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
            PrintClint(Client);
        }
    }
}
//Exit
/*system(pause)*/
void Start() {
    string DataBase;
    vector<string> vData = vReadFile(DataBase);
    vector<stClient> vDataList = vSplitedFile(vData, "/*/");
    system("cls");
    short Option;
    Menu();
    cin>> Option;
    switch (Option) {
        case 1:
            short Length = vDataList.size();
            TablePrinter(Length);
            clientsListPrinter(vDataList);
            system("Press any key to back to main menu...");
            Menu();
            break;
        case 2:
            AddClient(vDataList);
            system("Press any key to back to main menu...");
            Menu();
            break;
        case 3:
            DeleteClient(vDataList);
            system("Press any key to back to main menu...");
            Menu();
            break;
        case 4:
            UpdateClient(vDataList, DataBase);
            system("Press any key to back to main menu...");
            Menu();
            break;
        case 5:
            string AccountNumber;
            cout << "Enter Account Number: ";
            cin >> AccountNumber;
            SearchClient(vDataList, AccountNumber);
            system("Press any key to back to main menu...");
            Menu();
            break;
        case 6:
            cout << "Good bye!" << endl;
            break;
        default:
            short ListLength = vDataList.size();
            TablePrinter(ListLength);
            clientsListPrinter(vDataList);
            system("Press any key to back to main menu...");
            Menu();
    }
}

int main() {
    Start();
    return 0;
}