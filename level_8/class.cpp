#include <iostream>
using namespace std;

class clsPerson
{
    // by default any method , or variable is privet;
    public:
    string FirstName;
    string LastName;
    string FullName() const{
        return FirstName + " " + LastName;
    }
};

int main(){

    clsPerson Person1;
    Person1.FirstName = "Carlos";
    Person1.LastName = "Costa";
    cout << Person1.FullName() << endl;
    return 0;

}