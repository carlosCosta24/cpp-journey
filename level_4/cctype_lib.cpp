#include <iostream>
#include <cctype>
using namespace std;

int main() {

    char x = toupper('z');
    char y = tolower('M');

    cout << "converting z to Z: " << x<< endl;
    cout << "converting M to m: " << y << endl;

    cout<< isupper(x) << endl;
    cout<< islower(y) << endl;
    cout<< isdigit(5) << endl;
    cout<< ispunct(';') << endl;

return 0;


}