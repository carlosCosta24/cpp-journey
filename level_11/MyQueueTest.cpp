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
    cout << "List Items: "<< endl;
    myQueue.Print();
    cout << endl;

    cout << "Pop the first item: " <<endl;
    myQueue.Pop();
    myQueue.Print();
    cout << endl;

    cout << "Queue Front: " << myQueue.Front() << endl;
    cout << "Queue Back: " << myQueue.Back() << endl;
    cout << "Queue Size: "<< myQueue.Size() << endl;

    cout << "Item on the 2 Index: ";
    cout << myQueue.GetItem(1)  << endl;

    cout << "Reversing the queue: ";
    myQueue.Reverse();
    myQueue.Print();
    cout << endl;

    cout << "Updating the first item: ";
    myQueue.UpdateItem(0,500);
    myQueue.Print();
    cout << endl;

    cout << "Inserting after the first item: ";
    myQueue.InsertAfter(1,700);
    myQueue.Print();
    cout << endl;

    cout << "Inserting at the beginning: ";
    myQueue.InsertAtFront(600);
    myQueue.Print();
    cout << endl;

    cout << "Inserting at the end: ";
    myQueue.InsertAtBack(400);
    myQueue.Print();
    cout << endl;

    cout << "Clearing the queue : ";
    myQueue.Clear();
    myQueue.Print();
    return 0;

}