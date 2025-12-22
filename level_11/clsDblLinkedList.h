#pragma once
#include <iostream>

template <class T> class clsDblLinkedList {
private:
    struct Node{
        T data;
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
            std::cout << Temp->data << " ";
            Temp = Temp->Next;
        }
    }
};



