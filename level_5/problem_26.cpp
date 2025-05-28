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

string CapitalString(string String ) {
    for (int i =0; i < String.length(); i++) {
        String[i] = toupper(String[i]) ;
    }
    return String ;
}
string LowerString(string String ) {
    for (int i =0; i < String.length(); i++) {
        String[i] =tolower(String[i]) ;
    }
    return String ;
}

int main() {
    string str = Read();
    cout << "String after upper: "<< endl;
    cout << CapitalString(str)<< endl;
    cout << "String after lower: "<< endl;
    cout << LowerString(str)<<endl;

    return 0;
}