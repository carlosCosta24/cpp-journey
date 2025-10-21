#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
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
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }
    static string _ConvertClientObjToLine(clsBankClient Client, string Delimiter = "/*/") {
        string stClientRecord = "";
        stClientRecord += Client.GetFirstName() + Delimiter;
        stClientRecord += Client.GetLastName() + Delimiter;
        stClientRecord += Client.GetEmail() + Delimiter;
        stClientRecord += Client.GetPhone() + Delimiter;
        stClientRecord += Client.AccountNumber() + Delimiter;
        stClientRecord += Client.GetPassword() + Delimiter;
        stClientRecord += to_string(Client.GetBalance()) ;

        return stClientRecord;
    }
    static clsBankClient _GetEmptyClientObj() {
        return clsBankClient(enMode::EmptyMode,"","","","","","",0);
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
    static void _SaveClientsData(vector<clsBankClient> vclients) {
        fstream file;
        file.open("Clients.txt", ios::out);
        string DataLine;
        if (file.is_open()) {
            for (clsBankClient Client : vclients) {
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

    void Print() {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << GetFirstName();
        cout << "\nLastName    : " << GetLastName();
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << GetEmail();
        cout << "\nPhone       : " << GetPhone();
        cout << "\nAcc. Number : " << _Account;
        cout << "\nPassword    : " << _Password;
        cout << "\nBalance     : " << _Balance;
        cout << "\n___________________\n";
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
            break;
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
        vector <clsBankClient> vClients;
        vClients = _LoadClientsData();
        for (clsBankClient Client : vClients) {
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

};