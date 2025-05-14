#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct stEmployee {
    string FirstName;
    string LastName;
    int Age=0;

};

void EmployeesFiller(vector<stEmployee> & Employee ) {
    string Yes = "Yes";
    stEmployee temp;
    do {

        cout << "do you want to add an employee(YES / NO )?? :";
        cin >> Yes;
        if (Yes[0] != 'Y' && Yes[0] != 'y') break;

        cout<< "Enter The employee Firstname:";
        cin >> temp.FirstName;

        cout << "Enter The employee Lastname:";
        cin >> temp.LastName;

        cout << "Enter The employee Age :";
        cin>>temp.Age;

        Employee.push_back(temp);

    } while (Yes[0] == 'Y' || Yes[0] == 'y');
}
void GraphicPrinter(string Header = "BasicHeader"  , string Footer = "BasicFooter") {
    if (Header == "Header") cout << "|---------------|-----------------|-----------|\n";
    else if (Footer == "Footer") cout << "*---------------*-----------------*-----------*\n";
    else cout << " ";
}
void VectorPrinter(vector<stEmployee> & employees) {
    GraphicPrinter("Header");
    cout <<setw(5)<< "First Name " <<setw(22) <<"Second Name" << setw(10) << "Age\n"  ;
    GraphicPrinter("Header");

    for (stEmployee &temp : employees) {
        cout << temp.FirstName << setw(22) << temp.LastName << setw(14)<< temp.Age << "\n";
        GraphicPrinter("Header");


    }
    GraphicPrinter(" ","Footer");
}

int main() {
    vector<stEmployee> Employee;
    EmployeesFiller(Employee);
    VectorPrinter(Employee);
    return 0;

}