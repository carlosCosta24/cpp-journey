#pragma once
#include <iostream>
#include "clsMyQueueArr.h"
using namespace std;

template<class T>
class clsMyStackArr : public clsMyQueueArr<T>
{
public:
    void Push(T Item) {
        clsMyQueueArr<T>::_MyList.InsertArBegin(Item);
    };
    T Top(){
        return clsMyQueueArr<T>::Front();
    };
    T Bottom(){
        return clsMyQueueArr<T>::Back();
    };
};