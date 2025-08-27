#include <iostream>
using namespace std;

class clsA {
    public:
    static int function1() {
        return 27;
    }
    int function2() {
        return 20;
    }
};


int main() {
    // calling the static function via the class directly
    // at class level you can call static methods and members
    cout << clsA::function1() << endl;
    // also we can call through the object it self
    clsA B1, B2;
    cout << B1.function1()<< endl;
    cout << B1.function2()<< endl;
    cout << B2.function1()<< endl;
    return 0;

}