#pragma once
#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;

template <class T>
class clsMyQueue {
    protected:
    clsDblLinkedList<T> _MyList;
    public:

    void Push(T Value) {
        _MyList.InsertAtEnd(Value);
    }
    void Pop() {
       _MyList.DeleteFirstNode();

    }
    T Front() {
       return _MyList.GetItem(0);
    }
    T Back() {
        return _MyList.GetItem(_MyList.Size() - 1);

    }
    int Size() {
        return _MyList.Size();
    }
    void Print() {
        _MyList.PrintList();
    }
    bool IsEmpty() {
        return _MyList.IsEmpty();
    }

};