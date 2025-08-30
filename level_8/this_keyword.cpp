#include <iostream>
using namespace std;

class clsEmployee {
    public:
    int Id;
    string Name;
    double Salary;
    clsEmployee(int Id, string Name, double Salary) {
        this->Id = Id;
        this->Name = Name;
        this->Salary = Salary;
    }

    static void PrintEmployee(clsEmployee emp) {

        emp.Print();
    }

    void PassingToStatic() {
        PrintEmployee(*this);
    }

    void Print() {
        // cout << this->ID << "  " << this->Name << "  " << this->Salary << endl;
        cout << Id <<"  "<< Name <<"  "<< Salary << endl;
    }
};

int main() {
    clsEmployee employee(101,"Carlos costa", 5000);
    employee.Print();
    employee.PassingToStatic();
}