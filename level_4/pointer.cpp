#include <iostream>
using namespace std;

struct stEmployee {
    string name;
    int age;
};

int main() {
    int a = 20;
    int b = 50;
    int arr[5] = {10,50,80,90};
    int * arP = arr;

    cout << "Variable value: " << a<< endl;
    cout << "variable reference: " << & a << endl;

    int * p = &a;

    cout<< "Pointer value: "<< p<< endl;
    cout<< "Pointer reference: "<< & p<< endl;
    cout<< "Value of Pointer reference: "<< * p<< endl;

    p = &b;

    cout << "The pointer after changing: "<< p << endl;
    cout << "The value of pointer after changing: "<< *p << endl;


    cout << "First element address in  array: " << arP << endl;
    cout << "First element in array using address: " << *arP << endl;

    stEmployee employee , *pEmp = &employee;

    employee.name = "Carlos costa";
    employee.age = 25;

    cout << employee.name << endl;
    cout << employee.age << endl;

    cout << "Using pointer to print structure elements: "<< endl;

    cout << pEmp->name << endl;
    cout << pEmp->age << endl;

    return 0;

}