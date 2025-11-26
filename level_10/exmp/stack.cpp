#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> stkIntegers;
    stkIntegers.push(20);
    stkIntegers.push(40);
    stkIntegers.push(60);
    stkIntegers.push(80);
    stkIntegers.push(100);
    stkIntegers.push(120);


    cout << "Size of stack: " <<stkIntegers.size() << endl;


    while (!stkIntegers.empty()) {

        cout << "Element Number: " << stkIntegers.size() << endl;
        cout << stkIntegers.top() << endl;
        stkIntegers.pop();
    }

    return 0;

}