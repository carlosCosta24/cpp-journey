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

const string Database = "bank.txt";
stClient CurrentClient;
void LogIn();

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

bool LoadClient(string Username, string Password) {
    if (CheckClientAndPassword(Database, Username, Password)) {
        return true;
    }else {
        return false;
    }

}

void LoginScreen () {
    cout << "--------------------------------------------"<< endl;
    cout << "\t\t\t ATM Login Screen "<< endl;
    cout << "--------------------------------------------"<< endl;
}

int ReadMenuOptions() {
    int Option;
    cout << "Choose what do you want to do? [1 - 5]?"<< endl;
    cin >> Option;

    return Option;
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
    ReadMenuOptions();
}

void NormalWithdrawMenu() {
    cout << "========================================================" << endl;
    cout << "\t\t Normal Withdraw "<< endl;
    cout << "========================================================" << endl;
}

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

char Capitalize(const char & Character) {
    return toupper(Character);
}

void NormalWithdraw() {
    stClient Client;
    double WithdrawAmount;
    do {
        cout << "Enter an amount multiple of 5's ? "<< endl;
        WithdrawAmount = ReadAmount();
    } while (WithdrawAmount / 5.0 != 0 );

    if (Client.balance >= WithdrawAmount) {
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
    PerformMainMenu((enATMMainMenu) ReadMenuOptions());
}

void LogIn() {
    string ClientName , Password;
    bool LogInFailed = false;
    do {
    LoginScreen();

    if (LogInFailed) {
        cout << "Username / password is not correct!" << endl;

    }
        cout << "Please enter your username: "<< endl;

        cin >> ClientName;

        cout << "Please enter your password: "<<endl;

        cin >> Password;

        LogInFailed = !LoadClient( ClientName, Password);
    }while (LogInFailed);

    MainMenuScreen();

}

int main() {
    LogIn();
}