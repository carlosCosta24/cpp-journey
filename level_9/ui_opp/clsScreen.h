#pragma once
#include <iostream>
using namespace std;


class clsScreen {
    protected:
        static void _ScreenHeader(string Header, string SubHeader = "") {
            cout << "\t\t\t\t\t\t\t\t\t ★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★\n";
            cout << "\t\t\t\t\t\t\t\t\t\t"<< Header ;
            if (SubHeader != "") {
                cout << "\n\t\t\t\t\t\t\t\t " << SubHeader;
            }
            cout << "\n\t\t\t\t\t\t\t\t\t ★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★彡★\n";
        }
};