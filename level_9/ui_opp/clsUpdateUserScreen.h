#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
using namespace std;

class clsUpdateUserScreen : protected clsScreen {
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
    static char _Capitalize(const char & Character) {
        return toupper(Character);
    }
    static int _ReadUserPermissions() {
        int Permissions = 0;
        char Answer = 'N';
        cout << "Do you want to give user a full access? y/n? ";
        cin >> Answer;
        clsUtil::Capitalize(Answer);
        if (Answer == 'Y') {return -1;
        }
        cout << "\nDo you want to give access to : \n";
        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        clsUtil::Capitalize(Answer);
        if (Answer == 'Y') {Permissions += clsUser::enPermissions::pListClients;
        }
        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        clsUtil::Capitalize(Answer);
        if (Answer == 'Y') {Permissions += clsUser::enPermissions::pAddNewClient;
        }
        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        clsUtil::Capitalize(Answer);
        if (Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }
        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        clsUtil::Capitalize(Answer);
        if (Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClient;
        }
        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        clsUtil::Capitalize(Answer);
        if (Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }
        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        clsUtil::Capitalize(Answer);
        if (Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTransactions;
        }
        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        clsUtil::Capitalize(Answer);
        if (Answer == 'Y' )
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }
        return Permissions;

    }
public:
static void UpdateUserScreen() {
    _ScreenHeader("\t  Update User Screen");
    string UserName = "";

    cout << "\nPlease enter UserName number:";
    UserName = clsInputValidate::ReadString();
    while (!clsUser::IsUserExist(UserName)) {
        cout << "\nPlease enter UserName again: ";
        UserName = clsInputValidate::ReadString();
    }
    clsUser User = clsUser::Find(UserName);
    _PrintUserInfo(User);
    cout << "\n\nAre you sure you want to update this User? y/n"<< endl;
    char Choice = 'n';
    cin >> Choice;
    Choice = tolower(Choice);
    if (Choice == 'y') {
        cout << "\n\nUpdate User Info";
        cout << "\n---------------------\n";
        _ReadUserInfo(User);
        clsUser::enSaveResult SaveResult = User.Save();

        switch (SaveResult) {
            case clsUser::enSaveResult::svSaved: {
                cout << "\n\nUpdated Successfully ";
                _PrintUserInfo(User);
                break;
            }
            case clsUser::enSaveResult::svFailed: {
                cout << "\n\nUpdated Failed ";
                break;
            }
        }
    }else {
        cout << "\n\nUpdate Failed "<<endl;
    }

}
};

