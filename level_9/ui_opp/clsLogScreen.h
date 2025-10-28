#pragma once
#include <iomanip>
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"
using namespace std;

class clsLoginScreen : protected clsScreen {
    private:
    static void _Login() {
        bool LoginFailed = false;
        string UserName, Password;
        do {
            if (LoginFailed ) {
                cout << "\nIncorrect UserName / Password! " << endl;
            }
            cout << "Enter Username: ";
            cin >> UserName;

            cout << "Enter Password: ";
            cin >> Password;

            CurrentUser = clsUser::Find(UserName, Password);
            LoginFailed = CurrentUser.IsEmpty();
        }while(LoginFailed);
        clsMainScreen::ShowMainMenu();
    }
    public:
    static void LoginScreen() {
        _ScreenHeader("\t  Login Screen");
        _Login();
    }

};