#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

void Fibonacci(short n,short Prev1,short Prev2) {
    short Curr=0;
    if(n > 0) {
        Curr = Prev1 + Prev2;
        Prev2 = Prev1;
        Prev1 = Curr;
        cout << Curr << " ";
        Fibonacci(n-1,Prev1,Prev2);
    }
}

int main() {
    short n;
    cout << "Enter number to print fibonacci: ";
    cin >> n;
    Fibonacci(n,0,1);
    return 0;
}