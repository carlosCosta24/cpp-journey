#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDblLinkedList {
protected:
    int _Size = 0;
public:
    class Node{
    public:
        T Data;
        Node* Next;
        Node* Previous;
    };
    Node* Head = NULL;

    void InsertAtBegin(T Value){
        Node * NewNode = new Node();
        NewNode->Data = Value;
        NewNode->Next = Head;
        NewNode->Previous = NULL;
        if (Head != NULL) {
            Head->Previous = NewNode;
        }
            Head = NewNode;
            _Size++;
    };
    void PrintList(){
        Node * Temp = Head;
        while(Temp != NULL){
            cout << Temp->Data << " ";
            Temp = Temp->Next;
        }
        cout << endl;
    }
    Node * Find(T Target) {
        Node * Temp = Head;
        while (Temp!= NULL) {
            if (Temp->Data == Target) {
                return Temp;
            }
            Temp = Temp->Next;
        }
        return NULL;
    }
    void InsertAfter(Node * Target, T Value) {
        if (Target == NULL) {
            return;
        }
        Node * NewNode = new Node();
        NewNode->Data = Value;
        NewNode->Next = Target->Next;
        NewNode->Previous = Target;
        if (Target->Next != NULL) {
            Target->Next->Previous = NewNode;
        }
        Target->Next = NewNode;
        _Size++;
    }
    void InsertAtEnd(T Value) {
        Node * NewNode = new Node();
        NewNode->Data = Value;
        NewNode->Next = NULL;
        if (Head == NULL) {
            NewNode->Previous = NULL;
            Head = NewNode;
        }
        else {
            Node * Temp = Head;
            while (Temp->Next != NULL) {
                Temp = Temp->Next;
            }
            Temp->Next = NewNode;
            NewNode->Previous = Temp;
            NewNode->Next = NULL;
        }
        _Size++;
    }
    void DeleteNode(Node *& Target) {
        if ( Head == NULL || Target == NULL) {
            return;
        }
        if (Head == Target) {

            Head = Target->Next;

        }
        if (Target -> Next != NULL) {

            Target->Next->Previous = Target->Previous;

        }
        //Head case
        if (Target -> Previous != NULL) {

            Target->Previous->Next = Target->Next;

        }
        delete Target;
        Target = NULL;
        _Size--;
    }
    void DeleteFirstNode() {
        if (Head == NULL) {
            return;
        }
        Node * Temp = Head;
        Head = Head->Next;
        if (Head != NULL) {
            Head->Previous = NULL;
        }
        delete Temp;
        Temp = NULL;
        _Size--;
    }
    void DeleteLastNode() {
       if (Head == NULL) {
           return;
       }
       if (Head->Next == NULL) {
           delete Head;
           Head = NULL;
           _Size = 0;
           return;
       }
        Node * Current = Head;
        while (Current->Next->Next != NULL) {
            Current = Current->Next;
        }
        Node * Temp = Current->Next;
        Current->Next = NULL;
        delete Temp;
        Temp = NULL;
        _Size--;
    }
    int Size() {
        return _Size;
    }
    bool IsEmpty() {
        return (_Size == 0 ? true: false) ;
    }
    void CLear() {
        while(_Size > 0){
            DeleteFirstNode();
        }
    }
    void Reverse() {
        Node * Current = Head;
        Node * Temp = nullptr;
        while (Current != nullptr) {
            Temp = Current->Previous;
            Current->Previous = Current->Next;
            Current->Next = Temp;
            Current = Current->Previous;
        }
        if (Temp != nullptr) {
            Head = Temp->Previous;
        }
    }
    Node* GetNode(T Index) {
        Node * Temp = Head;
        int i = 0;
        if (Index > _Size -1 || Index < 0) {

            return nullptr;
        }
        while (Temp != nullptr && i < Index) {
            Temp = Temp->Next;
            i ++;
        }
        return Temp;
    }
    T GetItem(int Index) {
        Node * Temp = GetNode(Index);
        if (Temp == nullptr) {
            return NULL;
        }
        return Temp->Data;
    }
};




