#pragma once
#include "clsPerson.h"
#include "clsString.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
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
    void _Update() {
        vector <clsUser> _vUsers = _LoadUsersData();
        for (clsUser& User : _vUsers) {
            if (User.GetUserName() == GetFirstName()) {
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
        _SaveClientsData(vClients);
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
    static clsUser GetAddNewUserObj(string Username) {
        return clsUser(enMode::enAdd, "", "", "", "", Username,"", 0);
    }
    static vector<clsUser> GetUsersList() {
        return _LoadUsersData();
    }


};