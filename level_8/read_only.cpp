#include <iostream>
using namespace std;

class clsPerson
{
private:
    //only accessible inside this class
    //by convention any private variable should start with _
    // all variables are private
    short _ID = 1256985;
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
    //to add an read only property we create only a get function
    short Id() {
        return _ID;
    }
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
    cout << "Person Id: "<<Person1.Id() << endl;
    cout << "First Name: "<<Person1.FirstName()<< endl;
    cout << "Last Name: "<<Person1.LastName()<< endl;
    cout << "Full Name: "<<Person1.FullName() << endl;
    return 0;

}