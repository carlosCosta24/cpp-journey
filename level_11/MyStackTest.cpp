#include <iostream>
#include "clsMyStack.h"
using namespace std;

int main() {
    clsMyStack<int> myStack;

    myStack.Push(1);
    myStack.Push(2);
    myStack.Push(3);
    myStack.Push(4);
    cout << endl;
    cout << "Stack Items: "<< endl;
    myStack.Print();
    cout << endl;

    cout << "Pop the first item: " <<endl;
    myStack.Pop();
    myStack.Print();
    cout << endl;

    cout << "Stack Front: " << myStack.Top() << endl;
    cout << "Stack Back: " << myStack.Bottom() << endl;
    cout << "Stack Size: "<< myStack.Size() << endl;

    cout << "Item on the 2 Index: ";
    cout << myStack.GetItem(1)  << endl;

    cout << "Reversing the Stack: ";
    myStack.Reverse();
    myStack.Print();
    cout << endl;

    cout << "Updating the first item: ";
    myStack.UpdateItem(0,500);
    myStack.Print();
    cout << endl;

    cout << "Inserting after the first item: ";
    myStack.InsertAfter(1,700);
    myStack.Print();
    cout << endl;

    cout << "Inserting at the beginning: ";
    myStack.InsertAtFront(600);
    myStack.Print();
    cout << endl;

    cout << "Inserting at the end: ";
    myStack.InsertAtBack(400);
    myStack.Print();
    cout << endl;

    cout << "Clearing the Stack : ";
    myStack.Clear();
    myStack.Print();
    return 0;
}