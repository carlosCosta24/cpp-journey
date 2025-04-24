#include <iostream>
#include <string>
using namespace std;

int main()
{
    string user_str, str_1, str_2;

    cout << "Please enter a string >> ";
    getline(cin, user_str);

    cout << "Please enter a string 1 >> ";
    cin >> str_1;

    cout << "Please enter a string 2 >> ";
    cin >> str_2;

    cout << "*************************************" << endl;
    cout << "The length of the first string is: " << user_str.length() << endl;
    cout << "characters at 0,2,4,9 are: " << user_str[0] << user_str[2] << user_str[4] << user_str[9] << endl;
    cout << "concatenation of the first string and the second string is: " << str_1 + str_2 << endl;
    cout << str_1 << " * " << str_2 << " = " << stoi(str_1) * stoi(str_2) << endl;

    return 0;
}