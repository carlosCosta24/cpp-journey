#include <iostream>
#include "clsDynamicArray.h"
using namespace std;

int main() {
    clsDynamicArray<int> MyDaynamicArray(5);

    MyDaynamicArray.SetItem(0, 1);
    MyDaynamicArray.SetItem(1, 2);
    MyDaynamicArray.SetItem(2, 3);
    MyDaynamicArray.SetItem(3, 4);
    MyDaynamicArray.SetItem(4, 5);

    cout << "Is Empty: " << MyDaynamicArray.IsEmpty() << endl;
    cout << "Array Size: " << MyDaynamicArray.Size() << endl;
    cout << "Array Items: " ; MyDaynamicArray.PrintList();


    MyDaynamicArray.InsertArBegin(200);
    cout << "Array items after Inserting 200 at Beginning: " << endl;
    cout << "Array Size: " << MyDaynamicArray.Size() << endl;
    cout << "Array Items : " ; MyDaynamicArray.PrintList();

    MyDaynamicArray.InsertBefore(1, 500);
    cout << "Array items after Inserting 500 before index 1: " << endl;
    cout << "Array Size: " << MyDaynamicArray.Size() << endl;
    cout << "Array Items : " ; MyDaynamicArray.PrintList();

    MyDaynamicArray.InsertAfter(3, 600);
    cout << "Array items after Inserting 600 after index 3: " << endl;
    cout << "Array Size: " << MyDaynamicArray.Size() << endl;
    cout << "Array Items : " ; MyDaynamicArray.PrintList();

    MyDaynamicArray.InsertAtEnd(400);
    cout << "Array items after Inserting 400 at end: " << endl;
    cout << "Array Size: " << MyDaynamicArray.Size() << endl;
    cout << "Array Items : " ; MyDaynamicArray.PrintList();









}