#include <iostream>
using namespace std;

class clsPerson
{
    // by default any method , or variable is privet;
    // there are 3 types of access modifiers:
    // public, private, protected.
    //protected: accessible inside the class and classes inherits
private:
    //only accessible inside this class
    int salary = 10000;
    int GetSalary() {
        return salary;
    };

protected:
    //only accessible inside this class and all classes inherits this class.
    int WorkHours = 50;
    int GetWorkHours() {
        return WorkHours;
    }
public:
    // accessible for everyone outside /inside/ and class inherits this class
    string FirstName;
    string LastName;
    string FullName() const{
        return FirstName + " " + LastName;
    }
    float DailySalary() {
        float DailySalary = GetSalary() / ( 4 * WorkHours) ;

        return DailySalary;
    }
    string PrintDailySalary() {
        return  to_string(DailySalary()) + "s";
    }

};

int main(){

    clsPerson Person1;
    Person1.FirstName = "Carlos";
    Person1.LastName = "Costa";
    cout << Person1.FullName() << endl;
    cout<< Person1.PrintDailySalary() << endl;
    return 0;

}