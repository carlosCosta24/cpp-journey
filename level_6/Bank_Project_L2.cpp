#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <thread>
using namespace std;

struct stUser {
    string Name;
    string Password;
    int PermissionsFlag;
    bool Selected = false;
};

enum enTransactionsMenuOptions {
    eDeposit = 1,
    eWithdraw = 2,
    eShowTotalBalance =3,
    eShowMainMenu = 4
};

enum enManageUsersMenuOptions {
    eListUsers = 1,
    eAddNewUser = 2,
    eDeleteUser = 3,
    eUpdateUser = 4,
    eFindUser = 5,
    eMainMenu = 6
};

enum enMainMenuOptions {
    eListClint = 1,
    eAddNewClint = 2,
    eDeleteClint = 3,
    eUpdateClint = 4,
    eFindClint = 5,
    eShowTransactionsMenu = 6,
    eManageUsers = 7,
    eExit = 8
};

enum enMainMenuPermissions {
    eAll = -1,
    pListClients = 1,
    pAddNewClient = 2,
    pDeleteClient = 4,
    pUpdateClient = 8,
    pFindClient = 16,
    pTransactions = 32,
    pMenageUsers = 64
};

const string DataBase = "bank.txt";
const string Users = "users.txt";
stUser CurrentUser;

void ShowMainMenu();
void ShowTransactionsMenu();
void ShowManageUsersMenu();
bool CheckAccessPermission(enMainMenuPermissions Permission);
void login();

struct stClient {
    string account;
    string password;
    string phone;
    string name;
    double balance = 0;
    bool selected = false;
};

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
stUser ConvertLineToUsers(string Line, string Delim = "/*/") {
    stUser User;
    vector<string> vUser = vSpliter(Line, Delim);
    User.Name = vUser[0];
    User.Password = vUser[1];
    User.PermissionsFlag = stoi(vUser[2]);
    return User;
}

stClient ConvertLineToClients(string Line, string Delim = "/*/") {
    stClient Client;
    vector<string> vClientData = vSpliter(Line, Delim);

            Client.account = vClientData[0];
            Client.password =  vClientData[1];
            Client.name = vClientData[2];
            Client.phone = vClientData[3];
            Client.balance =stod(vClientData[4]);

    return Client;
};

string ConvertRecordToLine(stClient Client, string Delim = "/*/") {
    string Record = "";

    Record += Client.account + Delim;
    Record += Client.password + Delim;
    Record += Client.phone + Delim;
    Record += Client.name + Delim;
    Record += Client.phone + Delim;
    Record += to_string(Client.balance) + Delim;
    return Record;
}

string ConvertUserRecordToLine(stUser User, string Delim = "/*/") {

    string stClintRecord = "";

    stClintRecord += User.Name + Delim;
    stClintRecord += User.Password + Delim;
    stClintRecord += to_string(User.PermissionsFlag) + Delim;

    return stClintRecord;
}

bool IsAccountExists(const string AccountNumber, const string FileName) {

    vector <stClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open()) {
        string Line;
        stClient Client;
        while (getline(MyFile, Line)) {
            Client = ConvertLineToClients(Line);
            if (Client.account == AccountNumber) {
                MyFile.close();
                return true;
            }

            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return false;
}

bool ISUserExists(string UserName, string FileName) {
    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open()) {
        string Line;
        stUser User;
        while (getline(MyFile, Line)) {
            User = ConvertLineToUsers(Line);
            if (User.Name == UserName) {
                MyFile.close();
                return true;
            }
        }
        MyFile.close();
    }
    return false;

}

stClient AddClient() {
    stClient Client;

    cout<< "Enter Account Number: ";

    getline(cin >> ws, Client.account);

    while (IsAccountExists(Client.account, DataBase)) {

        cout << "\nClient already exists[ " << Client.account<<
            " ] already exist, Enter another account? ";
        getline(cin >> ws, Client.account);
    }

    cout<< "Enter Password: ";
    getline(cin >> ws, Client.password);

    cout<< "Enter Name: ";
    getline(cin >> ws, Client.name);

    cout<< "Enter Client Phone: ";
    getline(cin>> ws, Client.phone);

    cout<< "Enter Client Balance: ";
    cin >> Client.balance;


    cout<< "Client Added Successfully!" << endl;
    return Client;
};

char Capitalize(const char & character) {
    return toupper(character);
}

int SetPermissions() {

    int Permissions = 0;
    char Answer = 'N';

    cout << "Do you want to give full access? y/n? ";
    cin >> Answer;
    Capitalize(Answer);
    if (Answer == 'Y') {
        return -1;
    }

    cout << "\nDo you want to give access to : \n";

    cout << "\nShow Client List? y/n? ";
    cin >> Answer;
    Capitalize(Answer);
    if (Answer == 'Y') {
        Permissions += enMainMenuPermissions::pListClients;
    }

    cout << "\nAdd New Client? y/n? ";
    cin >> Answer;
    Capitalize(Answer);
    if (Answer == 'Y') {
        Permissions += enMainMenuPermissions::pAddNewClient;
    }

    cout << "\nDelete Client? y/n? ";
    cin >> Answer;
    Capitalize(Answer);
    if (Answer == 'y')
    {
        Permissions += enMainMenuPermissions::pDeleteClient;
    }

    cout << "\nUpdate Client? y/n? ";
    cin >> Answer;
    Capitalize(Answer);
    if (Answer == 'y')
    {
        Permissions += enMainMenuPermissions::pUpdateClient;
    }

    cout << "\nFind Client? y/n? ";
    cin >> Answer;
    Capitalize(Answer);
    if (Answer == 'y')
    {
        Permissions += enMainMenuPermissions::pFindClient;
    }

    cout << "\nTransactions? y/n? ";
    cin >> Answer;
    Capitalize(Answer);
    if (Answer == 'y')
    {
        Permissions += enMainMenuPermissions::pTransactions;
    }

    cout << "\nManage Users? y/n? ";
    cin >> Answer;
    Capitalize(Answer);
    if (Answer == 'y' )
    {
        Permissions += enMainMenuPermissions::pMenageUsers;
    }


    return Permissions;

}

stUser AddUser() {
    stUser User;

    cout << "Enter Username? ";
    getline(cin >> ws, User.Name);

    while (ISUserExists(User.Name, DataBase)) {

        cout << "\nUser with Username[ " <<
            User.Name<<" ] Exist, Enter New User? ";
        getline(cin>> ws , User.Name);
    }

    cout << "\nEnter Password: ";
    getline(cin >> ws, User.Password);

    User.PermissionsFlag = SetPermissions();

    return User;
};


vector <stUser> LoadUsers(string FileName) {

    vector <stUser> vUsers;

    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {

        string Line;
        stUser User;

        while (getline(MyFile, Line))
        {

            User = ConvertLineToUsers(Line);

            vUsers.push_back(User);
        }

        MyFile.close();

    }

    return vUsers;
}

vector <stClient> LoadClients(string FileName) {

    vector <stClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {

        string Line;
        stClient Client;

        while (getline(MyFile, Line))
        {

            Client = ConvertLineToClients(Line);

            vClients.push_back(Client);
        }

        MyFile.close();

    }

    return vClients;
}

void PrintClint(stClient Client) {
    cout << "Account Number    :"<<Client.account << endl;
    cout << "Name of Client    :"<<Client.name << endl;
    cout << "Phone Number      :"<<Client.phone << endl;
    cout << "Balance of Client :"<<Client.balance << endl;
}

void PrintUser(stUser User){


    cout << "_______________________________________________________________________________________________"<< endl;
    cout <<"|User Name" <<left << setw(18)<< User.Name;
    cout <<"|Password" <<left << setw(15)<< User.Password;
    cout <<"|Permissions" <<left << setw(30) << User.PermissionsFlag;
    cout << "_______________________________________________________________________________________________"<< endl;
}

void PrintClientBalance(stClient Client) {
    cout << "Account Number    :"<<Client.account << endl;
    cout << "Name of Client    :"<<Client.name << endl;
    cout << "Balance of Client :"<<Client.balance << endl;
}

void AccessDenied() {
    cout << "\t\t\t================================"<<endl;
    cout << "\t\t\t\t\t\tAccess denied,\n "
            "You don't have permission,\n "
            "Contact your admin!!" << endl;
    cout << "\t\t\t================================"<<endl;
}

void clientsListPrinter() {
    if (!CheckAccessPermission(enMainMenuPermissions::pListClients)) {
        AccessDenied();
        return;
    }
    vector <stClient> vClients = LoadClients(DataBase);
    cout << "Clients List (" << vClients.size() << ") client(s)." << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;

    cout << "|" <<left << setw(18) <<  "Account Number";
    cout << "|" <<left << setw(15) <<  "Password ";
    cout << "|" <<left << setw(30) <<  "Client Name";
    cout << "|" <<left << setw(15) <<  "Phone";
    cout << "|" <<left << setw(15) <<  "Balance";

    cout << "-----------------------------------------------------------------------------------------------" << endl;

    if (vClients.size() == 0) {
        cout << "No client available in the system!!";
    }else {
        for (stClient Client : vClients) {
            PrintClint(Client);
            cout << endl;
        }
    }
    cout << "-----------------------------------------------------------------------------------------------" << endl;

}

void UsersListPrinter() {
    vector <stUser> vUsers = LoadUsers(Users);
    cout << "Users List (" << vUsers.size() << ") Users(s)." << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;

    cout <<"|"<< left << setw(18) << "User Name";
    cout <<"|"<< left << setw(15) << "User Password";
    cout <<"|"<< left << setw(30) << "User Permissions";
    cout << endl;

    cout << "-----------------------------------------------------------------------------------------------" << endl;

    if (vUsers.size() == 0) {
        cout << "No user available in the system!!";
    }else {
        for (stUser User : vUsers) {
            PrintUser(User);
            cout << endl;
        }
    }
    cout << "-----------------------------------------------------------------------------------------------" << endl;

}

void BalancesPrinter() {

    vector <stClient> vClients = LoadClients(DataBase);
    double TotalBalance = 0;
    cout << "Balance List (" << vClients.size() << ") client(s)." << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;

    cout << "| " <<left << setw(18) << "Account Number";
    cout << "| " <<left << setw(30) << "Client Name";
    cout << "| " <<left << setw(15) << "Balance";

    cout << "-----------------------------------------------------------------------------------------------" << endl;

    if (vClients.size() == 0) {
        cout << "No client available to show the balance !";
    }else {
        for (stClient Client : vClients) {
            PrintClientBalance(Client);
            TotalBalance += Client.balance;
            cout << endl;
        }
    }
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t Total balance = " << TotalBalance<<  endl;
}

void PrintClintCard(stClient Client) {
    cout << "\nThe following are the client details:\n";
    cout << "\n-----------------------------------\n";
    cout << "Account Number    :"<<Client.account << endl;
    cout << "Phone Number      :"<<Client.phone << endl;
    cout << "Name of Client    :"<<Client.name << endl;
    cout << "Balance of Client :"<<Client.balance << endl;
    cout << "\n-----------------------------------\n";
}

void PrintUserCard(stUser User) {

    cout << "The following are the User details: "<< endl;
    cout<< "-----------------------------------------------"<< endl;
    cout << "User Name  :" << User.Name << endl;
    cout << "Password   :" << User.Password << endl;;
    cout << "Permissions:" << User.PermissionsFlag << endl;
    cout<< "-----------------------------------------------"<< endl;

}

bool SearchClient(vector<stClient>& List, string AccountNumber, stClient& TargetClient) {
    for (stClient& Client : List) {
        if (Client.account == AccountNumber) {
            Client = TargetClient;
            return true;
        }
    }
    return false;
}

bool SearchUser(vector<stUser>& List, string UserName, stUser& TargetUser) {
    for (stUser& User : List) {
        if (User.Name == UserName) {
            TargetUser = User;
            return true;
        }
    }
    return false;
}

bool FindUserUsingNameAndPassword(string UserName,string Password, stUser& User) {
    vector <stUser> vUserList = LoadUsers(Users);

    for (stUser& user:  vUserList) {
        if (user.Name == UserName && user.Password == Password) {
            User = user;
            return true;
        }
    }
    return  false;
}

stClient UpdateClintInfo(string AccountNumber) {
    stClient Client;
    Client.account = AccountNumber;

    cout << "Enter New Password (current: " << Client.password << "): ";
    getline(cin>> ws, Client.password);

    cout << "Enter New Client Name (current: " << Client.name << "): ";
    getline(cin, Client.name);

    cout << "Enter New Client Phone (current: " << Client.phone << "): ";
    getline(cin, Client.phone);

    cout << "Enter Client Balance (current: " << Client.balance << "): ";
    cin >> Client.balance;

    cout << "Client Info Updated Successfully!" << endl;
    return Client;
}

stUser UpdateUserInfo(string UserName) {
    stUser User;
    User.Name = UserName;

    cout << "Enter Password"<<endl;
    getline(cin >> ws, User.Password);

    User.PermissionsFlag = SetPermissions();

    return User;
}

bool MarkClientForDeletion(vector<stClient>& List, string ClientAccount) {

    for (stClient& Client : List) {
        if (Client.account == ClientAccount) {
            Client.selected = true;
            return true;
        }
    }
    return false;
}

bool MarkUserForDeletion(vector<stUser>& List, string UserName) {

    for (stUser& User : List) {
        if (User.Name == UserName) {
            User.Selected = true;
            return true;
        }
    }
    return false;
}

vector<stClient> SaveClientsToFile(string fileName, vector<stClient> vclients) {
    fstream MyFile;
    MyFile.open(fileName, ios::out);

    string Line;

    if (MyFile.is_open()) {

        for (stClient client : vclients) {
            if (client.selected == false) {
                Line = ConvertRecordToLine(client);
                MyFile << Line<< endl;
            }
        }
        MyFile.close();

    }
    return vclients;
}
// save new users
vector <stUser> SaveUserToFile(vector<stUser> vUserList, string fileName) {

    fstream MyFile;
    MyFile.open(fileName, ios::out);

    string Line;

    if (MyFile.is_open()) {

        for (stUser& user : vUserList) {

            if (user.Selected == false) {
                Line = ConvertUserRecordToLine(user);
                MyFile << Line<< endl;
            }

        }
        MyFile.close();
    }
    return vUserList;
}

void AddLineToFile(string FileName, string Line) {
    fstream MyFile;
    MyFile.open(FileName, ios::out| ios::app);

    if (MyFile.is_open()) {
        MyFile << Line << endl;
        MyFile.close();
    }
}

void AddNewClient() {
    stClient Client;

    Client = AddClient();

    AddLineToFile(DataBase, ConvertRecordToLine(Client));

}

void AddNewUser() {
    stUser User;

    User = AddUser();

    AddLineToFile(Users, ConvertUserRecordToLine(User));

}

void AddNewClients() {
    char Answer = 'Y';
    do {
        cout << "Adding New Clients" << endl;

        AddNewClient();
        cout << "Client added successfully, Do you Want to add more clients?? Y/N?"<< endl;
        cin >> Answer;
        Answer = Capitalize(Answer);

    }while (Answer == 'Y');
}

void addNewUsers() {
    char Answer = 'Y';
    do {
        cout << "Adding New Clients" << endl;

        AddNewUser();
        cout << "User added successfully, Do you Want to add more Users?? Y/N?"<< endl;
        cin >> Answer;
        Answer = Capitalize(Answer);

    }while (Answer == 'Y');
}

bool DeleteClient(string Account, vector<stClient>& List) {
    stClient Client;
    char Answer = 'N';

    if (SearchClient(List, Account, Client)) {

        PrintClintCard(Client);

        cout << "Are you sure you want to delete this client?? Y/N";
        cin >> Answer;
        Answer = Capitalize(Answer);

        if (Answer == 'Y') {
            MarkClientForDeletion(List, Account);
            SaveClientsToFile(DataBase, List);
            List = LoadClients(DataBase);

            cout << "Client Deleted Successfully!" << endl;
            return true;
        }
    }
    else {

        cout << "Client Not Found!" << endl;
        return false;

    }

    vector<stClient> NewList;
    for (stClient& Client : List) {

    }
    List = NewList;
}
//Delete user

bool DeleteUser(string UserName, vector<stUser>& List) {

    if (UserName == "Admin") {
        cout << "You cant Delete this User!!!"<< endl;
        return false;
    }

    stUser User;
    char Answer = 'N';
    if (SearchUser(List, UserName, User)) {
        PrintUserCard(User);
        cout << "Are you sure you want to delete this user?? Y/N?";
        cin >> Answer;
        Answer = Capitalize(Answer);
        if (Answer == 'Y') {
            MarkUserForDeletion(List, UserName);
            SaveUserToFile(List, Users);
            List = LoadUsers(DataBase);
            cout << "User Deleted Successfully!" << endl;
            return true;
        }
    }else {
        cout << "User Not Found!" << endl;
        return false;
    }

}

bool UpdateClient(vector<stClient>& List, string AccountNumber) {
    stClient TargetedClient;
    char Answer = 'N';

    if (SearchClient(List, AccountNumber, TargetedClient)) {

        PrintClintCard(TargetedClient);
        cout << "Are you sure you want to update this client ?? Y/N?";
        cin >> Answer;
        Answer = Capitalize(Answer);

        if (Answer == 'Y') {
            for (stClient& Client : List) {
                if (Client.account == AccountNumber) {
                    Client = UpdateClintInfo(Client.account);
                    break;
                }
            }
            SaveClientsToFile(DataBase, List);

            cout << "Client Updated Successfully!" << endl;
            return true;
        }

    }else {
        cout << "Client Not Found!" << endl;
        return false;
    }
}

bool UpdateUser(vector<stUser>& List, string UserName) {

    stUser TargetUser;
    char Answer = 'N';
    if (SearchUser(List, UserName, TargetUser)) {
        PrintUserCard(TargetUser);
        cout << "Are you sure you want to update this user?? Y/N";
        cin >> Answer;
        Answer = Capitalize(Answer);
        if (Answer == 'Y') {
            for (stUser& User : List) {
                if (User.Name == UserName) {
                    User = TargetUser;

                    User = UpdateUserInfo(UserName);
                    break;
                }
            }
                    SaveUserToFile(List,Users);
                    cout << "User Updated successfully "<< endl;
                    return true;
        }

    }
    else {
        cout << "User Not Found!" << endl;
        return false;
    }



    cout << "User Not Found!" << endl;
}

bool Deposit(vector<stClient>& List ,string AccountNumber, double Amount) {
    char Answer = 'N';
    cout << "Are you sure you want to perform this action?? Y/N??";
    cin >> Answer;
    Answer = Capitalize(Answer);
    if (Answer == 'Y') {


    for (stClient& Client : List) {
        if (Client.account == AccountNumber) {

            Client.balance += Amount;
            SaveClientsToFile(Users, List);
            cout << "Amount Updated successfully, New Account balance is [ "
            << Client.balance<<
                " ]"<< endl;
            return true;
        }
    }
        }
        return false;
}

string ReadClientAccount() {
    string Account = "";

    cout << "Please Enter Account Number: ";
    cin >> Account;

    return Account;
}

string ReadUseAccount() {
    string Username = "";

    cout << "Please Enter Username: ";
    cin >> Username;

    return Username;
}

void ShowAllUsersList(){

    UsersListPrinter();
}

void AddUserScreen(){
    cout << "\t\t\t================================"<<endl;
    cout << "\t\t\t\t\t\tAdd New User Screen" << endl;
    cout << "\t\t\t================================"<<endl;

    AddNewUser();
}

void DeleteUserScreen() {

    cout << "\n-----------------------------------\n";
    cout << "\tDelete Users Screen";
    cout << "\n-----------------------------------\n";

    vector<stUser> vUsers = LoadUsers(Users);

    string UserName = ReadUseAccount();
    DeleteUser(UserName, vUsers);
}

void AddClientScreen()

{
    cout << "\t\t\t================================"<<endl;
    cout << "\t\t\t\t\t\tAdd New Client Screen" << endl;
    cout << "\t\t\t================================"<<endl;

    AddNewClient();
}

void UpdateUserScreen() {
    cout << "\n-----------------------------------\n";
    cout << "\tUpdate Users Screen";
    cout << "\n-----------------------------------\n";

    vector <stUser> vUsers = LoadUsers(Users);
    string UserName = ReadUseAccount();

    UpdateUser(vUsers, UserName);
}

void DeleteClientScreen() {

    if (!CheckAccessPermission(enMainMenuPermissions::pDeleteClient)) {
        AddUserScreen();
        return;
    }

    cout << "\n-----------------------------------\n";
    cout << "\tDelete Client Screen";
    cout << "\n-----------------------------------\n";

    vector <stClient> vClients = LoadClients(Users);
    string AccountNumber = ReadClientAccount();
    DeleteClient(AccountNumber, vClients);
}

void ClientUpdateScreen() {

    if (!CheckAccessPermission(enMainMenuPermissions::pUpdateClient)) {

        AccessDenied();
        return;
    }

    vector<stClient> vClients = LoadClients(Users);
    string AccountNumber = ReadClientAccount();
    UpdateClient(vClients, AccountNumber );
}

void AddNewClientScreen() {

    if (!CheckAccessPermission(enMainMenuPermissions::pAddNewClient)) {
        AccessDenied();
        return;

    }
    cout << "\n-----------------------------------\n";
    cout << "\tAdd New Clients Screen";
    cout << "\n-----------------------------------\n";

    AddNewClients();

}

void FindClientScreen() {

    if (!CheckAccessPermission(enMainMenuPermissions::pFindClient)) {
        AccessDenied();
        return;
    }
    cout << "\n-----------------------------------\n";
    cout << "\tFind Client Screen";
    cout << "\n-----------------------------------\n";

    vector <stClient> vClients = LoadClients(Users);
    stClient Client;
    string AccountNumber = ReadClientAccount();
    if (SearchClient(vClients,AccountNumber,Client)) {
        PrintClintCard(Client);
    }else {
        cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";
    }

}

void FindUserScreen() {

    cout << "\n-----------------------------------\n";
    cout << "\tFind User Screen";
    cout << "\n-----------------------------------\n";

    vector <stUser> vUsers = LoadUsers(Users);
    stUser User;
    string UserName = ReadUseAccount();

    if (SearchUser(vUsers,UserName,User)) {
        PrintUserCard(User);
    }else {
        cout << "\nUser with Username [" << UserName << "] is not found!";
    }
}

void ShowEndScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tProgram Ends :-)";
    cout << "\n-----------------------------------\n";

}

void DepositScreen() {
    cout << "\n-----------------------------------\n";
    cout << "\tDeposit Screen";
    cout << "\n-----------------------------------\n";

    stClient Client;

    vector <stClient> vClients = LoadClients(Users);
    string AccountNumber = ReadClientAccount();

    while (!SearchClient(vClients,AccountNumber,Client)) {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadClientAccount();
    }

    PrintClintCard(Client);

    double Amount = 0;
    cout << "\nPlease enter deposit amount? ";
    cin >> Amount;

    Deposit(vClients,AccountNumber,Amount);

}























































































void LoginScreen() {
    cout << "\t\t\t================================"<<endl;
    cout << "\t\t\t\t\t\tLogin: " << endl;
    cout << "\t\t\t================================"<<endl;
}

stUserLogin LoginCredentials(stUserLogin & User) {
    cout << "Enter Username? ";
    cin>> User.Username;
    cout << "Enter Password? ";
    cin>> User.Password;
    return User;
}
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
    cout<< "\t\t\t[7] Manage Users."<<endl;
    cout<< "\t\t\t[8] Logout."<<endl;
    cout << "\t\t\t================================"<<endl;
    cout << "\t\t\tChoose What to do? [1 - 7]?"<<endl;
}
void ManageUsersMenu(){
    cout << "\t\t\t================================"<<endl;
    cout << "\t\t\t\t\t\tManage Users Menu Screen " << endl;
    cout << "\t\t\t================================"<<endl;
    cout<< "\t\t\t[1] List Users."<< endl;
    cout<< "\t\t\t[2] Add New User."<<endl;
    cout<< "\t\t\t[3] Delete User."<<endl;
    cout<< "\t\t\t[4] Update User."<<endl;
    cout<< "\t\t\t[5] Find User."<<endl;
    cout<< "\t\t\t[6] Main Menu."<<endl;
    cout << "\t\t\t================================"<<endl;
    cout << "\t\t\tChoose What to do? [1 - 6]?"<<endl;


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



//creating a new user

//Show Client list

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
//user listing


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


void BalancesListHeader(short Number) {
    cout << "\t\t\t\t\t\t\t\t Client list (" << Number << ") Client(s)" << endl;
    cout << "-----------------------------------------------------------------------------------------------"<< endl;
    cout << left << setw(18)<<"|Account Number";
    cout << left << setw(30)<<"|Client Name";
    cout << left << setw(15)<<"|Balance"<< endl;
    cout << "-----------------------------------------------------------------------------------------------"<< endl;
}

//Update Client


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

//Find User & user info card


stUser GetUser(vector<stUser> UserList, string UserName) {
    stUser TargetedUser;
    for (stUser& user:  UserList) {
        if (user.Name == UserName) {
            TargetedUser = user;
        }
    }
    return TargetedUser;
}
// check for permissions
/*bool IsAllowed(vector<stUser>& List,string UserName, bool Permission) {
    if (UserExists(List, UserName)) {
        stUser TargetedUser = GetUser(List, UserName);

        if (TargetedUser.Permissions.Permission == true) {

        }

    }
}*/

void ClearScreen() {
    std::cout << "\033[2J\033[1;1H";
}
//transaction menu operation

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
void stop() {
    AccessDenied();
    cout << "Press any key to back to main menu..."<<endl;
    cin.get();
}
void login() {
    const string DataBase = "bank.txt";
    const string Users = "users.txt";
    stUserLogin CurrentUser;
    vector<string> vData = vReadFile(DataBase);
    vector<string> vUsers = vReadFile(Users);
    vector<stClient> vDataList = vConvertLineToClients(vData);
    vector<stUser> vUsersList = vConvertLineToUsers(vUsers);
    bool IsLoggedIn = false;
    do {
        ClearScreen();
        LoginScreen();
        LoginCredentials(CurrentUser);
        IsLoggedIn = (IsUser(vUsersList,CurrentUser.Username) &&
            IsCorrect(vUsersList,CurrentUser.Username,CurrentUser.Password));
        if (!IsLoggedIn) {
            cout << "Invalid Username/Password!" << endl;
            cin.ignore();
            cin.get();
        }
    }while (!IsLoggedIn);
    Menu();
}
void Next(){
    cout << "Press any key to back to main menu..."<<endl;
    cin.get();

}

void Start() {

    while (true) {
        ClearScreen();
        stUserLogin UserCredentials = LoginScreen();
        while (!(IsUser(vUsersList,UserCredentials.Username) &&
            IsCorrect(vUsersList, UserCredentials.Password))) {
            cout << "Invalid Username/Password!" << endl;
            UserCredentials = LoginScreen();
        }
        stUser CurrentUser = GetUser(vUsersList, UserCredentials.Username);

        Menu();
        cout << endl;
        short Option;
        cin>> Option;
        cin.ignore();

    switch (Option) {
        case 1: {
            ClearScreen();
            if (CurrentUser.Permissions.ShowClintList) {

                stop();
            } else {

                short Length = vDataList.size();
                TablePrinter(Length);
                clientsListPrinter(vDataList);
                Next();
            }
            break;
        }
        case 2: {

            ClearScreen();
            if (!CurrentUser.Permissions.AddNewClint) {
                stop();

            }else {
                AddClient(vDataList);

                SaveClientsToFile(DataBase, vDataList);

                Next();

            }
            break;
        }
        case 3: {

            ClearScreen();
            if (CurrentUser.Permissions.DeleteClint) {
                stop();
            }else {
                string AccountNumber;
                char Answer ;
                cout<< "Enter Account Number to Delete: "<< endl;
                cin >> AccountNumber;
                SearchClient(vDataList, AccountNumber);
                cout << "Are you sure You want to delete this account ?";
                cin >> Answer;
                if (toupper(Answer) == 'Y') {
                    MarkForDeletion(vDataList, AccountNumber);
                    DeleteClient(vDataList);
                    SaveClientsToFile(DataBase, vDataList);
                    Next();
                }
            }
            break;
        }
        case 4: {
            ClearScreen();
            if (CurrentUser.Permissions.UpdateClint) {
                stop();
            }else {
                string ClientAccount;
                cout << "Enter Client Account: "<<endl;
                cin >> ClientAccount;
                UpdateClient(vDataList, ClientAccount);
                SaveClientsToFile(DataBase, vDataList);
                Next();
            }
            break;
        }
        case 5: {

            ClearScreen();
            if (CurrentUser.Permissions.FindClint) {
                stop();
            }else {

                string ClientIdentifier;
                cout << "Enter Account Number: "<<endl;
                cin >> ClientIdentifier;
                SearchClient(vDataList, ClientIdentifier);
                Next();
            }

            break;
        }
        case 6: {
            ClearScreen();
            if (CurrentUser.Permissions.ShowTransactions) {
                stop();
            }else {
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
                        Next();
                        break;
                    }
                    case 2: {
                        string ClientAccount;
                        cout<< "Enter Account Number: "<<endl;
                        cin >> ClientAccount;
                        SearchClient(vDataList, ClientAccount);
                        Withdraw(vDataList, ClientAccount);
                        SaveClientsToFile(DataBase, vDataList);
                        Next();
                        break;

                    }
                    case 3:
                    {
                        BalancesListHeader(vData.size());
                        BalancesPrinter(vDataList);
                        Next();
                        break;
                    }
                    case 4: {
                        Menu();
                        break;
                    }
                    default: {
                        cout << "Invalid Option! Please try again." << endl;
                        Next();
                        break;
                    }
                }
            }
            break;
        }
        case 7: {
            ClearScreen();
            if (CurrentUser.Permissions.ManageUsers) {
                stop();
            }else {
                ManageUsersMenu();
                short Choice;
                cin >> Choice;
                switch (Choice) {
                    case 1: {
                        ClearScreen();
                        short UsersNumber = vUsersList.size();
                        UsersHeaderPrinter(UsersNumber);
                        UsersListPrinter(vUsersList);
                        Next();
                        break;
                    }
                    case 2: {
                        ClearScreen();
                        AddUser(vUsersList);
                        SaveUserToFile(vUsersList, Users);
                        Next();
                        break;
                    }
                    case 3: {
                        ClearScreen();
                        string UserName;
                        char Answer ;
                        cout<< "Enter User Name to Delete: "<< endl;
                        cin >> UserName;
                        FindUser(vUsersList, UserName);
                        cout << "Are you sure You want to delete this account ?";
                        cin >> Answer;
                        if (toupper(Answer) == 'Y') {
                            MarkForUserDeletion(vUsersList, UserName);
                            DeleteUser(vUsersList);
                            SaveUserToFile(vUsersList, Users);
                            Next();
                            break;
                        }

                    }
                    case 4: {
                            ClearScreen();
                           string TargetedUser;
                           cout << "Enter user name?";
                           cin >> TargetedUser;
                           FindUser(vUsersList, TargetedUser);
                           stUser UserToUpdate = GetUser(vUsersList,TargetedUser);
                           UpdateUserInfo(UserToUpdate);
                           SaveUserToFile(vUsersList, Users);
                            Next();
                    }
                    case 5: {
                        ClearScreen();
                        string UserToFind;
                        cout << "Enter user name?";
                        cin >> UserToFind;
                        FindUser(vUsersList, UserToFind);
                        Next();
                        break;

                    }
                    case 6: {
                        ClearScreen();
                        Menu();
                        break;
                    }
                    default: {
                        cout << "Invalid Option! Please try again." << endl;
                        Next();
                        break;
                    }
                }

            }
        }break;
            case 8: {
            ClearScreen();
            return;
        }
        default: {
            cout << "Invalid Option! Please try again." << endl;
                Next();
            break;
        }
    }
}
    }

int main() {
    Start();
    return 0;
}