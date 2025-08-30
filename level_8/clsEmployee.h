#pragma once
#include <iostream>
#include "clsPerson.h"
using namespace std;

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
        //to access a function from the base class
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