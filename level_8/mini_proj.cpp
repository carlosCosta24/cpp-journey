#include <iostream>
using namespace std;

class clsPersonData {
private:
    int _ID;
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;
public:
    //constructor
    clsPersonData(string FirstName, string LastName, string Email, string Phone, int ID) {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }
    //Read only
    int ID() {
        return _ID;
    }

    //set
    void setFirstName(string FirstName) {
        _FirstName = FirstName;

    }
    void setLastName(string LastName) {
        _LastName = LastName;

    }
    void setEmail(string Email) {
        _Email = Email;


    }
    void setPhone(string Phone) {
        _Phone = Phone;

    }
    //get


    string FirstName() {
        return _FirstName;
    }
    string LastName() {
        return _LastName;

    }
    string FullName() const {
        return _FirstName + " " + _LastName;
    }
    string Email() {
        return _Email;
    }
    string Phone() {
        return _Phone;

    }
    void PrintData() {
        cout << "Info:";
        cout << "\n-----------------------------------\n";
        cout << "ID: " << _ID << endl;
        cout << "First Name: " << _FirstName << endl;
        cout << "Last Name: " << _LastName << endl;
        cout << "Full Name: " << FullName() << endl;
        cout << "Email: " << _Email << endl;
        cout << "Phone: " << _Phone << endl;
        cout << "\n-----------------------------------\n";


    }
    void SendEmail(string Subject, string Body) {
        cout << "The following message sent successfully to email: "<< _Email << endl;
        cout << "Subject: " << Subject << endl;
        cout << "Body: " << Body << endl;
        cout << "\n";
    }

    void SendSMS(string Message) {
        cout << "The following SMS sent successfully to phone: " << _Phone << endl;
        cout << "Message: " << Message << endl;
        cout << "\n";
    }


};

int main() {

    clsPersonData firstPerson("Carlos", "Costa",
        "CarlosCosta@mail.com", "799965822245", 1);

    firstPerson.PrintData();

    firstPerson.SendEmail("job interview", "Hello");
    firstPerson.SendSMS("are you interested");

    return 0;
}