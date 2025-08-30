#include <iostream>
#include <vector>
using namespace std;

class clsA {
    public:
    int x;
    // dummy constractor
    clsA() {}
    //parameterized constructor
    clsA(int Value) {
        x = Value;
    }
    void Print() {
        cout << "The value of x is: "<< x<< endl;
    }
};

int main() {

    clsA obj[] = {clsA(15), clsA(25), clsA(40)};
    //printing the content of the arr

    for (int i =0; i < 3; i++) {
        obj[i].Print();

    }

    return 0;
}