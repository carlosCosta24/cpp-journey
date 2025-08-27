#include <iostream>
using namespace std;

class clsA {
    public:
    int Number;
    static short Counter;

    clsA() {
        Counter ++;
    }

    void Printer() {
        cout <<"\n this is Number: " <<Number << endl;
        cout <<"\n this is Counter: " <<Counter << endl;

    }
};
// when class contain a static member we should initiate it outside the class and link them to be accessible.
short clsA::Counter = 0;

int main() {
    clsA First, Second, Third;

    First.Number = 10;
    Second.Number = 50;
    Third.Number = 40;

    First.Printer();
    Second.Printer();
    Third.Printer();

    // also when any obj edit a static var, the edit reflect on all obj
    cout << "\nafter changing the static member counter in one object:\n";

    Second.Counter = 12;
    First.Printer();
    Third.Printer();

    return 0;

}