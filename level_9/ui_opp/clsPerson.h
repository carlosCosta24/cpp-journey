#pragma once
#include <iostream>
#include <string>
#include "InterfaceCommunication.h"
using namespace std;

class clsPerson : public InterfaceCommunication {
    private:
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;
    public:
    clsPerson(string FirstName, string LastName, string Email, string Phone) {
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }
    void SetFirstName(string FName) {
        _FirstName = FName;
    }
    string GetFirstName() {
        return _FirstName;
    }
    void SetLastName(string LName) {
        _LastName = LName;
    }
    string GetLastName() {
        return _LastName;
    }
    void SetEmail(string Email) {
        _Email = Email;
    }
    string GetEmail() {
        return _Email;
    }
    void SetPhone(string Phone) {
        _Phone = Phone;
    }
    string GetPhone() {
        return _Phone;
    }
    string FullName() {
        return _FirstName + " " +_LastName;
    }
    void SendEmail(string Title, string Body) {}
    void SendMessage(string Title, string Body) {}


};