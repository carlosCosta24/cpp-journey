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
//using a builtin fun
/*
    string ReplaceWordInStringUsingBuiltInFunction
    (string S1, string StringToReplace, string sRepalceTo)
    {
    short pos = S1.find(StringToReplace);
    while (pos != std::string::npos)
    {
    S1 = S1.replace
    (pos, StringToReplace.length(),sRepalceTo);
    pos = S1.find(StringToReplace);//find next
    }
    return S1;
    }
*/
void StringReplacer(vector<string> &S, string Target, string Replacement ) {
    for (string &Word : S) {
        if (Word == Target) Word = Replacement;
    }
}
void TokenPrinter(vector<string> &vVector) {
    cout << "New string is: " << vVector.size() << endl;
    for (string &s : vVector) {
        cout << s << endl;
    }
}

int main() {
    string S = Read();
    string Target;
    string Replacement;
    vector<string> vString = StringSpliter(S, " ");

    cout << "Please chose a Word to replace: ";
    cin >> Target;

    cout << "Please enter a replacer: ";
    cin >> Replacement;

    StringReplacer(vString, Target, Replacement);
    TokenPrinter(vString);

    return 0;
}