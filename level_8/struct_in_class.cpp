#include<iostream>
using namespace std;

class clsPerson {
    struct stAddress {
        string address;
        string address_id;
        string city;
        string country;
    };
    public:
    string FullName;
    stAddress Address;

    clsPerson() {
        FullName = "carlos costa ";
        Address.address_id = "1234";
        Address.city = "Amsterdam";
        Address.country = "netherland";

    }

    void Print() {
        cout << "---------------------------------"<< endl;
        cout << "FullName: " << FullName << endl;
        cout << "Address: " << Address.address << endl;
        cout << "City: " << Address.city << endl;
        cout << "Country: " << Address.country << endl;
        cout << "-------------------------------"<< endl;

    }
};

int main() {

    clsPerson person;
    person.Print();
    return 0;
}