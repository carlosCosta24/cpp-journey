#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDblLinkedList {
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
    }
    void DeleteLastNode() {
       if (Head == NULL) {
           return;
       }
       if (Head->Next == NULL) {
           delete Head;
           Head = NULL;
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
    }
};



