#pragma once
#include <iostream>
#include <stddef.h>

template <class T> class clsDblLinkedList {
private:
    struct Node{
        T Data;
        Node* Next;
        Node* Previous;
    };
    Node* Head;
    Node* Tail;
public:

    clsDblLinkedList(){
        Head = nullptr;
        Tail = nullptr;
    }
    void InsertAtBegin(T Value){
        Node * NewNode = new Node {Value, nullptr, nullptr};
        if (Head == nullptr) {
            Head = Tail = NewNode;
            return;
        }
        NewNode->Next = Head;
        Head->Previous = NewNode;
        Head = NewNode;

    };
    void PrintList(){
        Node * Temp = Head;
        while(Temp != nullptr){
            std::cout << Temp->Data << " ";
            Temp = Temp->Next;
        }
    }
    Node * Find(T Target) {
        Node * Temp = Head;
        while (Temp!= nullptr) {
            if (Temp-> Data == Target) {
                return Temp;
            }
            Temp = Temp->Next;
        }
        return nullptr;
    }
    void InsertAfter(Node * Target, T Value) {
        if (Target == nullptr) {
            return;
        }
        NewNode = new Node {Value, nullptr, nullptr};
        if (Target -> Next == nullptr) {
            //the new node will become the last node so it will be the tail
            Target-> Next = NewNode;
            NewNode -> Previous = Target;
            NewNode -> Next = nullptr;
            Tail = NewNode;
            return;
        }
        // inserting between to nodes
        Node * Temp = Target->Next;
        Target -> Next = NewNode;
        Temp-> Previous = NewNode;
        NewNode -> Next = Temp;
        NewNode -> Previous = Target;
    }
    void InsertAtEnd(T Value) {
        if (Head == nullptr) {
            NewNode = new Node {Value, nullptr, nullptr};
            Head = Tail = NewNode;
            return;
        }
        NewNode = new Node {Value, nullptr, nullptr};
        NewNode -> Next = nullptr;
        NewNode -> Previous = Tail;
        Tail-> Next = NewNode;
        Tail = NewNode;
    }
    void DeleteNode(Node * Target) {
        if (Target == nullptr) {
            return;
        }
        //One node case
        if (Target -> Previous == nullptr && Target -> Next == nullptr) {
            Head = Tail = nullptr;
            delete Target;
            Target = nullptr;
            return;
        }
        //Tail case
        if (Target -> Next == nullptr) {
            Target -> Previous -> Next = nullptr;
            Tail = Target -> Previous;
            delete Target;
            Target = nullptr;
            return;
        }
        //Head case
        if (Target -> Previous == nullptr) {
            Target -> Next -> Previous = nullptr;
            Head = Target -> Next;
            delete Target;
            Target = nullptr;
            return;
        }
        Target -> Previous -> Next = Target -> Next;
        Target -> Next -> Previous = Target -> Previous;
        delete Target;
        Target = nullptr;
    }
    void DeleteFirstNode(Node * Target) {
        if (Target == nullptr || Target -> Previous != nullptr ) {
            return;
        }
        // One node case
        if (Target -> Next == nullptr) {
            delete Target;
            Head = Tail = nullptr;
            return;
        }
        Target -> Next -> Previous = nullptr;
        Head = Target -> Next;
        delete Target;
        Target = nullptr;
    }
    void DeleteLastNode(Node * Target) {
        //Check if it is the tail and not a null
        if (Target == nullptr || Target -> Next != nullptr) {
            return;
        }
        // One Node list case
        if (Target -> Previous == nullptr && Target -> Next != nullptr) {
            Head = Tail = nullptr;
            delete Target;
            Target = nullptr;
            return;
        }

    }
};



