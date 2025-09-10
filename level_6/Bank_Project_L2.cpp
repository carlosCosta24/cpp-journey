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
    double balance;
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
stClient AddClient(vector<stClient>& List) {
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

stUser ReadUser() {
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

bool FindUserNameAndPassword
(string UserName,string Password, stUser& User) {
    vector <stUser> vUserList = LoadUsers(Users);

    for (stUser& user:  vUserList) {
        if (user.Name == UserName) {
            TargetUser = user;
            return true;
        }
    }
    return  false;
}

for (const stUser &User : Users) {
    if (User.Name == UserName) {
        return true;
    }
}
return false;
}

bool IsCorrect(vector<stUser> Users, string UserName ,short Password) {
    for (const stUser &User : Users) {
        if (User.Name == UserName) {
            if (User.Password == Password) {
                return true;
            }
        }
    }
    return false;
}
// struct stPermissions {
//     bool FullAccess = false;
//     bool ShowClintList = false;
//     bool AddNewClint = false;
//     bool DeleteClint = false;
//     bool UpdateClint = false;
//     bool FindClint = false;
//     bool ShowTransactions = false;
//     bool ManageUsers = false;
// };

// struct stUserLogin {
//     string Username;
//     short Password;
// };

// enum enPermissionValue {
//     FullAccess =-1,
//     ShowClintList=1,
//     AddNewClint=2,
//     DeleteClint=3,
//     UpdateClint=4,
//     FindClint=5,
//     ShowTransactions=6,
//     ManageUsers=7,
// };
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




//login
//check for user in users list
bool IsUser(vector<stUser> Users, string UserName) {

// check if password is correct
bool IsCorrectPassword(vector<stUser> Users,string UserName,  short Password) {
    for (stUser &User : Users) {
        if (User.Name == UserName) {
            short UserPassword = User.Password;
            if (UserPassword == Password) {
                return true;
            }
        }
    }

    return false;
}
// Access denied

//creating a new user
void AddUserScreen(){
    cout << "\t\t\t================================"<<endl;
    cout << "\t\t\t\t\t\tAdd New User Screen" << endl;
    cout << "\t\t\t================================"<<endl;
    cout << "Adding New User:" << endl;
}
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

//Add New client


//add New user

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
//Delete user
void MarkForUserDeletion(vector<stUser>& List, string UserName) {
    vector<stUser> vNewList;
    for (stUser& User : List) {
        if (User.Name == UserName) {
            User.Selected = true;
            cout<< "Deleting....";
            return;
        }
    }
    cout<< "User Not Found!"<<endl;
}
void DeleteUser(vector<stUser>& List) {
    vector<stUser> NewList;
    for (stUser& User : List) {
        if (User.Selected == false) {
            NewList.push_back(User);
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
//update user
void UpdateUserInfo(stUser& User) {
    cout << "Enter New Password (current: " << User.Password << "): ";
    cin >> User.Password;
    cout << "Do want to give access to:"<< endl;
    cout << "Show Client List? y/n? ";
    cin >> User.Permissions.ShowClintList;
    cout << "Add New Client? y/n?";
    cin >>  User.Permissions.AddNewClint;
    cout << "Delete Client? y/n?";
    cin >> User.Permissions.DeleteClint;
    cout << "Update Client? y/n?";
    cin >> User.Permissions.UpdateClint;
    cout << "Find Client? y/n?";
    cin >> User.Permissions.FindClint;
    cout << "Show Transactions Menu? y/n?";
    cin >> User.Permissions.ShowTransactions;
    cout << "Manage Users? y/n? ";
    cin >> User.Permissions.ManageUsers;
}
void UpdateUsers(vector<stUser>& List, string UserName) {
    for (stUser& User : List) {
        if (User.Name == UserName) {
            UpdateUserInfo(User);
            cout << "User Updated Successfully!" << endl;
            return;
        }
    }
    cout << "User Not Found!" << endl;

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
// save new users
void SaveUserToFile(vector<stUser> UserList, string fileName) {
    fstream file(fileName);
    if (file.is_open()) {
        for (stUser& user : UserList) {
            file << user.Name << "/*/"
            << user.Password << "/*/"
            << user.PermissionsFlag << endl;
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