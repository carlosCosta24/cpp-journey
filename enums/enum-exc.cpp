#include <iostream>
using namespace std;

enum genders
{
    Male,
    Female,
};
enum status
{
    Single,
    Married,
};
struct Id
{
    string name;
    short age;
    string city;
    string country;
    double monthly_salary;
    double yearly_salary;
    genders gender;
    status is_married;
};

int main()
{
    Id carlos_id;
    genders my_gender;
    status is_marred;
    my_gender = genders::Male;
    is_marred = status::Single;
    carlos_id.name = "carlos costa ";
    carlos_id.age = 26;
    carlos_id.city = "aracaju";
    carlos_id.country = "brazil";
    carlos_id.monthly_salary = 10000;
    carlos_id.yearly_salary = carlos_id.monthly_salary * 12;
    carlos_id.gender = my_gender;
    carlos_id.is_married = is_marred;

    string gender_str = (carlos_id.gender == Male) ? "Male" : "Female";
    string is_married_str = (carlos_id.is_married == Single) ? "single" : "married";

    cout << "*********************************" << endl;
    cout << "name: " << carlos_id.name << endl;
    cout << "age: " << carlos_id.age << endl;
    cout << "city: " << carlos_id.city << endl;
    cout << "country: " << carlos_id.country << endl;
    cout << "monthly_salary: " << carlos_id.monthly_salary << endl;
    cout << "yearly_salary: " << carlos_id.yearly_salary << endl;
    cout << "gender: " << gender_str << endl;
    cout << "is_married: " << is_married_str << endl;
    cout << "*********************************" << endl;

    return 0;
}