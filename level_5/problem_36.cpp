#include <iostream>
#include <string>
using namespace std;

string Read() {
    string S;
    cout << "Enter a sentence: ";
    getline(cin, S);
    return S;
}

int WordCounter(string S) {
    string Space = " ";
    int Pos,Counter = 0 ;
    string Word;
    while ((Pos = S.find(Space)) != std::string::npos) {
        Word = S.substr(0, Pos);
        if (Word != "") Counter++;

        S.erase(0,Pos + Space.length());
    }
    if (S != "") Counter++;
    return Counter;
}

int main() {
    string S = Read();
    cout << "The number of word in the string is: "<< WordCounter(S)<< endl;
    return 0;
}