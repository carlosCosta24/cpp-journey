#include <iostream>
#include "clsLogScreen.h"
#include "clsUtil.h"
using namespace std;

int main() {
    char Exit = 'n';
    while (Exit == 'n') {
        clsLoginScreen::LoginScreen();
        cout << "Do you Want to Exit? y/n: " << endl;
        cin >> Exit;
        clsUtil::Capitalize(Exit);
        if (Exit == 'Y') {
            return 0;
        }
    }
}