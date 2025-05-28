#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

string Read() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str) ;
    return str;
}

void CapitalFirstLetter(string String ) {
    bool IsFirstLetter = true;

    for (int i =0; i < String.length(); i++) {
        if (String[i] != ' ' && IsFirstLetter) {
            String[i] = toupper(String[i]);
        }
        IsFirstLetter = (String[i] == ' ' ? true : false);
        cout << String[i] ;
    }
}

int main() {
    CapitalFirstLetter(Read());
    return 0;
}