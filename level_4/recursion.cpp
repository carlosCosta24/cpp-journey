#include <iostream>
using namespace std;

void PrintNumber(int A, int B) {

    if (A<= B) {
        cout << A << endl;
        PrintNumber(A+1, B);
    }
}
// always make sure to consider the callstack size
int main() {
    PrintNumber(1, 6);
    return 0;
}