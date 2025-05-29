#include <iostream>
#include <string>
using namespace std;

string Read() {
    string str;
    cout << "Please enter a string: ";
    getline(cin, str);
    return str;
}


string CaseInverter(string Str){
    for(int i =0 ; i < Str.length(); i++){
        char Curr = Str[i];
        Str[i] = isupper(Curr)? Curr = tolower(Curr): Curr = toupper(Curr);
    }
    return Str;
}

// second method

char InvertLetterCase(char char1)
{
    return isupper(char1) ? tolower(char1) : toupper(char1);
}

string InvertAllStringLettersCase(string S1)
{
    for (short i = 0; i < S1.length(); i++)
{
        S1[i] = InvertLetterCase(S1[i]);
}
return S1;
}


int main()
{
    string UserInput = Read();
    cout << CaseInverter(UserInput);
    return 0;
}
