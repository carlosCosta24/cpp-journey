#include <iostream>
#include <vector>
using namespace std;

class clsA {
  public:
    int x;
    clsA(int Value) {
        x = Value;
    }
    void Print() {
        cout << "Value of x: "<< x << endl;
    }
};

int main() {
    vector<clsA> vec;
    short NumberOfObj = 10;

    //adding obj to the vector
    for (int i = 0; i < NumberOfObj; i++) {
        vec.push_back(clsA(i));
    }

    //print the vector content

    for (int i =0 ; i < NumberOfObj ; i++) {
        vec[i].Print();
    }
    return 0;


}
