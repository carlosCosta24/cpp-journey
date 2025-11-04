#pragma once
#include "clsPerson.h"
#include "clsString.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsDate.h"
using namespace std;

class clsUser : public clsPerson {
private:
    enum enMode {enEmpty = 0, enUpdate = 1, enAdd = 2};
    enMode _Mode ;
    string _UserName;
    string _Password;
    int _Permissions;
    bool _MarkForDelete = false;
    static clsUser _ConvertLineToUserObj(string Line, string Delimiter = "/*/") {
        vector <string> vUserData = clsString::StringSplitter(Line, Delimiter);
        return clsUser(enMode::enUpdate, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4], vUserData[5], stod(vUserData[6]));
    }
    static string _ConvertUserObjToLine(clsUser User, string Delimiter = "/*/") {
        string sUserRecord = "";
        sUserRecord += User.GetFirstName() + Delimiter;
        sUserRecord += User.GetLastName() + Delimiter;
        sUserRecord += User.GetEmail() + Delimiter;
        sUserRecord += User.GetPhone() + Delimiter;
        sUserRecord += User.GetUserName() + Delimiter;
        sUserRecord += User.GetPassword() + Delimiter;
        sUserRecord += to_string(User.GetPermissions()) ;

        return sUserRecord;
    }
    static string _GetLogInLine(clsUser User, string Dellimter = "/*/") {
        string LogInLine = "";
        clsMyDate Date;
        LogInLine = to_string(Date.GetDay()) + "/";
        LogInLine += to_string(Date.GetMonth()) + "/";
        LogInLine += to_string(Date.GetYear()) ;
        LogInLine += " - " + to_string(Date.GetHour()) + ":"
        + to_string(Date.GetMinute()) + ":"
        + to_string(Date.GetSecond()) + Dellimter;
        LogInLine += User.GetUserName() + Dellimter;
        LogInLine += User.GetPassword() + Dellimter;
        LogInLine += to_string(User.GetPermissions());
        return LogInLine;
    }
    static vector <clsUser> _LoadUsersData() {
        vector <clsUser> _vUsers;
        fstream file;
        file.open("Users.txt", ios::in);

        if (file.is_open()) {
            string Line;
            while (getline(file, Line)) {
                clsUser User = _ConvertLineToUserObj(Line, "/*/");
                _vUsers.push_back(User);
            }
        }
        file.close();
        return _vUsers;
    }
    static void _SaveUsersData(vector<clsUser> vUsers) {
        fstream file;
        file.open("Users.txt", ios::out);
        string DataLine;
        if (file.is_open()) {
            for (clsUser User : vUsers) {
                if (!User._MarkForDelete) {
                    DataLine = _ConvertUserObjToLine(User, "/*/");
                    file << DataLine << endl;
                }
            }
            file.close();
        }
    }
    static void SaveLogInfo(string Logs) {
        fstream file;
        file.open("Logs.txt", ios::out | ios::app);
        if (file.is_open()) {
            file << Logs << endl;
            file.close();
        }
    }
    void _Update() {
        vector <clsUser> _vUsers = _LoadUsersData();
        for (clsUser& User : _vUsers) {
            if (User.GetUserName() == GetUserName()) {
                User = *this;
                break;
            }
        }
        _SaveUsersData(_vUsers);
    }
    void _AddNewUser() {
        _AddDataLineToFile(_ConvertUserObjToLine(*this));
    }
    static void _AddDataLineToFile(string stDataLine) {
        fstream file;
        file.open("Users.txt", ios::out | ios::app);
        if (file.is_open()) {
            file << stDataLine << endl;
            file.close();
        }
    }
    static clsUser _GetEmptyUserObj() {
        return clsUser(enMode::enEmpty,"","","","","","",0);
    }

public:
    enum enPermissions {
        pAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClient = 8,
        pFindClient = 16, pTransactions = 32, pManageUsers = 64, pLogs = 128
    };
    struct stUsersLogs {
        string Date;
        string Name;
        string Password;
        int Permissions;
    };
    clsUser(enMode Mode, string FirstName, string LastName,string Email
        , string Phone, string UserName, string Password, int Permissions ) :
    clsPerson(FirstName, LastName, Email, Phone) {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;

    }
    enum enSaveResult {svFailed = 0, svSaved = 1, svAccountExist = 2};

    bool IsEmpty() {
        return (_Mode == enMode::enEmpty);
    }
    bool MarkForDelete() {
        return _MarkForDelete ;
    }
    string GetUserName() {
        return _UserName;
    }
    void SetUserName(string Name) {
        _UserName = Name;
    }
    string GetPassword() {
        return _Password;
    }
    void SetPassword(string NewPassword) {
        _Password = NewPassword;
    }
    int GetPermissions() {
        return _Permissions;
    }
    void SetPermissions(int Permissions) {
        _Permissions = Permissions;
    }
    static clsUser Find(string UserName) {
        fstream file;
        file.open("Users.txt", ios::in);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                clsUser User = _ConvertLineToUserObj(line);
                if (User.GetUserName() == UserName) {
                    file.close();
                    return User;
                }
            }
            file.close();
        }
        return _GetEmptyUserObj();
    }
    static clsUser Find (string UserName, string Password) {
        fstream file;
        file.open("Users.txt", ios::in);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                clsUser User = _ConvertLineToUserObj(line);
                if (User.GetUserName() == UserName && User._Password == Password) {
                    file.close();
                    return User;
                }
            }
            file.close();
        }
        return _GetEmptyUserObj();
    }
    bool Delete() {
        vector <clsUser> vUsers = _LoadUsersData();
        for (clsUser &User : vUsers) {
            if (User.GetUserName() == _UserName) {
                User._MarkForDelete = true;
                break;
            }
        }
        _SaveUsersData(vUsers);
        *this = _GetEmptyUserObj();
        return true;
    }
    enSaveResult Save() {
        switch (_Mode) {
            case enMode::enEmpty:
            {
                return enSaveResult::svFailed;
            }
            case enMode::enUpdate: {
                _Update();
                return enSaveResult::svSaved;
            }
            case enMode::enAdd: {
                if (clsUser::IsUserExist(_UserName)) {
                    return enSaveResult::svAccountExist;

                }else {
                    _AddNewUser();
                    _Mode = enMode::enUpdate;
                    return enSaveResult::svSaved;
                }
            }
        }

    }
    static bool IsUserExist(string UserName) {
        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }
    static clsUser GetAddNewUserObj(string Username) {
        return clsUser(enMode::enAdd, "", "", "", "", Username,"", 0);
    }
    static vector<clsUser> GetUsersList() {
        return _LoadUsersData();
    }
    bool IsAllowed(enPermissions Permission) {
        if (this->GetPermissions() == enPermissions::pAll) return true;
        if ((Permission & this->GetPermissions()) == Permission) return true;
        return false;

    }
    static void SaveToLog(string UserName) {
        clsMyDate Date;
        clsUser User = clsUser::Find(UserName);
        string Line = _GetLogInLine(User);
        SaveLogInfo(Line);
    }
    static stUsersLogs _ConvertLogsLineToRecord(string Line) {
        stUsersLogs Record;
        vector <string> vRecordLine = clsString::StringSplitter(Line,"/*/");
        Record.Date = vRecordLine[0];
        Record.Name = vRecordLine[1];
        Record.Password = vRecordLine[2];
        Record.Permissions = stod(vRecordLine[3]);
        return Record;
    }
    static vector <stUsersLogs> GetLogsList() {
        vector <stUsersLogs> vUsersLogList;
        fstream file;
        file.open("Logs.txt", ios::in);
        if (file.is_open()) {
            string Line;
            stUsersLogs LogRecord;
            while (getline(file, Line)) {
                LogRecord = _ConvertLogsLineToRecord(Line);
                vUsersLogList.push_back(LogRecord);
            }
        }
        file.close();
        return vUsersLogList;
    }


};