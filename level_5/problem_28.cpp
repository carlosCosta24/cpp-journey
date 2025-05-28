#include <iostream>
#include <string>
using namespace std;

string CaseInverter(string String){
    for(int i =0 ; i < String.length(); i++){
        char Curr = String[i];
        String[i] = isupper(Curr)? Curr = tolower(Curr): Curr = toupper(Curr);
    }
    return String;
}

int main()
{
    string UserInput;
    cout<< "Please Enter a string: ";
    getline(cin, UserInput);
    cout << CaseInverter(UserInput);

    return 0;
}
