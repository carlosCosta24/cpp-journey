#include <iostream>
#include <string>
using namespace std;
string Read() {
    string S;
    cout << "Enter a sentence: ";
    getline(cin, S);
    return S;
}
void WordPrinter(string Frase) {
    bool Start = true;
    for (int i = 0 ; i < Frase.length() ; i++) {
        if(Start && Frase[i] == ' ') {
            cout << Frase[i]<< endl;
        }
        (Frase[i] == ' ') ? Start = false : Start = true;
    }
}

int main() {
    string S = Read();
    WordPrinter(S);
    return 0;
}