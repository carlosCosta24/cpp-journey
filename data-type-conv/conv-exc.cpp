#include <iostream>
#include <string>
using namespace std;

int main()
{

    string st1 = "43.22";
    int N1 = 20;
    double N2 = 33.5;
    float N3 = 55.23;

    int st1_int = stoi(st1);
    float st1_float = stof(st1);
    double st1_double = stod(st1);

    string str_N1 = to_string(N1);
    string str_N2 = to_string(N2);
    string str_N3 = to_string(N3);
    int int_3 = (int)N3;

    cout << st1_int << endl;
    cout << st1_float << endl;
    cout << st1_double << endl;
    cout << str_N1 << endl;
    cout << str_N2 << endl;
    cout << str_N3 << endl;
    cout << int_3 << endl;

    return 0;
}