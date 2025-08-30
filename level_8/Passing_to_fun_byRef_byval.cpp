#include <iostream>
using namespace std;

class clsA {
    public:
        int z;
        void Print() {
            cout << "the value of z = " << z << endl;
        }

};

//passing by value

void ByVal(clsA a) {
    a.z = 102;
}

//passing by ref

void BYRef(clsA& a1 ) {
    a1.z = 50;

}


int main() {

    clsA A;
    A.z = 500;
    cout << "this is the initial value, before any operation: "<< A.z << endl;
    A.Print();

    ByVal(A);
    cout << "this is the result value, after Passing byval: " << A.z << endl;
    A.Print();

    BYRef(A);
    cout << "this is the result value, after Passing byref: " << A.z << endl;
    A.Print();

    return 0;

}