#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct stClient {
    string account;
    string password;
    string phone;
    string name;
    double balance = 0;
};

enum enATMMainMenu {
    enQuickWithDraw = 1,
    enNormalWithDraw = 2,
    enDeposit = 3,
    enCheckBalance = 4,
    enLogout = 5,
};

enum enQuickWithdrawMenu {
    enQuick_20 = 1,
    enQuick_50 = 2,
    enQuick_100 = 3,
    enQuick_200 = 4,
    enQuick_400 = 5,
    enQuick_600 = 6,
    enQuick_800 = 7,
    enQuick_1000 = 8,
    enExit = 9,

};

const string Database = "bank.txt";
stClient CurrentClient;
void LogIn();
char Capitalize(const char & Character) {
    return toupper(Character);
}

bool ActionConfirmation() {
    char Answer;
    cout << "Are You sure you want to perform this transaction? y/n?" << endl;
    cin >> Answer;
    Answer = Capitalize(Answer);
    return (Answer == 'Y');
}

void QuickWithdrawMenu();

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
    Record += Client.name + Delim;
    Record += Client.phone + Delim;
    Record += to_string(Client.balance) + Delim;
    return Record;
}

vector<stClient> SaveClientsToFile(string fileName, vector<stClient> vClients) {
    fstream MyFile;
    MyFile.open(fileName, ios::out);

    string Line;

    if (MyFile.is_open()) {

        for (stClient client : vClients) {
                Line = ConvertRecordToLine(client);
                MyFile << Line<< endl;

        }
        MyFile.close();

    }
    return vClients;
}

vector<stClient> LoadClients(string FileName) {

    vector<stClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open()) {
        string Line;
        stClient Client;

        while (getline(MyFile, Line)) {
            Client = ConvertLineToClients(Line, "/*/");
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;

}

void AddLineToFile(string FileName, string Line) {
    fstream MyFile;
    MyFile.open(FileName, ios::out| ios::app);

    if (MyFile.is_open()) {
        MyFile << Line << endl;
        MyFile.close();
    }
}

void UpdateClientsFile(string FileName, string ClientAccount, stClient NewClient) {
    vector <stClient> List = LoadClients(FileName);
    for (stClient& C : List) {
        if (C.account == ClientAccount) {
            C = NewClient;
            break;
        }
    }
    SaveClientsToFile(FileName, List);
}

bool CheckClientAndPassword(string FileName, string Account,string Password ) {
    vector <stClient> vDatabase = LoadClients(FileName);
    for (stClient Client : vDatabase) {
        if (Client.account == Account) {
            if (Client.password == Password) {
                return true;
            }
        }
    }
    return false;

}

bool LoadClient(string UserName, string Password) {
    if (CheckClientAndPassword(Database, UserName, Password)) {
        return true;
    }
    return false;
}

void LoginScreen () {
    cout << "--------------------------------------------"<< endl;
    cout << "\t\t\t ATM Login Screen "<< endl;
    cout << "--------------------------------------------"<< endl;
}

int ReadMenuOptions(const short NumberOFOptions) {
    int Option;
    cout << "Choose what do you want to do? [1 - " << NumberOFOptions <<"]?"<< endl;
    cin >> Option;

    return Option;
}

double GetClientBalance() {
    return CurrentClient.balance;
}

void WithDraw(double WithdrawAmount ,stClient & Client) {
    double NewBalance = Client.balance - WithdrawAmount;
    Client.balance = NewBalance;
}

bool HaveSufficientAmount(double ClientBalance, double AmountOfWithDraw) {

    if (ClientBalance > AmountOfWithDraw) {
        return true;
    }else {
        return false;
    }
}

void DeniedTransaction() {
    cout << " You cant perform this transaction\n make another choice"<< endl;

}

void NormalWithdrawMenu() {
    cout << "========================================================" << endl;
    cout << "\t\t Normal Withdraw "<< endl;
    cout << "========================================================" << endl;
}

void MainMenuScreen();

void Deposit() {
    double DepositAmount;
    cout << "Enter Deposit Amount: "<< endl;
    cin >> DepositAmount;
    if (ActionConfirmation()) {
        CurrentClient.balance += DepositAmount;
        cout << "Done successfully, Your current balance is: " << CurrentClient.balance << endl;
        UpdateClientsFile(Database,CurrentClient.account, CurrentClient);
    }else {
        cout << "Transaction cancelled" << endl;
    }

}

double ReadAmount() {
    double Amount;
    cout << "Please Enter Amount : ";
    cin >> Amount;

    return Amount;
}


void ClearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

stClient LoadClientInfo(string& ClientName) {
    vector<stClient> vClients = LoadClients(Database);
    stClient TargetClient;
    for (stClient& Client : vClients) {
        if (Client.account == ClientName) {
              TargetClient = Client;
        }
    }
    return TargetClient;
}

void CheckBalance() {
    cout << "Your Balance is: " << CurrentClient.balance << endl;
}

void NormalWithdraw(stClient& Client) {
    double WithdrawAmount;
    do {
        cout << "Enter an amount multiple of 5's ? "<< endl;
        cout << "Your Current balance: " << Client.balance << endl;
        WithdrawAmount = ReadAmount();

        if (static_cast<int> (WithdrawAmount) % 5 != 0 ) {
            cout << "Amount must be a multiple of 5. Try again. \n";
            continue;
        }
        if (WithdrawAmount >= Client.balance) {

            cout << "the amount exceeds your balance, try again! \n"
                 "your current balance is " << Client.balance << endl;
            continue;
        }

        if (ActionConfirmation()) {
            Client.balance -= WithdrawAmount;
            cout << "Done successfully, Your current balance is " << Client.balance << endl;
            UpdateClientsFile(Database,Client.account, Client);
        }
        else {
            cout<<"Transaction canceled \n"<<endl;
        }
        break;
    }while (true);
}

void PerformQuickWithdrawMenu(enQuickWithdrawMenu Option) {
    switch (Option) {
        case 1: {
            if (HaveSufficientAmount(CurrentClient.balance, 20)) {
                if (ActionConfirmation()) {
                    WithDraw(20,CurrentClient);
                    cout << "Done successfully, Your current balance is " << CurrentClient.balance << endl;
                }
            }
            else {
                DeniedTransaction();
                QuickWithdrawMenu();
            }
            UpdateClientsFile(Database,CurrentClient.account, CurrentClient);
            break;
        }
        case 2: {
            if (HaveSufficientAmount(CurrentClient.balance, 50)) {
                if (ActionConfirmation()) {
                    WithDraw(50,CurrentClient);
                    cout << "Done successfully, Your current balance is " << CurrentClient.balance << endl;
                }
            }
            else {
                DeniedTransaction();
                QuickWithdrawMenu();
            }
            UpdateClientsFile(Database,CurrentClient.account, CurrentClient);
            break;
        }
            case 3: {
            if (HaveSufficientAmount(CurrentClient.balance, 100)) {
                if (ActionConfirmation()) {
                    WithDraw(100,CurrentClient);
                    cout << "Done successfully, Your current balance is " << CurrentClient.balance << endl;

                }
            }
            else {
                DeniedTransaction();
                QuickWithdrawMenu();
            }
            UpdateClientsFile(Database,CurrentClient.account, CurrentClient);
            break;
        }
            case 4: {
            if (HaveSufficientAmount(CurrentClient.balance, 200)) {
                if (ActionConfirmation()) {
                    WithDraw(200,CurrentClient);
                    cout << "Done successfully, Your current balance is " << CurrentClient.balance << endl;
                };
            }
            else {
                DeniedTransaction();
                QuickWithdrawMenu();
            }
            UpdateClientsFile(Database,CurrentClient.account, CurrentClient);
            break;
        }
        case 5: {
            if (HaveSufficientAmount(CurrentClient.balance, 400)) {
                if (ActionConfirmation()) {
                    WithDraw(400,CurrentClient);
                    cout << "Done successfully, Your current balance is " << CurrentClient.balance << endl;
                }
            }
            else {
                DeniedTransaction();
                QuickWithdrawMenu();
            }
            UpdateClientsFile(Database,CurrentClient.account, CurrentClient);
            break;
        }
            case 6: {
            if (HaveSufficientAmount(CurrentClient.balance, 600)) {
                    if (ActionConfirmation()) {
                        WithDraw(600,CurrentClient);
                        cout << "Done successfully, Your current balance is " << CurrentClient.balance << endl;

                    }
            }
            else {
                DeniedTransaction();
                QuickWithdrawMenu();
            }
            UpdateClientsFile(Database,CurrentClient.account, CurrentClient);
            break;
        }
            case 7: {
            if (HaveSufficientAmount(CurrentClient.balance, 800)) {
                if (ActionConfirmation()) {
                    WithDraw(800,CurrentClient);
                    cout << "Done successfully, Your current balance is " << CurrentClient.balance << endl;
                }
            }
            else {
                DeniedTransaction();
                QuickWithdrawMenu();
            }
            UpdateClientsFile(Database,CurrentClient.account, CurrentClient);
            break;
        }
            case 8: {
            if (HaveSufficientAmount(CurrentClient.balance, 1000)) {
                if (ActionConfirmation()) {
                    WithDraw(1000,CurrentClient);
                    cout << "Done successfully, Your current balance is " << CurrentClient.balance << endl;
                }
            }
            else {
                DeniedTransaction();
                QuickWithdrawMenu();
            }
            UpdateClientsFile(Database,CurrentClient.account, CurrentClient);
            break;
        }
            case 9: {
                MainMenuScreen();
                break;
        }
            default: {
                cout << "Please enter a valid option!" << endl;
                QuickWithdrawMenu();
        }
    }
}

void QuickWithdrawMenu() {
    cout << "========================================================" << endl;
    cout << "\t\t Quick Withdraw "<< endl;
    cout << "========================================================" << endl;
    cout << "\t\t[1] 20";
    cout << "\t\t\t\t[2] 50"<<endl;
    cout << "\t\t[3] 100";
    cout << "\t\t\t\t[4] 200"<<endl;
    cout << "\t\t[5] 400";
    cout << "\t\t\t\t[6] 600"<<endl;
    cout << "\t\t[7] 800";
    cout << "\t\t\t\t[8] 1000"<<endl;
    cout << "\t\t[9] Exit"<<endl;
    cout << "==========================================================" << endl;
    cout << "Your Balance is : " << GetClientBalance() << endl;

    PerformQuickWithdrawMenu((enQuickWithdrawMenu) ReadMenuOptions(9));

}

void PerformMainMenu(enATMMainMenu Option) {
    switch (Option) {
        case enQuickWithDraw: {
            ClearScreen();
            QuickWithdrawMenu();
            MainMenuScreen();
            break;
        }
        case enNormalWithDraw: {
            ClearScreen();
            NormalWithdraw(CurrentClient);
            MainMenuScreen();
            break;
        }
        case enDeposit: {
            ClearScreen();
            Deposit();
            MainMenuScreen();
            break;
        }
        case enCheckBalance: {
            ClearScreen();
            CheckBalance();
            MainMenuScreen();
            break;

        }
        case enLogout: {
            ClearScreen();
            LogIn();
            break;
        }
        default: {
            ClearScreen();
            cout << "Please enter a valid option!" << endl;
            MainMenuScreen();
            break;
        }
    }
}

void MainMenuScreen () {
    ClearScreen();
    cout << "=======================================================" << endl;
    cout << "\t\t ATM Main Menu Screen "<< endl;
    cout << "=======================================================" << endl;
    cout << "[1] Quick Withdraw "<<endl;
    cout << "[2] Normal Withdraw "<<endl;
    cout << "[3] Deposit "<<endl;
    cout << "[4] Check Balance "<<endl;
    cout << "[5] Logout "<<endl;
    cout << "=======================================================" << endl;
    PerformMainMenu((enATMMainMenu) ReadMenuOptions(5));
}


void LogIn() {
    string Account , Password;
    bool LogInFailed = false;
    do {
    LoginScreen();

    if (LogInFailed) {
        cout << "Username / password is not correct!" << endl;

    }
        cout << "Please enter your username: "<< endl;

        cin >> Account;

        cout << "Please enter your password: "<<endl;

        cin >> Password;

        LogInFailed = !LoadClient( Account, Password);
    }while (LogInFailed);
    CurrentClient = LoadClientInfo(Account);
    MainMenuScreen();

}

int main() {
    LogIn();
}