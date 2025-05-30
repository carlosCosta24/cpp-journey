#include <iostream>
#include <string>
#include <vector>
using namespace std;

string Read() {
    string S;
    cout << "Enter a sentence: ";
    getline(cin, S);
    return S;
}

vector<string> StringSpliter(string S, string Splitter) {
    vector<string> vResult;
    int Pos = 0;
    string Word;

    while ((Pos = S.find(Splitter)) != string::npos) {
        Word = S.substr(0,Pos);
        if (Word != "") vResult.push_back(Word);
        S.erase(0, Pos + Splitter.length());
    }
    if (S != "") vResult.push_back(S);
    return vResult;
}

void TokenPrinter(vector<string> &vVector) {
    cout << "Tokens = " << vVector.size() << endl;
    for (string &s : vVector) {
        cout << s << endl;
    }
}

int main() {
    string S = Read();
    vector<string> vResult = StringSpliter(S, " ");
    TokenPrinter(vResult);
    return 0;
}

