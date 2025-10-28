#pragma once
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsScreen.h"
#include <iostream>
#include "clsPerson.h"

using namespace std;

class clsFindUserScreen : protected clsScreen {
private:
    static void _PrintUser(clsUser User) {
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
public:
    static void FindUserScreen() {
        _ScreenHeader("\t Find User Screen ");
        string UserName = "";
        cout << "\nEnter UserName:";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName)) {
            cout << "\nUserName doesn't exist, Try again:";
            UserName = clsInputValidate::ReadString();
        }
        clsUser NewUser = clsUser::Find(UserName);

        if (!NewUser.IsEmpty()){
            cout << "Useer Data was found :-)"<<endl;
        }else {
            cout << "User Data was not foud :-("<< endl;

        }
        _PrintUser(NewUser);
    }
};
