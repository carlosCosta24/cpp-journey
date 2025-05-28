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

void LowerFirstLetter(string String ) {
    bool IsFirstLetter = true;

    for (int i =0; i < String.length(); i++) {
        if (String[i] != ' ' && IsFirstLetter) {
            String[i] = tolower(String[i]);
        }
        IsFirstLetter = (String[i] == ' ' ? true : false);
        cout << String[i] ;
    }
}

int main() {
    LowerFirstLetter(Read());
    return 0;
}