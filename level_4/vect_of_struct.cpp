#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct stEmployee {
    string FirstName;
    string LastName;
    int Age;

};

int main() {
    vector<stEmployee> vEmployees;

    stEmployee emp;

    emp.FirstName = "John";
    emp.LastName = "Mary";
    emp.Age = 20;
    vEmployees.push_back(emp);

    emp.FirstName = "carlos";
    emp.LastName = "costa";
    emp.Age = 26;
    vEmployees.push_back(emp);

    emp.FirstName = "ricardo";
    emp.LastName = "cost";
    emp.Age = 40;
    vEmployees.push_back(emp);

    cout<< "Employee list: "<< endl;

    for (stEmployee &rec : vEmployees ) {
        cout<< rec.FirstName << ", " << rec.LastName << endl;
        cout<< rec.Age <<" years" << endl;
    }

    return 0;

}