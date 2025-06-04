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
    double Amount;
};

vector<string> FileReader(string FileName) {
    fstream file(FileName, ios::in);
    vector<string> vData;
    string Line;

    if (file.is_open()) {
        while ( getline(file, Line)) {

            if (!Line.empty()) vData.push_back(Line) ;
        }
    file.close();
    }
    return vData;

}

vector <string> SeparatorRemover(vector<string> &S, string &Sep) {
    vector <string> vResult;
    for (string &L : S) {
    int Pos = 0;
    while ((Pos = L.find(Sep)) != string::npos) {
        string Temp = L.substr(0, Pos);
        vResult.push_back(Temp);
        L.erase(0, Pos + Sep.length());
    }
    if (!L.empty()) {
        vResult.push_back(L);
    }
    }
    return vResult;
}

vector<stClint> LineToRecord(vector<string> &vTokens) {

    vector<stClint> vResult;

    for (int i = 0;i + 4 < vTokens.size(); i+=5) {
        stClint stResult;
        stResult.AccountNumber = vTokens[i];
        stResult.Pin = vTokens[i+1];
        stResult.Name = vTokens[i+2];
        stResult.Phone = vTokens[i+3];
        stResult.Amount = stod(vTokens[i+4]);
        vResult.push_back(stResult);
    }

    return vResult;
}

void TablePrinter(short N) {
    cout << setw(15) << "Client List " << "(" << N << ") Client(s)" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "| " << setw(15) << left << "Account Number"
         << "| " << setw(10) << "Pin Code"
         << "| " << setw(15) << "Client Name"
         << "| " << setw(15) << "Phone"
         << "| " << setw(10) << "Balance" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
}

void StructPrinter(vector<stClint> &v) {
    for (stClint &st: v) {
        cout << "| " << setw(15) << left << st.AccountNumber
     << "| " << setw(10) << st.Pin
     << "| " << setw(15) << st.Name
     << "| " << setw(15) << st.Phone
     << "| " << setw(10) << fixed << setprecision(2) << st.Amount << endl;
    }
}

int main() {
    vector<string> vData = FileReader("bank.txt");
    string Separator= "/*/";
    vector<string> vToken = SeparatorRemover(vData,Separator);
    vector<stClint> vLine = LineToRecord(vToken);
    TablePrinter(vLine.size());
    StructPrinter(vLine);
    cout << "------------------------------------------------------------------------------" << endl;
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

void PrintClientRecord(sClient Client)
{
cout << "| " << setw(15) << left << Client.AccountNumber;
cout << "| " << setw(10) << left << Client.PinCode;
cout << "| " << setw(40) << left << Client.Name;
cout << "| " << setw(12) << left << Client.Phone;
cout << "| " << setw(12) << left << Client.AccountBalance;
}
void PrintAllClientsData(vector <sClient> vClients)
{
cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ")
Client(s).";
cout <<
"\n_______________________________________________________";
cout << "_________________________________________\n" << endl;
cout << "| " << left << setw(15) << "Accout Number";
cout << "| " << left << setw(10) << "Pin Code";
cout << "| " << left << setw(40) << "Client Name";
cout << "| " << left << setw(12) << "Phone";
cout << "| " << left << setw(12) << "Balance";
cout <<
"\n_______________________________________________________";
cout << "_________________________________________\n" << endl;
for (sClient Client : vClients)
{
PrintClientRecord(Client);
cout << endl;
}
cout <<
"\n_______________________________________________________";
cout << "_________________________________________\n" << endl;
}

int main()
{
vector <sClient> vClients =
LoadCleintsDataFromFile(ClientsFileName);
PrintAllClientsData(vClients);
system("pause>0");
return 0;
}
 */