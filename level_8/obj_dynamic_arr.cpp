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
    short NumberOfObj = 8;

    // allocating dynamic array of size NumberOfObj using nue keyword
    clsA* arrA = new clsA[NumberOfObj];

    //calling the constructor for each index in the arr
    for (int i = 0; i < NumberOfObj; i++) {
        arrA[i] = clsA(i);
    }

    //printing the content of the arr

    for (int i =0; i < NumberOfObj; i++) {
        arrA[i].Print();

    }

    return 0;
}