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
            NewSize = 0 ;
        }
        TempArray = new T[NewSize];
        if (NewSize < _Size) {
            _Size = NewSize;
        }
        for (int i = 0; i < _Size; i++) {
            TempArray[i] = Array[i];
        }
        _Size = NewSize;
        delete [] Array;
        Array = TempArray;
    }
    T GetItem(int Index) {
        if (Index < 0 || Index >= _Size) {
            return T();
        }
        return Array[Index];
    }

    void Reverse() {
        if (_Size == 0 || _Size == 1) {
            return;
        }
        TempArray = new T[_Size];
        for (int i = _Size-1; i >=0; i--) {
             TempArray[i] = Array[_Size-1-i];
        }
        delete[] Array;
        Array = TempArray;;
    }
    void CLear() {
        _Size = 0;
        TempArray = new T[0];
        delete [] Array;
        Array = TempArray;
    }
    bool DeleteItemAt(int Index) {
        if (Index < 0 || Index >= _Size) {
            return false;
        }
        _Size --;
        TempArray = new T[_Size];

        for (int i = 0; i < Index; i++) {
            TempArray [i] = Array[i];
        }
        for (int i = Index + 1; i < _Size + 1; i++ ) {
            TempArray [i - 1] = Array[i];
        }
        delete [] Array;
        Array = TempArray;
        return true;
    }
    void DeleteFirstItem() {
        if (_Size == 0) {
            return;
        }
        DeleteItemAt(0);
    }
    void DeleteLastItem() {
        if (_Size == 0) {
            return;
        }
        DeleteItemAt(_Size - 1);
    }

};
