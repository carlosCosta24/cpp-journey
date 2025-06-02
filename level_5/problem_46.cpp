#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct stClint {
    string AccountNumber;
    string Pin;
    string Name;
    string Phone;
    double Amount;
};

vector<string> RecordSeparator(string Record , string Separator) {
    vector<string> ResultRecords;
    short Pos = 0;
    string Current = "";
    while ((Pos =Record.find(Separator)) != string::npos) {
            Current = Record.substr(0,Pos);
            if (Current != "") {
                ResultRecords.push_back(Current);
            }
            Record.erase(0, Pos + Separator.length());
        }
    if (!Record.empty()) {
        ResultRecords.push_back(Record);
    }
    return ResultRecords;
}

stClint LineToRecord(string Line, string Separator){
    stClint stResult;
    vector<string> vData = RecordSeparator(Line, Separator);
    stResult.AccountNumber = vData[0];
    stResult.Pin = vData[1];
    stResult.Name = vData[2];
    stResult.Phone = vData[3];
    stResult.Amount = stod(vData[4]);

    return stResult;
}



void PrintClientRecord(stClint &Client)
{
    cout << "\n\nThe following is the extracted client record:\n";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code : " << Client.Pin;
    cout << "\nName : " << Client.Name;
    cout << "\nPhone : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.Amount;
}




int main() {
    string Line= "A150#//#1234#//#carlos costa #//#079999#//#5270.000000";
    stClint Client = LineToRecord(Line, "#//#");
    PrintClientRecord(Client);
    return 0;
}