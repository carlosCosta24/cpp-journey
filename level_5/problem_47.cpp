#include <iostream>
#include <string>
#include <fstream>
#include <limits>
using namespace std;
void ClearScreen() {
    system("clear"); // Simple and effective for Linux
    cout.flush();    // Ensure all output is flushed
}

void  ClearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

struct stClint {
    string AccountNumber;
    string Pin;
    string Name;
    string Phone;
    double Amount;
};

stClint Filler() {
    stClint stNewClint;
    cout<< "Please enter account Data\n"<< endl;
    cout<< "Enter Account Number: ";
    getline(cin>> ws, stNewClint.AccountNumber) ;

    cout<< "Enter Account Pin: ";
    getline(cin, stNewClint.Pin);

    cout<< "Enter Account Holder Name: ";
    getline(cin,stNewClint.Name) ;

    cout<< "Enter Account Holder Phone: ";
    getline(cin,stNewClint.Phone) ;

    cout<< "Enter Account Balance: ";
    cin >> stNewClint.Amount;

    ClearInputBuffer();
    return stNewClint;
}

string AccountRecord(stClint stClint, string Sep) {
    string AccountRecord="";

    AccountRecord+= stClint.AccountNumber + Sep;
    AccountRecord+= stClint.Pin + Sep;
    AccountRecord+= stClint.Name + Sep;
    AccountRecord+= stClint.Phone + Sep;
    AccountRecord+= to_string(stClint.Amount);

    return AccountRecord;
}

void SaveToFile(string Record, string FileName) {
    fstream file(FileName, ios::out|ios::app);

    if (file.is_open()) {
    file << Record << "\n";
    file.close();
    }else {
        cerr << "File could not be opened." << endl;
    }
}

void AddClint() {
    string AddMore = "Yes";

    do {
        ClearScreen();
        stClint stNewClint=  Filler();
        string NewClint = AccountRecord(stNewClint, "/*/");
        SaveToFile(NewClint, "bank.txt");
        ClearScreen();
        cout << "Clint added successfully, Do You Want TO Add More Clint (Yes/No) ? " << endl;
        cin >> AddMore;
    } while (AddMore == "Yes" || AddMore == "yes");

}

int main() {
    AddClint();
    return 0;
}


