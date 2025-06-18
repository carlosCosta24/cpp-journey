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
    cout<< "\t\t\t[6] Exit."<<endl;
    cout << "\t\t\t================================"<<endl;
    cout << "\t\t\tChoose What to do? [1 - 6]"<<endl;
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
vector<string> vSplitedFile(vector<string> &L, string delim) {
    vector<string> vResult;
    for (string s : L) {
        vSpliter(s, delim);
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
    cin.ignore();
    getline(cin,Client.name);
    cout<< "Enter Client Phone: ";
    getline(cin,Client.phone);
    cout<< "Enter Client Balance: ";
    cin >> Client.balance;
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
}
void DeleteClient(vector<stClient>& List) {
    vector<stClient> NewList;
    for (stClient& Client : List) {
        if (!Client.selected) {
            NewList.push_back(Client);
        }
    }
    List = NewList;
    cout<< "Deleted :-)";

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
            MarkForDeletion(vDataList, AccountNumber);
            DeleteClient(vDataList);
            SaveClientsToFile(DataBase, vDataList);
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

            cout << "Good bye!" << endl;
            return;
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
/*ideal solution

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
const string ClientsFileName = "Clients.txt";

void ShowMainMenue();

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable

    // use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word.
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }

    return vString;

}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
    sClient Client;
    vector<string> vClientData;
    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);//cast string to double
    return Client;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{

    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}

bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
{

    vector <sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {
        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            if (Client.AccountNumber == AccountNumber)
            {
                MyFile.close();
                return true;
            }
            vClients.push_back(Client);
        }

        MyFile.close();

    }
    return false;
}

sClient ReadNewClient()
{
    sClient Client;
    cout << "Enter Account Number? ";

    // Usage of std::ws will extract allthe whitespace character
    getline(cin >> ws, Client.AccountNumber);

    while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName))
    {
        cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, Client.AccountNumber);
    }

    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;
}

vector <sClient> LoadCleintsDataFromFile(string FileName)
{
    vector <sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {
        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

void PrintClientRecordLine(sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void ShowAllClientsScreen()
{
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (sClient Client : vClients)
        {

            PrintClientRecordLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

void PrintClientCard(sClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "-----------------------------------";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code     : " << Client.PinCode;
    cout << "\nName         : " << Client.Name;
    cout << "\nPhone        : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << "\n-----------------------------------\n";
}

bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClients, sClient& Client)
{
    for (sClient C : vClients)
    {

        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }

    }
    return false;
}

sClient ChangeClientRecord(string AccountNumber)
{
    sClient Client;

    Client.AccountNumber = AccountNumber;

    cout << "\n\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;
    return Client;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{

    for (sClient& C : vClients)
    {

        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }

    }

    return false;
}

vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {
        for (sClient C : vClients)
        {

            if (C.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }

        }

        MyFile.close();
    }

    return vClients;
}

void AddDataLineToFile(string FileName, string  stDataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {

        MyFile << stDataLine << endl;

        MyFile.close();
    }
}

void AddNewClient()
{
    sClient Client;
    Client = ReadNewClient();
    AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void AddNewClients()
{
    char AddMore = 'Y';
    do
    {
        //system("cls");
        cout << "Adding New Client:\n\n";

        AddNewClient();
        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');

}

bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {

        PrintClientCard(Client);

        cout << "\n\nAre you sure you want delete this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveCleintsDataToFile(ClientsFileName, vClients);

            //Refresh Clients
            vClients = LoadCleintsDataFromFile(ClientsFileName);

            cout << "\n\nClient Deleted Successfully.";
            return true;
        }

    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
}

bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{

    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {

        PrintClientCard(Client);
        cout << "\n\nAre you sure you want update this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            for (sClient& C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }

            SaveCleintsDataToFile(ClientsFileName, vClients);

            cout << "\n\nClient Updated Successfully.";
            return true;
        }

    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
}

string ReadClientAccountNumber()
{
    string AccountNumber = "";

    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;

}

void ShowDeleteClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDelete Client Screen";
    cout << "\n-----------------------------------\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClients);
}

void ShowUpdateClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tUpdate Client Info Screen";
    cout << "\n-----------------------------------\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);

}

void ShowAddNewClientsScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tAdd New Clients Screen";
    cout << "\n-----------------------------------\n";

    AddNewClients();
}

void ShowFindClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tFind Client Screen";
    cout << "\n-----------------------------------\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    sClient Client;
    string AccountNumber = ReadClientAccountNumber();
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
        PrintClientCard(Client);
    else
        cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";
}

void ShowEndScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tProgram Ends :-)";
    cout << "\n-----------------------------------\n";
}

enum enMainMenueOptions
{
    eListClients = 1, eAddNewClient = 2,
    eDeleteClient = 3, eUpdateClient = 4,
    eFindClient = 5, eExit = 6
};

void GoBackToMainMenue()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    ShowMainMenue();

}

short ReadMainMenueOption()
{
    cout << "Choose what do you want to do? [1 to 6]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}

void PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
{
    switch (MainMenueOption)
    {
    case enMainMenueOptions::eListClients:
    {
        system("cls");
        ShowAllClientsScreen();
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOptions::eAddNewClient:
        system("cls");
        ShowAddNewClientsScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eDeleteClient:
        system("cls");
        ShowDeleteClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eUpdateClient:
        system("cls");
        ShowUpdateClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eFindClient:
        system("cls");
        ShowFindClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eExit:
        system("cls");
        ShowEndScreen();
        break;
    }
}

void ShowMainMenue()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tMain Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Exit.\n";
    cout << "===========================================\n";
    PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
}

int main()

{
    ShowMainMenue();
    system("pause>0");
    return 0;
}
 */