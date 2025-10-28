#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include <iostream>
using namespace std;

class clsListUsersScreen : protected clsScreen {
private:
    static void _PrintUsersList(clsUser User) {
        cout << "| " << left << setw(15) << User.GetUserName();
        cout << "| " << left << setw(20) << User.FullName();
        cout << "| " << left << setw(12) << User.GetPhone();
        cout << "| " << left << setw(28) << User.GetEmail();
        cout << "| " << left << setw(12) << User.GetPermissions();
    }
    public:
    static void ListUsersScreen() {
        vector <clsUser> vUsers = clsUser::GetUsersList();
        string Title = "\t Users List Screen";
        string SubTitle = "\t\t (" + to_string(vUsers.size()) + ") Users(s).";

        _ScreenHeader(Title, SubTitle);
        cout << "\n-------------------------------------------------------------------------------"
                "---------------------------\n";
        cout << "| " << left << setw(15) << "User Name";
        cout << "| " << left << setw(20) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(28) << "Email";
        cout << "| " << left << setw(12) << "Permissions";
        cout << "\n-------------------------------------------------------------------------------------"
                "---------------------\n";
        if (vUsers.size() == 0) {
            cout << "\n\t\t\t\t\t\t\t\t\tNo User data not available" << endl;
        }
        else {
            for (clsUser User : vUsers) {
                _PrintUsersList(User);
                cout << endl;
            }
        }
        cout << "\n----------------------------------------------------------------------------------"
                "------------------------\n";
    }
};
