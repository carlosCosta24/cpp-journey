#include <iostream>
#include <queue>
using namespace std;

int main() {

    queue<int> Q1;
    queue<int> Q2;

    Q1.push(100);
    Q1.push(80);
    Q1.push(60);
    Q1.push(40);
    Q1.push(20);

    Q2.push(200);
    Q2.push(180);
    Q2.push(160);
    Q2.push(140);
    Q2.push(120);

    Q2.swap(Q1);

    cout << "Size of Queue 1: " <<Q1.size() << endl;
    cout << endl;


    while (!Q1.empty()) {
        cout << "\nElement Number: " << Q1.size() << endl;
        cout << Q1.front() << " " << endl;
        Q1.pop();
    }

    cout << "Size of Queue 2: " <<Q2.size() << endl;
    cout << endl;


    while (!Q2.empty()) {

        cout << "\nElement Number: " << Q2.size() << endl;
        cout << Q2.front() << " "<< endl;
        Q2.pop();
    }
    return 0;
}