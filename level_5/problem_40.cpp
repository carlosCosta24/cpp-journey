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
string StringJoin(vector<string> &S, string Splitter) {
    string String = "";
    for (string &Word : S ) {
        String += Word + Splitter;
    }
    return String.substr(0, String.length()-Splitter.length());
}

string StringJoin(string arr[], int Length,string Splitter) {
    string String = "";
    for (int i =0; i < Length; i++) {
        String += arr[i] + Splitter;
    }
    return String.substr(0, String.length()-Splitter.length());
}

int main() {
    string S = "carlos costa ";
    string arr[2] = {"costa","carlos"};
    vector<string> vResult = StringSpliter(S, " ");
    TokenPrinter(vResult);
    cout << StringJoin(vResult, "-")<< endl;
    cout << StringJoin(arr, 2,"&&")<< endl;
    return 0;
}