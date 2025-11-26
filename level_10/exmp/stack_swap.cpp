#include <iostream>
#include <stack>
using namespace std;

int main() {

    stack<int> stk1;
    stack<int> stk2;

    stk1.push(100);
    stk1.push(80);
    stk1.push(60);
    stk1.push(40);
    stk1.push(20);

    stk2.push(200);
    stk2.push(180);
    stk2.push(160);
    stk2.push(140);
    stk2.push(120);

    stk2.swap(stk1);

    cout << "Size of stack 1: " <<stk1.size() << endl;
    cout << endl;


    while (!stk1.empty()) {
        cout << "Element Number: " << stk1.size() << endl;
        cout << stk1.top() << endl;
        stk1.pop();
    }

    cout << "Size of stack 2: " <<stk2.size() << endl;
    cout << endl;


    while (!stk2.empty()) {

        cout << "Element Number: " << stk2.size() << endl;
        cout << stk2.top() << endl;
        stk2.pop();
    }
    return 0;
}