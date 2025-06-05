#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

struct stClint {
    string AccountNumber;
    string Pin;
    string Name;
    string Phone;
    double Amount=0.0;
};

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable
    // use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }
    return vString;
}

stClint ConvertLinetoRecord(string Line, string Seperator ="/*/")
{
    stClint Client;
    vector<string> vClientData;
    vClientData = SplitString(Line, Seperator);
    Client.AccountNumber = vClientData[0];
    Client.Pin = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.Amount = stod(vClientData[4]);//cast string to double
    return Client;
}
vector <stClint> LoadCleintsDataFromFile(string FileName)
{
    vector <stClint> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode
    if (MyFile.is_open())
    {
        string Line;
        stClint Client;
        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}
void PrintClientRecord(stClint Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.Pin;
    cout << "| " << setw(15) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.Amount;
}
stClint Finder(vector<stClint> &vClients , string Account ) {
    for (stClint &Client : vClients) {
        if (Client.AccountNumber == Account) {
            return Client;
        }
    }
    return stClint{};
}
void TablePrinter(const string &Account) {
    cout <<"\t\t\t\t\t\t\t Client" << "(" << Account << ")" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "| " << setw(15) << left << "Account Number"
         << "| " << setw(10) << "Pin Code"
         << "| " << setw(15) << "Client Name"
         << "| " << setw(12) << "Phone"
         << "| " << setw(12) << "Balance" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
}
void SaveToFile(string FileName, const vector<stClint> &vClients) {
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    if (MyFile.is_open()) {
        for (const stClint &Client : vClients) {
            MyFile << Client.AccountNumber << "/*/"
       << Client.Pin << "/*/"
       << Client.Name << "/*/"
       << Client.Phone << "/*/"
       << Client.Amount << endl;
        }
        MyFile.close();
    }
}
stClint Filler() {
    stClint stNewClint;
    cout<< "Please enter account Data\n"<< endl;
    cin.ignore();

    cout<< "Enter Account Pin: ";
    getline(cin, stNewClint.Pin);

    cout<< "Enter Account Holder Name: ";
    getline(cin,stNewClint.Name) ;

    cout<< "Enter Account Holder Phone: ";
    getline(cin,stNewClint.Phone) ;

    cout<< "Enter Account Balance: ";
    cin >> stNewClint.Amount;

    return stNewClint;
}
void EditClintData(vector<stClint> &vClients, string Account) {
    for (stClint &Client : vClients) {
        if (Client.AccountNumber == Account) {
            Client.AccountNumber = Account;
             Client = Filler();
        }
    }
}

int main() {
    string Account;
    vector<stClint> vClients = LoadCleintsDataFromFile("bank.txt");

    cout << "Please enter AccountNumber?: ";
    cin>> Account;

    stClint SearchResult = Finder(vClients, Account);
    if(!SearchResult.AccountNumber.empty()) {
        char Edit;
        TablePrinter(Account);
        PrintClientRecord(SearchResult);
        cout << endl;
        cout << "Are you sure you want to edit this account? Y/n?";
        cin >> Edit;

        if(Edit == 'Y' || Edit == 'y') {
                EditClintData(vClients, Account);
                SaveToFile("bank.txt",vClients);
                cout<< "Clint account has been Updated!!";
        }else {

                cout << "Edit canceled by user !!";

        }
    }else {
        cout << "Account (" << Account << ") not found";
    }
    return 0;


}