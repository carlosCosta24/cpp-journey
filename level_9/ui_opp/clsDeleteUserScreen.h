#pragma once
#include "clsUser.h"
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsInputValidate.h"
#include <iostream>

class clsDeleteUserScreen : protected clsScreen {
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
    static void DeleteUserScreen() {
        _ScreenHeader("\t Delete User Screen");
        string UserName = "";
        cout << "\nPlease enter UserName :";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName)) {
            cout << "\nPlease enter UserName again: ";
            UserName = clsInputValidate::ReadString();
        }
        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);
        cout << "\n\nAre you sure you want to delete this User? y/n"<< endl;
        char Choice = 'n';
        cin >> Choice;
        Choice = tolower(Choice);
        if (Choice == 'y') {
            bool Deleted = User.Delete();
            if (Deleted){
                cout << "\nUser deleted successfully :-)" << endl;
                _PrintUser(User);

            }
        }else {cout << "\nUser not deleted :-("<< endl;
        }
    }

};