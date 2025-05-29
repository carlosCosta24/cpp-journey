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

string CaseInventer(string String ) {

    for (int i =0; i < String.length(); i++) {
        (isupper(String[i])) ? String[i] = tolower(String[i]): String[i] = toupper(String[i]) ;
    }
    return String ;
}

//letter case inverter
char InvertLetterCase(char char1) {
    return isupper(char1) ? tolower(char1) : toupper(char1);
}


int main() {
    string str = Read();
    cout << "String before edit: "<< endl;
    cout << str<< endl;
    cout << "String after edit: "<< endl;
    cout << CaseInventer(str)<<endl;

    return 0;
}