#include <iostream>
#include "clsLogScreen.h"
#include "clsUtil.h"
using namespace std;

int main() {
    char Exit = 'n';
    while (Exit == 'n') {
        if (clsLoginScreen::LoginScreen() == false ) {
            return 0;
        };
        cout << "Do you Want to Exit? y/n: " << endl;
        cin >> Exit;
        clsUtil::Capitalize(Exit);
        if (Exit == 'Y') {
            return 0;
        }
    }
}