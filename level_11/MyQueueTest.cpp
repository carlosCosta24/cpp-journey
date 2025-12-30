#include <iostream>
#include "clsMyQueue.h"
using namespace std;

int main() {
    clsMyQueue<int> myQueue;

    myQueue.Push(1);
    myQueue.Push(2);
    myQueue.Push(3);
    myQueue.Push(4);
    cout << endl;

    myQueue.Print();
    cout << endl;

    myQueue.Pop();
    myQueue.Print();
    cout << endl;

    cout << "Queue Front: " << myQueue.Front() << endl;
    cout << "Queue Back: " << myQueue.Back() << endl;
    cout << "Queue Size: "<< myQueue.Size() << endl;
    return 0;

}