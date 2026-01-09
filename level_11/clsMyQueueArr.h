# pragma once
#include "clsDynamicArray.h"
#include <iostream>
using namespace std;

template<class T> class clsMyQueueArr : public clsDynamicArray<T>
{
    public:
    void Push(T Value) {
        clsDynamicArray<T>::InsertAtEnd(Value);
    }
    void Pop() {
        clsDynamicArray<T>::DeleteFirstItem();
    }
    void Front() {
        cout << clsDynamicArray<T>::GetItem(0);
    }
    void Back() {
        int End = clsDynamicArray<T>::_Size;
        cout << clsDynamicArray<T>::GetItem(End - 1);
    }
    void Size() {
        cout << clsDynamicArray<T>::Size();
    }
    void Print() {
        clsDynamicArray<T>::PrintList();
    }
    void Reverse() {
        clsDynamicArray<T>::Reverse();
    }
    void UpdateItem(int Index , T Value) {
        clsDynamicArray<T>::InsertAt(Index, Value);
    }
    void InsertAtFront(T Value) {
        clsDynamicArray<T>::InsertArBegin(Value);
    }
    void InsertAtBack(T Value) {
        clsDynamicArray<T>::InsertAtEnd(Value);
    }
    void Clear() {
        clsDynamicArray<T>::Clear();
    }
};