#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

void Fibonacci(int n) {
    short Prev1=0;
    short Prev2=1;
    short Curr=0;
    cout << 1 << " ";
    for(int i = 2; i < n; i++) {
        Curr = Prev1 + Prev2;
        cout << Curr  << " ";
        Prev1 = Prev2;
        Prev2 = Curr;
    }
}

int main() {
    short n;
    do {
    cout << "Enter number to print fibonacci: ";
    cin >> n;
    } while (isdigit(n));
    Fibonacci(n);
    return 0;
}