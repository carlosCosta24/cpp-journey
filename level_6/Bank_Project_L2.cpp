/* requirements
 * log screen , user file for user, default username: admin , password: 1234 done;
 * Mange user option, logout done;
 * mange user menu: list users, add new user, delete user, update user , find user, main menu done;
 * use bitwise operation and to add the permissions
 * deny deleting the admin account
 *
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <limits>
#include <unistd.h>
using namespace std;
struct stPermissions {
    bool FullAccess = false;
    bool ShowClintList = false;
    bool AddNewClint = false;
    bool DeleteClint = false;
    bool UpdateClint = false;
    bool FindClint = false;
    bool ShowTransactions = false;
    bool ManageUsers = false;
};
struct stUser {
    string Name;
    string Password;
    stPermissions Permissions;
    string PermissionsFlag;
    bool Selected = false;
};
struct stUserLogin {
    string Username;
    string Password;
};
struct stClient {
    string account;
    string password;
    string phone;
    string name;
    double balance;
    bool selected;
};
enum enPermissionValue {
    FullAccess =-1,
    ShowClintList=1,
    AddNewClint=2,
    DeleteClint=3,
    UpdateClint=4,
    FindClint=5,
    ShowTransactions=6,
    ManageUsers=7,
};
stUserLogin LoginScreen() {
    stUserLogin Login;
    cout << "\t\t\t================================"<<endl;
    cout << "\t\t\t\t\t\tLogin: " << endl;
    cout << "\t\t\t================================"<<endl;
    cout << "Enter Username? ";
    cin>> Login.Username;
    cout << "Enter Password? ";
    cin>> Login.Password;
    return Login;
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
vector <stUser> vConvertLineToUsers(vector<string> Lines) {
    vector <stUser> vUsers;
    for (string Line : Lines) {
        vector<string> vUser = vSpliter(Line, "/*/");
        if (vUser.size() >= 3) {
            stUser User;
            User.Name = vUser[0];
            User.Password = vUser[1];
            User.PermissionsFlag = vUser[2];
            vUsers.push_back(User);
        }
    }
    return vUsers;
}
//login
//check for user in users list
bool IsUser(vector<stUser> Users, string UserName) {
    for (const stUser &User : Users) {
        if (User.Name == UserName) {
            return true;
        }
    }
    return false;
}
bool UserExists(vector<stUser>& List, string& UserName) {
    for (const stUser& user : List) {
        if(user.Name == UserName) return true;
    }
    return false;
}
bool IsCorrect(vector<stUser> Users, string Password) {
    for (const stUser &User : Users) {
        if (User.Password == Password) {
            return true;
        }
    }
    return false;
}
// check if password is correct
bool IsCorrectPassword(vector<stUser> Users,stUser UserName,  short Password) {
    for (stUser &User : Users) {
        if (User.Name == UserName) {
            string UserPassword = User.Password;
            if (UserPassword == Password) {
                return true;
            }
        }
    }

    return false;
}
// Access denied
void AccessDenied() {
    cout << "\t\t\t================================"<<endl;
    cout << "\t\t\t\t\t\tAccess denied,\n "
            "You don't have permission,\n "
            "Contact your admin!!" << endl;
    cout << "\t\t\t================================"<<endl;
}
//creating a new user
void AddUserScreen(){
    cout << "\t\t\t================================"<<endl;
    cout << "\t\t\t\t\t\tAdd New User Screen" << endl;
    cout << "\t\t\t================================"<<endl;
    cout << "Adding New User:" << endl;
}
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
//user listing
void UsersHeaderPrinter(short Number){
    cout << "\t\t\t\t\t\t\t\t Users list (" << Number << ") User(s)" << endl;
    cout << "_______________________________________________________________________________________________"<< endl;
    cout << left << setw(18)<<"|User Name";
    cout << left << setw(15)<<"|Password";
    cout << left << setw(30)<<"|Permissions";
    cout << "_______________________________________________________________________________________________"<< endl;

}
void UsersListPrinter(vector<stUser>& vUsers) {
    for (const stUser& User : vUsers) {
        cout << left << setw(18) << "|" + User.Name;
        cout << left << setw(15) << "|" + User.Password;
        cout << left << setw(30) << "|" + User.PermissionsFlag;
    }
    cout << "-----------------------------------------------------------------------------------------------" << endl;}
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
void BalancesPrinter(vector<stClient>& vList) {
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
//add New user
void AddUser(vector<stUser>& List) {
    stUser User;
    char Answer = '';
    cout<< "Enter Username: ";
    cin >> User.Name;
    if (UserExists(List, User.Name)) {
    cout << "User already exists" << endl;
    return;
    }
    cout<< "Enter Password: ";
    cin >> User.Password;

    cout << "Do you want to give full access? y/n? ";
    cin >>  Answer;
    Answer = toupper(Answer);
    while(Answer != 'Y' && Answer != 'N') {
        cout <<"Invalid Input! Do you want to give full access? y/n? ";
        cin >> Answer;
    }
    (Answer == 'Y')? User.Permissions.FullAccess = true : User.Permissions.FullAccess = false;
    (User.Permissions.FullAccess == true)? User.PermissionsFlag = -1 : User.PermissionsFlag = 0;
    if (User.Permissions.FullAccess == false) {
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
    if (User.Permissions.FullAccess == true) {
        User.PermissionsFlag = -1;
    }else {
        if (User.Permissions.ShowClintList  == true )  User.PermissionsFlag &=  enPermissionValue::ShowClintList;
        if (User.Permissions.AddNewClint  == true )  User.PermissionsFlag &=  enPermissionValue::AddNewClint;
        if (User.Permissions.DeleteClint  == true )  User.PermissionsFlag &=  enPermissionValue::DeleteClint;
        if (User.Permissions.UpdateClint  == true )  User.PermissionsFlag &=  enPermissionValue::UpdateClint;
        if (User.Permissions.FindClint  == true )  User.PermissionsFlag &=  enPermissionValue::FindClint;
        if (User.Permissions.ShowTransactions  == true )  User.PermissionsFlag &=  enPermissionValue::ShowTransactions;

    }
    List.push_back(User);
    cout << "User Added Successfully!" << endl;
}
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
void SearchClient(vector<stClient>& List, string AccountNumber) {
    for (stClient& Client : List) {
        if (Client.account == AccountNumber) {
            ClientCard(Client);
            return;
        }
    }
    cout<< "Client not found!" << endl;
}
//Find User & user info card
void UserCard(stUser User) {
    cout << "The following are the User details: "<< endl;
    cout<< "-----------------------------------------------"<< endl;
    cout << "User Name  :" << User.Name << endl;
    cout << "Password   :" << User.Password << endl;;
    cout << "Permissions:" << User.PermissionsFlag << endl;
    cout<< "-----------------------------------------------"<< endl;

}
void FindUser(vector<stUser> UserList, string UserName) {
    for (stUser& user:  UserList) {
        if (user.Name == UserName) {
            UserCard(user);
        }
    }
    cout << "User Not Found!" << endl;
}
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

void Start() {
    const string DataBase = "bank.txt";
    const string Users = "users.txt";
    vector<string> vData = vReadFile(DataBase);
    vector<string> vUsers = vReadFile(Users);
    vector<stClient> vDataList = vConvertLineToClients(vData);
    vector<stUser> vUsersList = vConvertLineToUsers(vUsers);
    while (true) {
        ClearScreen();
        stUserLogin UserCredentials = LoginScreen();
        while (IsUser(vUsersList,UserCredentials.Username) != true  ||
            IsCorrect(vUsersList, UserCredentials.Password) != true) {
            cout << "Invalid Username/Password!" << endl;
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
            if (!CurrentUser.Permissions.ShowClintList) {

                AccessDenied();
                cout << "Press any key to back to main menu..."<<endl;
                cin.get();
            } else {

                short Length = vDataList.size();
                TablePrinter(Length);
                clientsListPrinter(vDataList);
                cout << "Press any key to back to main menu..."<<endl;
                cin.get();
            }
            break;
        }
        case 2: {

            ClearScreen();
            if (!CurrentUser.Permissions.AddNewClint) {
                AccessDenied();
                cout << "Press any key to back to main menu..."<<endl;
                cin.get();

            }else {
                AddClient(vDataList);

                SaveClientsToFile(DataBase, vDataList);

                cout << "Press any key to back to main menu..."<<endl;

                cin.get();

            }
            break;
        }
        case 3: {

            ClearScreen();
            if (!CurrentUser.Permissions.DeleteClint) {
                AccessDenied();
                cout << "Press any key to back to main menu..."<<endl;
                cin.get();

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
                    cout << "Press any key to back to main menu..."<<endl;
                    cin.ignore();
                    cin.get();
                }
            }
            break;
        }
        case 4: {
            ClearScreen();
            if (!CurrentUser.Permissions.UpdateClint) {
                AccessDenied();
                cout << "Press any key to back to main menu..."<<endl;
                cin.get();
            }else {
                string ClientAccount;
                cout << "Enter Client Account: "<<endl;
                cin >> ClientAccount;
                UpdateClient(vDataList, ClientAccount);
                SaveClientsToFile(DataBase, vDataList);
                cout << "Press any key to back to main menu..."<<endl;
                cin.ignore();
                cin.get();
            }
            break;
        }
        case 5: {

            ClearScreen();
            if (!CurrentUser.Permissions.FindClint) {
                AccessDenied();
                cout << "Press any key to back to main menu..."<<endl;
                cin.get();
            }else {

                string ClientIdentifier;
                cout << "Enter Account Number: "<<endl;
                cin >> ClientIdentifier;
                SearchClient(vDataList, ClientIdentifier);
                cout<< "Press any key to back to main menu..."<< endl;
                cin.ignore();
                cin.get();
            }

            break;
        }
        case 6: {
            ClearScreen();
            if (!CurrentUser.Permissions.ShowTransactions) {
                AccessDenied();
                cout << "Press any key to back to main menu..."<<endl;
                cin.get();
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
                        BalancesPrinter(vDataList);
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
            }
            break;
        }
        case 7: {
            ClearScreen();
            if (!CurrentUser.Permissions.ManageUsers) {
                AccessDenied();
                cout << "Press any key to back to main menu..."<<endl;
                cin.ignore();
            }else {
                short Choice;
                cin >> Choice;
                switch (Choice) {
                    case 1: {
                        ClearScreen();
                        short UsersNumber = vUsersList.size();
                        UsersHeaderPrinter(UsersNumber);
                        UsersListPrinter(vUsersList);
                        cout << "Press any key to back to main menu..."<<endl;
                        cin.ignore();
                        cin.get();
                        break;
                    }
                    case 2: {
                        ClearScreen();
                        AddUser(vUsersList);
                        SaveUserToFile(vUsersList, Users);
                        cout << "Press any key to back to main menu..."<<endl;
                        cin.ignore();
                        cin.get();
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
                            cout << "Press any key to back to main menu..."<<endl;
                            cin.ignore();
                            cin.get();
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
                           cout << "Press any key to back to main menu..."<<endl;
                           cin.ignore();
                           cin.get();
                    }
                    case 5: {
                        ClearScreen();
                        string UserToFind;
                        cout << "Enter user name?";
                        cin >> UserToFind;
                        FindUser(vUsersList, UserToFind);
                        cout<< "Press any key to back to main menu..."<<endl;
                        cin.ignore();
                        cin.get();
                        break;

                    }
                    case 6: {
                        ClearScreen();
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

            }
        }
            case 8: {
            ClearScreen();
            return;
        }
        default: f{
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