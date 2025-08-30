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
    clsPersonData(){}
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

class clsEmployee : public clsPersonData {
private:
    string _Title;
    string _Department;
    float _Salary;

public:
    clsEmployee(string Firstname, string LastName, string Email, string Phone, int ID,
        string Title, string Department, float Salary)
        :clsPersonData(Firstname, LastName, Email, Phone, ID)
    {
        _Title = Title;
        _Department = Department;
        _Salary = Salary;

    }
    //set
    void SetTitle(string Title) {
        _Title = Title;
    }
    void SetDepartment(string Department) {
        _Department = Department;
    }
    void SetSalary(float Salary) {
        _Salary = Salary;
    }
    // get
    string Title() {
        return _Title;

    }
    string Department() {
        return _Department;

    }
    float Salary() {
        return _Salary;
    }
    void PrintData() {
        //to access an function from the baseclas
        //clsPersonData::PrintData();
        cout << "Info:";
        cout << "\n-----------------------------------\n";
        cout << "Full Name:  " << FullName() << endl;
        cout << "ID:         " << ID() << endl;
        cout << "Title:      " << _Title << endl;
        cout << "Department: " << _Department << endl;
        cout << "First Name: " << FirstName() << endl;
        cout << "Last Name:  " << LastName() << endl;
        cout << "Email:      " << Email() << endl;
        cout << "Phone:      " << Phone() << endl;
        cout << "Salary:     " << _Salary << endl;
        cout << "\n-----------------------------------\n";
    }



};

int main() {

    clsEmployee Employee1("carlos", "costa", "carlos@mail.com", "7952583465",
        105, "junior SWE", "Development", 500);
    Employee1.PrintData();

    return 0;
}