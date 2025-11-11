#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsUtil.h"
using namespace std;

class clsBankClient :public clsPerson {
private:
    enum enMode {EmptyMode = 0, UpdateMode = 1, AddNew = 2};
    enMode _Mode;
    string _Account;
    string _Password;
    float _Balance;
    bool _MarkedForDeletion = false;

    static clsBankClient _ConvertLineToClientObj(string Line, string Delimiter = "/*/") {
        vector <string> vClientData;
        vClientData = clsString::StringSplitter(Line, Delimiter);
        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], clsUtil::Decryption(vClientData[5]), stod(vClientData[6]));
    }
    static string _ConvertClientObjToLine(clsBankClient Client, string Delimiter = "/*/") {
        string stClientRecord = "";
        stClientRecord += Client.GetFirstName() + Delimiter;
        stClientRecord += Client.GetLastName() + Delimiter;
        stClientRecord += Client.GetEmail() + Delimiter;
        stClientRecord += Client.GetPhone() + Delimiter;
        stClientRecord += Client.AccountNumber() + Delimiter;
        stClientRecord += clsUtil::Encryption(Client.GetPassword()) + Delimiter;
        stClientRecord += to_string(Client.GetBalance()) ;

        return stClientRecord;
    }
    static clsBankClient _GetEmptyClientObj() {
        return clsBankClient(enMode::EmptyMode,"","","","","","",0);
    }
    string _GetTransferLogs(string UserNamw,clsBankClient Destination,
    float Amount, string Dellimter = "/*/") {
        string Line;
        clsMyDate Date;
        Line = to_string(Date.GetDay()) + "/";
        Line += to_string(Date.GetMonth()) + "/";
        Line += to_string(Date.GetYear()) ;
        Line += " - " + to_string(Date.GetHour()) + ":"
        + to_string(Date.GetMinute()) + ":"
        + to_string(Date.GetSecond()) + Dellimter;
        Line +=  AccountNumber() + Dellimter;
        Line += Destination.AccountNumber() + Dellimter;
        Line += to_string(Amount) + Dellimter;
        Line += to_string(GetBalance()) + Dellimter;
        Line += to_string(Destination.GetBalance()) + Dellimter;
        Line += UserNamw;
        return Line;
    }
     void _SaveTransferInfo(string UserName, clsBankClient Destination, float Amount) {
        fstream file;
        string Log = _GetTransferLogs(UserName, Destination, Amount);
        file.open("Transfers.txt", ios::out | ios::app);
        if (file.is_open()) {
            file << Log << endl;
            file.close();
        }
    }
    static vector <clsBankClient> _LoadClientsData() {
        vector <clsBankClient> _vClients;
        fstream file;
        file.open("Clients.txt", ios::in);

        if (file.is_open()) {
            string Line;
            while (getline(file, Line)) {
                clsBankClient Client = _ConvertLineToClientObj(Line, "/*/");
                _vClients.push_back(Client);
            }
        }
        file.close();
        return _vClients;

    }
    static void _SaveClientsData(vector<clsBankClient> vClients) {
        fstream file;
        file.open("Clients.txt", ios::out);
        string DataLine;
        if (file.is_open()) {
            for (clsBankClient Client : vClients) {
                if (!Client._MarkedForDeletion) {
                    DataLine = _ConvertClientObjToLine(Client, "/*/");
                    file << DataLine << endl;
                }
            }
            file.close();
        }
    }
    static void _AddDataLineToFile(string stDataLine) {
        fstream file;
        file.open("Clients.txt", ios::out | ios::app);
        if (file.is_open()) {
            file << stDataLine << endl;
            file.close();
        }
    }
    void _Update() {
        vector <clsBankClient> _vClients = _LoadClientsData();
        for (clsBankClient & Client : _vClients) {
            if (Client.AccountNumber() == AccountNumber()) {
                Client = *this;
                break;
            }
        }
        _SaveClientsData(_vClients);

    }
    void _AddNewClient() {
        _AddDataLineToFile(_ConvertClientObjToLine(*this));
    }
public:
    clsBankClient(enMode Mode, string FirstName, string LastName, string Email,
        string Phone,string AccountNumber, string Password,float Balance)
    :clsPerson(FirstName,LastName,Email,Phone) {
        _Mode = Mode;
        _Account = AccountNumber;
        _Password = Password;
        _Balance = Balance;
    }
    struct stTransferLog {
        string Date;
        string DestinationAccount;
        string SourceAccount;
        float Amount;
        float DestinationBalance;
        float SourceBalance;
        string UserName;
    };
    bool IsEmpty() {
        return (_Mode == enMode::EmptyMode);
    }
    string AccountNumber() {
        return _Account;
    }
    void SetPassword(string NewPassword) {
        _Password = NewPassword;
    }
    string GetPassword() {
        return _Password;
    }
    void setBalance(float Balance) {
        _Balance = Balance;
    }
    float GetBalance() {
        return _Balance;
    }

    static clsBankClient Find (string Account) {
        fstream file;
        file.open("Clients.txt", ios::in);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                clsBankClient Client = _ConvertLineToClientObj(line);
                if (Client.AccountNumber() == Account) {
                    file.close();
                    return Client;
                }
            }
            file.close();
        }
        return _GetEmptyClientObj();
    }
    static clsBankClient Find (string Account, string Password) {
        fstream file;
        file.open("Clients.txt", ios::in);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                clsBankClient Client = _ConvertLineToClientObj(line);
                if (Client.AccountNumber() == Account && Client._Password == Password) {
                    file.close();
                    return Client;
                }
            }
            file.close();
        }
        return _GetEmptyClientObj();
    }
    enum enSaveResult {svFailed = 0, svSaved = 1, svAccountExist = 2};
    enSaveResult Save() {
        switch (_Mode) {
        case enMode::EmptyMode:
        {
            return enSaveResult::svFailed;
        }
        case enMode::UpdateMode: {
            _Update();
            return enSaveResult::svSaved;
        }
        case enMode::AddNew: {
            if (clsBankClient::IsClientExist(_Account)) {
                return enSaveResult::svAccountExist;

            }else {
                _AddNewClient();
                _Mode = enMode::UpdateMode;
                return enSaveResult::svSaved;
            }
        }
        }

    }
    static bool IsClientExist(string Account) {
        clsBankClient Client = Find(Account);
        return (!Client.IsEmpty());
    }

    static clsBankClient AddNewClientObj(string AccountNumber) {
        return clsBankClient(enMode::AddNew,"","","","",AccountNumber,"", 0);
    }

    bool Delete() {
        vector <clsBankClient> vClients = _LoadClientsData();
        for (clsBankClient &Client : vClients) {
            if (Client.AccountNumber() == _Account) {
                Client._MarkedForDeletion = true;
                break;
            }
        }
            _SaveClientsData(vClients);
            *this = _GetEmptyClientObj();
            return true;
    }

    static vector<clsBankClient> GetClientsList() {
        return _LoadClientsData();
    }

    void Deposit(double Amount) {
        _Balance += Amount;
        Save();
    }

    bool Withdraw(double Amount) {
        if (Amount > _Balance) {
            return false;
        }
        _Balance -= Amount;
        Save();
        return true;

    }
    static stTransferLog _ConvertTransferLogsLineToRecord(string Line) {
        stTransferLog Record;
        vector <string> vRecordLine = clsString::StringSplitter(Line,"/*/");
        Record.Date = vRecordLine[0];
        Record.SourceAccount = vRecordLine[1];
        Record.DestinationAccount = vRecordLine[2];
        Record.Amount = stod(vRecordLine[3]);
        Record.SourceBalance = stod(vRecordLine[4]);
        Record.DestinationBalance = stod(vRecordLine[5]);
        Record.UserName = vRecordLine[6];
        return Record;
    }
    static vector<stTransferLog> GetTransferList() {
        vector <stTransferLog> vRecords;
        fstream file;
        file.open("Transfers.txt", ios::in);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                stTransferLog Record;
                Record = _ConvertTransferLogsLineToRecord(line);
                vRecords.push_back(Record);
            }
            file.close();
        }
        return vRecords;

    }

    static double GetTotalBalances(vector<clsBankClient> vClientsList) {
        double TotalBalance = 0;
        for (clsBankClient Client : vClientsList) {
            TotalBalance += Client.GetBalance();
        }
        return TotalBalance;
    }
    bool Transfer(float Amount, clsBankClient & DestinationAccount, string UserName) {
        if (Amount > _Balance) {
            return false;
        }
        Withdraw(Amount);
        DestinationAccount.Deposit(Amount);
        _SaveTransferInfo(UserName, DestinationAccount,Amount);

        return true;
    }

};