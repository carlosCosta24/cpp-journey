#include "clsUser.h"
#include <iostream>
using namespace std;

int main() {

cout << "=== Testing User Functions =====" << endl;
clsUser NewUser = clsUser::GetAddNewUserObj("alice");
    NewUser.SetFirstName("Jon");
    NewUser.SetLastName("Bob");
    NewUser.SetEmail("Jon@bob");
    NewUser.SetPhone("123456789");
    NewUser.SetPassword("1234");
    NewUser.SetPermissions(7);

    clsUser::enSaveResult Result = NewUser.Save();
    if (Result == clsUser::svSaved) {
        cout << "Saved!" << endl;
    }else if (Result == clsUser::enSaveResult::svFailed) {
        cout << "Save failed!" << endl;
    }else {
        cout << "User already exist"<<endl;
    }
    cout << "\n=== TEST 3: Update existing user ===" << endl;
    NewUser.SetPhone("987654321");
    NewUser.Save();
    cout << "User updated successfully.\n";

    cout << "\n=== TEST 4: Delete user ===" << endl;
    if (NewUser.Delete())
        cout << " User deleted successfully.\n";
    else
        cout << "Delete failed.\n";

    cout << "\n=== TEST 5: Verify deletion ===" << endl;
    clsUser Deleted = clsUser::Find("JohnDoe");
    if (Deleted.IsEmpty())
        cout << " User no longer exists.\n";
    else
        cout << "User still found.\n";

    return 0;
}

