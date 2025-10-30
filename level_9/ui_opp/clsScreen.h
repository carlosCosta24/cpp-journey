#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsDate.h"
#include "Global.h"
using namespace std;


class clsScreen {
    protected:
        static void _ScreenHeader(string Header, string SubHeader = "") {
            clsMyDate Date = clsMyDate();
            cout << "\t\t\t\t\t\t\t\t\t ★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★\n";
            cout << "\t\t\t\t\t\t\t\t\t\t"<< Header ;
            if (SubHeader != "") {
                cout << "\n\t\t\t\t\t\t\t\t " << SubHeader;
            }
            cout << "\n\t\t\t\t\t\t\t\t\t ★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★\n";
            cout << "\t\t\t\t\t\t\t\t\t User: " << CurrentUser.GetUserName() << endl;
            cout << "\t\t\t\t\t\t\t\t\t Date: " << Date.GetDay() << "/" << Date.GetMonth()
            << "/" << Date.GetYear() << endl;


        }
        static bool _AccessChecker(clsUser::enPermissions Permission) {
            if (!CurrentUser.IsAllowed(Permission)) {
                cout << "\t\t\t\t\t\t\t\t\t ★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★\n";
                cout << "\t\t\t\t\t\t\t\t\t\t\t You dont have access, "
                        "\n\t\t\t\t\t\t\t\t\t\t\t contact your system admin"<<endl;
                cout << "\t\t\t\t\t\t\t\t\t ★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★\n";
                return false;
            }else {
                return true;
            }

        }

};