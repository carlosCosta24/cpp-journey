#include <iostream>
using namespace std;

class clsEmployee {
private:
    int _ID;
    string _FirstName;
    string _LastName;
    string _Title;
    string _Email;
    string _Phone;
    float _Salary;
    string _Department;


public:
    //constructor
    clsEmployee(string FirstName, string LastName, string Email, string Phone,string title,float salary, string department, int ID) {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
        _Title = title;
        _Salary = salary;
        _Department = department;

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
    void setTitle(string title) {
        _Title = title;
    }
    void setSalary(float salary) {
        _Salary = salary;

    }
    void setDepartment(string department) {
        _Department = department;
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
    string Title() {
        return _Title;

    }
    float Salary() {
        return _Salary;
    }
    string Department() {
        return _Department;
    }

    void PrintData() {
        cout << "Info:";
        cout << "\n-----------------------------------\n";
        cout << "ID: " << _ID << endl;
        cout << "Title: " << _Title << endl;
        cout << "Department: " << _Department << endl;
        cout << "First Name: " << _FirstName << endl;
        cout << "Last Name: " << _LastName << endl;
        cout << "Full Name: " << FullName() << endl;
        cout << "Email: " << _Email << endl;
        cout << "Phone: " << _Phone << endl;
        cout << "Salary: " << _Salary << endl;
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

    clsEmployee Employee1("Carlos", "Costa",
        "CarlosCosta@mail.com", "799965822245",
        "junior dev", 2000, "Development", 1);

    Employee1.PrintData();
    Employee1.SendEmail("project initialization", "Hello");
    Employee1.SendSMS("are you interested");

    return 0;
}