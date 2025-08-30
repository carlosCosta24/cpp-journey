#include <iostream>
#include <string>
using namespace std;

//abstract class / interface / contract

class clsMobile {
    virtual void Dail(string phoneNumber) = 0;
    virtual void SendSMS(string Text, string PhoneNumber) = 0;
    virtual void SendEmail(string Text, string Email) = 0;
};

class clsIphone : public clsMobile {
    public:
    virtual void Dail(string phoneNumber) {
        cout << phoneNumber << endl;
    };
    virtual void SendSMS(string Text, string PhoneNumber) {
        cout << Text << endl;
    };
    virtual void SendEmail(string Text, string Email) {
        cout << Email << endl;
    };
};

int main() {
    clsIphone myIphone;

    myIphone.Dail("John");
    myIphone.SendEmail("Hi joan hope you are doing good.","John@email.com");
    myIphone.SendSMS("Are available next monday?","0214458744");

    return 0;
}