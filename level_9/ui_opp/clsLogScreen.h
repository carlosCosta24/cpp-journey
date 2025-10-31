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
    static bool _Login() {
        bool LoginFailed = false;
        string UserName, Password;
        short Trails = 3;
        do {
            if (LoginFailed && Trails <= 1) {
                cout << "Your have been locked out of the system \n"
                        "due to too many login attempts,\n"
                        "contact the bank" << endl;
                return false;
            }
            if (LoginFailed ) {
                Trails -= 1;
                cout << "\nIncorrect UserName / Password! " << endl;
                cout << "\nYour Have (" << Trails << ") Trail(s) left" << endl;
            }
            cout << "Enter Username: ";
            cin >> UserName;

            cout << "Enter Password: ";
            cin >> Password;

            CurrentUser = clsUser::Find(UserName, Password);
            LoginFailed = CurrentUser.IsEmpty();
        }while(LoginFailed);
        CurrentUser.SaveToLog(CurrentUser.GetUserName());
        clsMainScreen::ShowMainMenu();
        return true;
    }
    public:
    static bool LoginScreen() {
        _ScreenHeader("\t  Login Screen");
        return _Login();
    }

};