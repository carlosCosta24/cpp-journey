#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDblLinkedList{
private:
    struct Node{
        T data;
        Node* next;
        Node* previous;
    }
    Node* head;
    Node* tail;
public:

 clsDblLinkedList(){
   Head = * nullptr;
   Tail = * nullptr;
   };

void clsDblLinkedList(T Value){
    Node * New = new Node {Value, nullptr, nullptr};
    Head = New;
    Tail = New;
};

void InsertAtBegin(T Value){
    Node * New = new Node {Value, nullptr, nullptr};
    head . previous = NULL;
    New . next = head.next ;


}


}

