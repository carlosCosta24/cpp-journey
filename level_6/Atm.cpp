#include <iostream>
#include <vector>
using namespace std;

struct stClient {
    string account;
    string password;
    string phone;
    string name;
    double balance = 0;
    bool selected = false;
};