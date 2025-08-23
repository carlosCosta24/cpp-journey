#include <iostream>
using namespace std;

class clsPerson
{
private:
    //only accessible inside this class
    //by convention any private variable should start with _
    // all variables are private
    string _FirstName;
    string _LastName;
public:
    //all access and edit to any member of the class should be done
    //using the class properties get and set
    //set property:
    void setFirstName(string FirstName) {
        _FirstName = FirstName;
    }
    void setLastName(string LastName) {
        _LastName = LastName;
    }
    //get
    string FirstName() {
        return _FirstName;

    }
    string LastName() {
        return _LastName;
    }
    string FullName() const{
        return _FirstName + " " + _LastName;
    }
};

int main(){

    clsPerson Person1;
    Person1.setFirstName("Carlos");
    Person1.setLastName("Costa");
    cout << Person1.FirstName()<< endl;
    cout << Person1.LastName()<< endl;
    cout << Person1.FullName() << endl;
    return 0;

}