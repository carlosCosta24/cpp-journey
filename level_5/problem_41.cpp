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
/*
string ReverseWordsInString(string S1)
{
    vector<string> vString;
    string S2 = "";
    vString = SplitString(S1, " ");
    // declare iterator
    vector<string>::iterator iter = vString.end();
    while (iter != vString.begin())
    {
        --iter;
        S2 += *iter + " ";
    }
    S2 = S2.substr(0, S2.length() - 1); //remove last space.
    return S2;
}
*/
string StringReverser(vector<string> &vIn) {
    string Reversed ="";
    for (int i = vIn.size()-1; i >= 0; i--) {
        Reversed += vIn[i];
        if (i != 0) Reversed += " ";
    }
    return Reversed;
}

int main() {
    string S = Read();
    vector<string> vSpliter = StringSpliter(S, " ");
    cout << StringReverser(vSpliter);
    return 0;
}
