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

enum enQuickWithDrawMenu {
    enQuick_20 = 1,
    enQuick_50 = 2,
    enQuick_100 = 3,
    enQuick_200 = 4,
    enQuick_400 = 5,
    enQuick_600 = 6,
    enQuick_800 = 7,
    enQuick_1000 = 8,

};

const string Database = "bank.txt";
stClient CurrentClient;
void LogIn();
void PerformQuickWithdrawMenu();
char Capitalize(const char & Character) {
    return toupper(Character);
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

stClient GetClient(string Account) {
    stClient Target;
    vector <stClient> ClientsList = LoadClients(Database);
    for (stClient& Client : ClientsList) {
        if (Client.account == Account) {
            Target = Client;
        }
    }
    return Target;
}

void WithDraw(double WithdrawAmount, double Balance, stClient & Client) {
    double NewBalance = Balance - WithdrawAmount;
    Client.balance -= NewBalance;
}

void QuickWithdrawMenu(enQuickWithDrawMenu Option) {
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

    PerformQuickWithdrawMenu((enQuickWithDraw) ReadMenuOptions(9));

}

bool HaveSufficientAmount(double ClientBalance, double AmountOfWithDraw) {

    if (ClientBalance > AmountOfWithDraw) {
        return true;
    }else {
        return false;
    }
}

void DeniedTransaction() {
    cout << "You cant perform this transaction"<< endl;
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
    CurrentClient.balance += DepositAmount;

}

double ReadAmount() {
    double Amount;
    cout << "Please Enter Amount : ";
    cin >> Amount;

    return Amount;
}

bool ActionConfirmation() {
    char Answer;
    cout << "Are You sure you want to perform this transaction? y/n?" << endl;
    cin >> Answer;
    Answer = Capitalize(Answer);
    return (Answer == 'Y') ? true : false;
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
    stClient Client = LoadClientInfo(CurrentClient.account);
    cout << "Your Balance is: " << CurrentClient.balance << endl;
}

void NormalWithdraw() {
    stClient Client;
    short WithdrawAmount;
    do {
        cout << "Enter an amount multiple of 5's ? "<< endl;
        WithdrawAmount = ReadAmount();
    } while (WithdrawAmount % 5 != 0 );

    if (Client.balance < WithdrawAmount) {
        cout << "the amount exceeds your balance, make another choice, "
                "your current balance is " << Client.balance << endl;
        return;
    }
    char Answer;
    cout << "Are you sure you want to perform this transaction? Y/N? "<< endl;
    cin >> Answer;
    Answer = Capitalize(Answer);

    if (Answer == 'Y') {
        Client.balance -= WithdrawAmount;
        cout << "Done successfully, Your current balance is " << Client.balance << endl;
    }
}

void PerformMainMenu(enATMMainMenu Option) {
    switch (Option) {
        case enQuickWithDraw: {
            ClearScreen();
            QuickWithdrawMenu();
            break;
        }
        case enNormalWithDraw: {
            ClearScreen();
            NormalWithdraw();
            break;
        }
        case enDeposit: {
            ClearScreen();
            Deposit();
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
            LoginScreen();
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

void PerformQuickWithdrawMenu(short Option) {
    switch (Option) {
        case 1: {
            if (HaveSufficientAmount(CurrentClient.balance, 20)) {
                if (ActionConfirmation()) {
                    WithDraw(20, CurrentClient.balance,  CurrentClient);
                    cout << "Successful Withdraw"<< endl;
                }
            }
            else {
                DeniedTransaction();
            }
            break;
        }
        case 2: {
            if (HaveSufficientAmount(CurrentClient.balance, 50)) {
                ActionConfirmation();
                WithDraw(50, CurrentClient.balance,  CurrentClient);
                cout << "Successful Withdraw"<< endl;
            }
            else {
                DeniedTransaction();
            }
            break;
        }
            case 3: {
            if (HaveSufficientAmount(CurrentClient.balance, 100)) {
                ActionConfirmation();
                WithDraw(100, CurrentClient.balance,  CurrentClient);
                cout << "Successful Withdraw"<< endl;
            }
            else {
                DeniedTransaction();
            }
            break;
        }
            case 4: {
            if (HaveSufficientAmount(CurrentClient.balance, 200)) {
                ActionConfirmation();
                WithDraw(200, CurrentClient.balance,  CurrentClient);
                cout << "Successful Withdraw"<< endl;
            }
            else {
                DeniedTransaction();
            }
            break;
        }
        case 5: {
            if (HaveSufficientAmount(CurrentClient.balance, 400)) {
                ActionConfirmation();
                WithDraw(400, CurrentClient.balance,  CurrentClient);
                cout << "Successful Withdraw"<< endl;
            }
            else {
                DeniedTransaction();
            }
            break;
        }
            case 6: {
            if (HaveSufficientAmount(CurrentClient.balance, 600)) {
                    ActionConfirmation();
                    WithDraw(600, CurrentClient.balance,  CurrentClient);
                    cout << "Successful Withdraw"<< endl;
            }
            else {
                DeniedTransaction();
            }
            break;
        }
            case 7: {
            if (HaveSufficientAmount(CurrentClient.balance, 800)) {
                ActionConfirmation();
                WithDraw(800, CurrentClient.balance,  CurrentClient);
                cout << "Successful Withdraw"<< endl;
            }
            else {
                DeniedTransaction();
            }
            break;
        }
            case 8: {
            if (HaveSufficientAmount(CurrentClient.balance, 1000)) {
                ActionConfirmation();
                WithDraw(1000, CurrentClient.balance,  CurrentClient);
                cout << "Successful Withdraw"<< endl;
            }
            else {
                DeniedTransaction();
            }
            break;
        }
            case 9: {
                MainMenuScreen();
                break;
        }
            default: {
                cout << "Please enter a valid option!" << endl;
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
    CurrentClient = GetClient(Account);
    MainMenuScreen();

}

int main() {
    LogIn();
}