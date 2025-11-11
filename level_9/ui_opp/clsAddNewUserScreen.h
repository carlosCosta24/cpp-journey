#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include <iostream>
#include <iomanip>
#include "clsUtil.h"
using namespace std;

class clsAddNewUserScreen : protected clsScreen {
    private:
    static void _ReadUserInfo(clsUser& User) {
        cout << "\nEnter User FirstName:";
        User.SetFirstName(clsInputValidate::ReadString());

        cout << "\nEnter User LastName:";
        User.SetLastName(clsInputValidate::ReadString());

        cout << "\nEnter User Email:";
        User.SetEmail(clsInputValidate::ReadString());

        cout << "\nEnter User PhoneNumber:";
        User.SetPhone(clsInputValidate::ReadString());

        cout << "\nEnter User Password:";
        User.SetPassword(clsInputValidate::ReadString());

        cout << "\nEnter User Permissions:"<<endl;
        User.SetPermissions(_ReadUserPermissions());
        cout << User.GetPermissions();
    }
    static void _PrintUserInfo(clsUser User) {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nUser Name   : " << User.GetUserName();
        cout << "\nFirstName   : " << User.GetFirstName();
        cout << "\nLastName    : " << User.GetLastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.GetEmail();
        cout << "\nPhone       : " << User.GetPhone();
        cout << "\nPassword    : " << User.GetPassword();
        cout << "\nPermissions : " << User.GetPermissions();
        cout << "\n___________________\n";
    }
    static int _ReadUserPermissions() {
        int Permissions = 0;
        char Answer = 'N';
        cout << "Do you want to give user a full access? y/n? ";
        cin >> Answer;
        clsUtil::Capitalize(Answer);
        if (Answer == 'Y') {
            return -1;
        }
        cout << "\nDo you want to give access to : \n";
        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        clsUtil::Capitalize(Answer);
        if (Answer == 'Y') {
            Permissions += clsUser::enPermissions::pListClients;
            cout << "DEBUG: Added pListClients (" << clsUser::enPermissions::pListClients
     << "), Total: " << Permissions << endl;

        }
        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        clsUtil::Capitalize(Answer);
        if (Answer == 'Y') {
            Permissions += clsUser::enPermissions::pAddNewClient;
            cout << "DEBUG: Added pListClients (" << clsUser::enPermissions::pAddNewClient
     << "), Total: " << Permissions << endl;

        }
        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        clsUtil::Capitalize(Answer);
        if (Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
            cout << "DEBUG: Added pListClients (" << clsUser::enPermissions::pDeleteClient
     << "), Total: " << Permissions << endl;

        }
        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        clsUtil::Capitalize(Answer);
        if (Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClient;
            cout << "DEBUG: Added pListClients (" << clsUser::enPermissions::pUpdateClient
     << "), Total: " << Permissions << endl;
        }
        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        clsUtil::Capitalize(Answer);
        if (Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
            cout << "DEBUG: Added pListClients (" << clsUser::enPermissions::pFindClient
     << "), Total: " << Permissions << endl;

        }
        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        clsUtil::Capitalize(Answer);
        if (Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTransactions;
            cout << "DEBUG: Added pListClients (" << clsUser::enPermissions::pTransactions
     << "), Total: " << Permissions << endl;

        }
        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        clsUtil::Capitalize(Answer);
        if (Answer == 'Y' )
        {
            Permissions += clsUser::enPermissions::pManageUsers;
            cout << "DEBUG: Added pListClients (" << clsUser::enPermissions::pManageUsers
     << "), Total: " << Permissions << endl;

        }
        cout<< "\nShow Logs? y/n? ";
        cin >> Answer;
        clsUtil::Capitalize(Answer);
        if (Answer == 'Y') {
            Permissions += clsUser::enPermissions::pLogs;
            cout << "DEBUG: Added pListClients (" << clsUser::enPermissions::pLogs
     << "), Total: " << Permissions << endl;

        }
        return Permissions;
    }
public:
    static void AddNewUserScreen() {

        _ScreenHeader("\t  Add New User Screen");
        string UserName = "";
        cout << "\nEnter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (clsUser::IsUserExist(UserName)) {
            cout << "\nUserName already exist, Try again: ";
            UserName = clsInputValidate::ReadString();
        }
        clsUser NewUser = clsUser::GetAddNewUserObj(UserName);

        _ReadUserInfo(NewUser);
        clsUser::enSaveResult SaveResult = NewUser.Save();

        switch (SaveResult) {
            case clsUser::enSaveResult::svSaved: {
                cout << "\nSaved Successfully :-)";
                _PrintUserInfo(NewUser);
                break;
            }
            case clsUser::enSaveResult::svFailed: {
                cout << "\nSaved Failed!, object is empty!";
                break;
            }
            case clsUser::enSaveResult::svAccountExist:{
                cout << "\nUserName already in use, Try again later.";
                break;
            }
        }

    }
};