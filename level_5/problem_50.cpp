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
bool DeleteRecord(vector<stClint> &vClients , string Account ) {
    for (auto it = vClients.begin(); it != vClients.end(); ++it) {
        if (it->AccountNumber == Account) {
            vClients.erase(it);
            return true;
        }
    }
    return false;
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
int main() {
    string Account;
    vector<stClint> vClients = LoadCleintsDataFromFile("bank.txt");

    cout << "Please enter AccountNumber?: ";
    cin>> Account;

    stClint SearchResult = Finder(vClients, Account);

    if(!SearchResult.AccountNumber.empty()) {
        char Delete;
        TablePrinter(Account);
        PrintClientRecord(SearchResult);
        cout << endl;
        cout << "Are you sure you want to delete this account? Y/n?";
        cin >> Delete;

        if(Delete == 'Y' || Delete == 'y') {
        if (DeleteRecord(vClients, Account)) {
            SaveToFile("bank.txt",vClients);
            cout<< "Clint account has been deleted!!";
        }else {

            cout << "Record isn't exist !!";
        }
        }
    }else {
        cout << "Account (" << Account << ") not found";
    }
    return 0;
}

/*
const string ClientsFileName = "Clients.txt";
struct sClient
{
string AccountNumber;
string PinCode;
string Name;
string Phone;
double AccountBalance;
bool MarkForDelete = false;
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
sClient ConvertLinetoRecord(string Line, string Seperator =
"#//#")
{
sClient Client;
vector<string> vClientData;
vClientData = SplitString(Line, Seperator);
Client.AccountNumber = vClientData[0];
Client.PinCode = vClientData[1];
Client.Name = vClientData[2];
Client.Phone = vClientData[3];
Client.AccountBalance = stod(vClientData[4]);//cast string to
double
return Client;
}
string ConvertRecordToLine(sClient Client, string Seperator =
"#//#")
{
string stClientRecord = "";
stClientRecord += Client.AccountNumber + Seperator;
stClientRecord += Client.PinCode + Seperator;
stClientRecord += Client.Name + Seperator;
stClientRecord += Client.Phone + Seperator;
stClientRecord += to_string(Client.AccountBalance);
return stClientRecord;
}
vector <sClient> LoadCleintsDataFromFile(string FileName)
{
vector <sClient> vClients;
fstream MyFile;
MyFile.open(FileName, ios::in);//read Mode
if (MyFile.is_open())
{
string Line;
sClient Client;
while (getline(MyFile, Line))
{
Client = ConvertLinetoRecord(Line);
vClients.push_back(Client);
}
MyFile.close();
}
return vClients;
}
void PrintClientCard(sClient Client)
{
cout << "\nThe following are the client details:\n";
cout << "\nAccout Number: " << Client.AccountNumber;
cout << "\nPin Code : " << Client.PinCode;
cout << "\nName : " << Client.Name;
cout << "\nPhone : " << Client.Phone;
cout << "\nAccount Balance: " << Client.AccountBalance;
}
bool FindClientByAccountNumber(string AccountNumber, vector
<sClient> vClients, sClient& Client)
{
for (sClient C : vClients)
{
if (C.AccountNumber == AccountNumber)
{
Client = C;
return true;
}
}
return false;
}
bool MarkClientForDeleteByAccountNumber(string AccountNumber,
vector <sClient>& vClients)
{
for (sClient& C : vClients)
{
if (C.AccountNumber == AccountNumber)
{
C.MarkForDelete = true;
return true;
}
}
return false;
}
vector <sClient> SaveCleintsDataToFile(string FileName, vector
<sClient> vClients)
{
fstream MyFile;
MyFile.open(FileName, ios::out);//overwrite
string DataLine;
if (MyFile.is_open())
{
for (sClient C : vClients)
{
if (C.MarkForDelete == false)
{
//we only write records that are not marked for
delete.
DataLine = ConvertRecordToLine(C);
MyFile << DataLine << endl;
}
}
MyFile.close();
}
return vClients;
}
bool DeleteClientByAccountNumber(string AccountNumber, vector
<sClient>& vClients)
{
sClient Client;
char Answer = 'n';
if (FindClientByAccountNumber(AccountNumber, vClients,
Client))
{
PrintClientCard(Client);
cout << "\n\nAre you sure you want delete this client? y/n ? ";
cin >> Answer;
if (Answer == 'y' || Answer == 'Y')
{
MarkClientForDeleteByAccountNumber(AccountNumber,
vClients);
SaveCleintsDataToFile(ClientsFileName, vClients);
//Refresh Clients
vClients = LoadCleintsDataFromFile(ClientsFileName);
cout << "\n\nClient Deleted Successfully.";
return true;
}
}
else
{
cout << "\nClient with Account Number (" << AccountNumber
<< ") is Not Found!";
return false;
}
}
string ReadClientAccountNumber()
{
string AccountNumber = "";
cout << "\nPlease enter AccountNumber? ";
cin >> AccountNumber;
return AccountNumber;
}
int main()
{
vector <sClient> vClients =
LoadCleintsDataFromFile(ClientsFileName);
string AccountNumber = ReadClientAccountNumber();
DeleteClientByAccountNumber(AccountNumber, vClients);
system("pause>0");
return 0;
}
*/