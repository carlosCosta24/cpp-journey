#include <iostream>
#include <string>
using namespace std;

int reverse()
{
    // reversing the process

    int Fnum = 1998;
    double Snum = 19.98;

    string str1 = to_string(Fnum);
    string str2 = to_string(Snum);

    cout << str1 << endl;
    cout << str2 << endl;
    return 0;
}
int main()
{

    string str = "122.4577";

    int str_to_int = stoi(str);
    float str_to_flt = stof(str);
    double str_to_dob = stod(str);

    cout << "num_int: " << str_to_int << endl;
    cout << "num_float: " << str_to_flt << endl;
    cout << "num_double: " << str_to_dob << endl;
    reverse();

    return 0;
}
