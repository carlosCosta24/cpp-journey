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
string WordCap(string Input ){
    string OutPut;
    for (int i = 0; i < Input.length(); i++) {
        OutPut += toupper(Input[i]);
    }
    return OutPut;
}
void StringReplacer(vector<string> &S, string Target, string Replacement ,bool ExactMatch = false ) {
    if (ExactMatch) {
        for (string &Word : S) {
            if (WordCap(Word) == WordCap(Target)) Word = Replacement;
        }
    }else {
        for (string &Word : S) {
            if (Word == Target) Word = Replacement;
        }
    }

}
void TokenPrinter(vector<string> &vVector) {
    for (string &s : vVector) {
        cout << s << endl;
    }
}
/*
 * modified method ;
string ReplaceWordInStringUsingSplit(string S1, string
StringToReplace, string sRepalceTo, bool MatchCase = true)
{
vector<string> vString = SplitString(S1, " ");
for (string& s : vString)
{
if (MatchCase)
{
if (s == StringToReplace)
{
s = sRepalceTo;
}
}
else
{
if (LowerAllString(s) ==
LowerAllString(StringToReplace))
{
s = sRepalceTo;
}
}
}
return JoinString(vString, " ");
}

 */

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
    cout << "Replaced string with case match "<< endl;
    TokenPrinter(vString);

    cout << "Replaced string without case match " << endl;
    StringReplacer(vString, Target, Replacement, true);
    TokenPrinter(vString);

    return 0;
}