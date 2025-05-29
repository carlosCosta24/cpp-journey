#include <iostream>
#include <string>
using namespace std;

string Read() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str) ;
    return str;
}
int CaseLetterCounter(string Str, char Target){
    int Count=0;
    for(int i =0 ; i <Str.length(); i ++){
        if(Str[i] == Target) Count ++ ;
    }
    return Count;
}

int main() {
    string UserInput = Read();
    char Target;
    cout << "Enter a Letter to Search for: ";
    cin>> Target;

    (CaseLetterCounter(UserInput, Target) == 0)?
    cout<< "No match " :
    cout << "The letter " << Target << " is " << CaseLetterCounter(UserInput, Target);
    return 0;


}