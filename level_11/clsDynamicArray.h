#pragma once
#include<iostream>
using namespace std;

template<class T>
class clsDynamicArray{
    protected:
    T * TempArray;
    int _Size;

    public:
    T * Array;
    clsDynamicArray(int Size = 0) {
        if (Size < 0) {
            _Size = 0 ;
        }
        _Size = Size;
        Array = new T[_Size];
    }
    ~clsDynamicArray() {
        delete[] Array;
    }
    bool SetItem(int Index, T Item) {
         if (Index < 0 || Index >= _Size) {
             return false;
         };
        Array[Index] = Item;
        return true;
    }
    bool IsEmpty() {
        return ( _Size == 0? true: false);
    }
    int Size() {
        return  _Size;
    }
    void PrintList() {
         for (int i = 0; i < _Size; i++) {
             cout << Array[i] << " ";
         }
        cout << endl;
    }
    void Resize(int NewSize) {
        if (NewSize < 0) {
            _Size = 0 ;
            return ;
        }
        TempArray = new T[NewSize];
        if (NewSize < _Size) {
            _Size = NewSize;
            return;
        }
        for (int i = 0; i < _Size; i++) {
            TempArray[i] = Array[i];
        }
        _Size = NewSize;
        delete [] Array;
        Array = TempArray;
    }
};
