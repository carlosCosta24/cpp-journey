# pragma once
#include "clsDynamicArray.h"
#include <iostream>
using namespace std;

template<class T> class clsMyQueueArr{
    protected:
    clsDynamicArray<T> _MyList;
    public:
    void Push(T Value) {
        _MyList.InsertAtEnd(Value);
    }
    void Pop() {
        _MyList.DeleteFirstItem();
    }
    T Front() {
        return  _MyList.GetItem(0);
    }
    T Back() {

        return _MyList.GetItem(Size() - 1);
    }
    int Size() {
        return _MyList.Size();
    }
    void Print() {
        _MyList.PrintList();
    }
    void Reverse() {
        _MyList.Reverse();
    }
    void UpdateItem(int Index , T Value) {
        _MyList.InsertAt(Index, Value);
    }
    void InsertAtFront(T Value) {
        _MyList.InsertArBegin(Value);
    }
    void InsertAtBack(T Value) {
        _MyList.InsertAtEnd(Value);
    }
    void Clear() {
        _MyList.Clear();
    }
    void InsertAfter(int Index, T Value) {
        _MyList.InsertAfter(Index, Value);
    }
    T GetItem(int Index) {
        return _MyList.GetItem(Index);
    }
    bool IsEmpty() {
        return _MyList.IsEmpty();
    }
};