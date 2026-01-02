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

    MyDaynamicArray.PrintList();



}