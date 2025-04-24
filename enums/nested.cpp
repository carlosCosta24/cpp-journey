#include <iostream>
using namespace std;

enum enColor
{
    red,
    white,
    blue,
    black
};
enum enGender
{
    Male,
    Female
};
enum enStatus
{
    Married,
    Single
};

struct stAddress
{
    string StreetName;
    string BuildingNo;
    string POBox;
    string ZipCode;
};
struct stContactInfo
{
    string Phone;
    string Email;
    stAddress Address;
};

struct stPerson
{
    string FirstName;
    string LastName;
    stContactInfo ContactInfo;
    enGender Gender;
    enStatus MaritalStatus;
    enColor color;
};
int main()
{
    stPerson carlos;
    carlos.FirstName = "carlos";
    carlos.LastName = "costa";

    carlos.ContactInfo.Email = "xyz@xyz.com";
    carlos.ContactInfo.Phone = "+961000000999";
    carlos.ContactInfo.Address.POBox = "7777";
    carlos.ContactInfo.Address.ZipCode = "11194";
    carlos.ContactInfo.Address.StreetName = "Queen1 Street";
    carlos.ContactInfo.Address.BuildingNo = "313";
    carlos.Gender = enGender::Male;
    carlos.MaritalStatus = enStatus::Married;
    carlos.color = enColor::white;
    cout << carlos.FirstName << " " << carlos.LastName << endl;
    return 0;
}
