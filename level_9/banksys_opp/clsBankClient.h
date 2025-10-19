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
    enum enMode {EmptyMode = 0, UpdateMode = 1};
    enMode _Mode;
    string _Account;
    string _Password;
    float _Balance;

    static clsBankClient _ConvertLineToClientObj(string Line, string Delimiter = "/*/") {
        vector <string> vClientData;
        vClientData = clsString::StringSplitter(Line, Delimiter);
        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }
    static clsBankClient _GetEmptyClientObj() {
        return clsBankClient(enMode::EmptyMode,"","","","","","",0);
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
    float getBalance() {
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
    static bool IsClientExist(string Account) {
        clsBankClient Client = Find(Account);
        return (!Client.IsEmpty());
    }

};