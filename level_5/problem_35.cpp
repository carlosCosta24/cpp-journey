#include <filesystem>
#include <iostream>
#include <string>
#include <bits/locale_facets_nonio.h>
using namespace std;
string Read() {
    string S;
    cout << "Enter a sentence: ";
    getline(cin, S);
    return S;
}
/*
void PrintEachWordInString(string S1)
{
string delim = " "; // delimiter
cout << "\nYour string wrords are: \n\n";
short pos = 0;
string sWord; // define a string variable
// use find() function to get the position of the delimiters
while ((pos = S1.find(delim)) != std::string::npos)
{
sWord = S1.substr(0, pos); // store the word
if (sWord != "")
{
cout << sWord << endl;
}
// erase() until positon and move to next word.
S1.erase(0, pos + delim.length());
}
*/
void WordPrinter(string Frase) {
    string Space = " ";
    string Word;
    int StartPosition = 0;

    while ((StartPosition = Frase.find(Space)) != string::npos) {
        Word = Frase.substr(0,StartPosition);
        if (Word != "") {
            cout << Word<< endl;
        }
            Frase.erase(0, StartPosition+Space.length());
    }
    if (Frase != "") {
        cout << Frase<< endl;
    }
}

int main() {
    string S = Read();
    WordPrinter(S);
    return 0;
}