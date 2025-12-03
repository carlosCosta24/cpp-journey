#include <iostream>
using namespace std;

class Node {
public:
    int Data;
    Node* Next;
};
void PrintList(Node *Head) {

    while (Head != NULL) {

        cout << Head->Data << endl;
        Head = Head->Next;
    }
}

void InsertAtEnd(Node * & Head,int Value) {

    // creat a nww node
    Node * NewNode = new Node();
    NewNode->Data = Value;
    NewNode->Next = NULL;

    //check if the linkedlist is empty
    if (Head == NULL) {
        Head = NewNode;
        return;
    }
    //find the last node
    Node * Last = Head;
    while (Last->Next != NULL ) {
        Last = Last->Next;
    }
    Last->Next = NewNode;
    return;
}

void DeleteLastNode(Node * & Head){
    Node * Current = Head;
    Node * Prev = Head;
    if(Head == NULL){
        cout << "Linked List is empty " << endl;
        return;
    }
    if(Current->Next == NULL){
        Head = NULL;
        delete Current;
        return;
    }
    while(Current != NULL && Current->Next != NULL){
        Prev = Current;
        Current = Current->Next;
    }
    Prev->Next = NULL;
    delete Current;
    return;
}


int main() {

    Node *Head = NULL;

    InsertAtEnd(Head, 10);
    InsertAtEnd(Head, 20);
    InsertAtEnd(Head, 30);
    cout << "Unprocessed List" << endl;
    cout << "-------------------------------" << endl;
    PrintList(Head);
    cout << "-------------------------------" << endl;
    DeleteLastNode(Head);
    cout << "-------------------------------" << endl;
    cout << "processed List" << endl;
    cout << "-------------------------------" << endl;
    PrintList(Head);

}