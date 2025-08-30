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
    string GetTitle() {
        return _Title;

    }
    string GetDepartment() {
        return _Department;

    }
    float GetSalary() {
        return _Salary;
    }



};

int main() {

    clsEmployee Employee1;
    Employee1.setFirstName("carlos");
    Employee1.setLastName("costa");
    Employee1.setEmail("carlos.costa@mail.com");
    Employee1.setPhone("+55 79991412736");
    Employee1.PrintData();
    cout << Employee1.Phone()<< endl;

    Employee1.SetDepartment("Development");
    Employee1.SetSalary(5000);
    Employee1.PrintData();

    cout << endl<< Employee1.GetSalary();

    // clsPersonData firstPerson("Carlos", "Costa",
    //     "CarlosCosta@mail.com", "799965822245", 1);
    //
    // firstPerson.PrintData();
    //
    // firstPerson.SendEmail("job interview", "Hello");
    // firstPerson.SendSMS("are you interested");

    return 0;
}