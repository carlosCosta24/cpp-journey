#include <iostream>
using namespace std;
struct Id
{
    string name;
    short age;
    string city;
    string country;
    double monthly_salary;
    double yearly_salary;
    char gender;
    bool is_married;
};
int main()
{
    Id carlos_id;
    carlos_id.name = "carlos costa ";
    carlos_id.age = 26;
    carlos_id.city = "aracaju";
    carlos_id.country = "brazil";
    carlos_id.monthly_salary = 10000;
    carlos_id.yearly_salary = carlos_id.monthly_salary * 12;
    carlos_id.gender = 'M';
    carlos_id.is_married = 0;
    cout << "*********************************" << endl;
    cout << "name: " << carlos_id.name << endl;
    cout << "age: " << carlos_id.age << endl;
    cout << "city: " << carlos_id.city << endl;
    cout << "country: " << carlos_id.country << endl;
    cout << "monthly_salary: " << carlos_id.monthly_salary << endl;
    cout << "yearly_salary: " << carlos_id.yearly_salary << endl;
    cout << "gender: " << carlos_id.gender << endl;
    cout << "is_married: " << carlos_id.is_married << endl;
    cout << "*********************************" << endl;

    return 0;
}