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

string PunctuationRemover(string S) {
    string Result = "";
    for (int i = 0; i < S.length(); i++) {
        if(!ispunct(S[i])) Result += S[i];
    }
    return Result;
}

int main() {
    string S = Read();
    cout << S<< endl;
    cout << PunctuationRemover(PunctuationRemover(S))<< endl;
    return 0;

}