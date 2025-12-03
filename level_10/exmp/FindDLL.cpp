#include <iostream>
using namespace std;

class Node {
public:
    int Data;
    Node* Next;
    Node * Prev;
};

void PrintLinkedList(Node * Head) {
    while (Head != NULL) {

        cout << Head->Data << endl;
        Head = Head->Next;
    }
}
Node * Find(Node * Head, int Target ) {

    while (Head != NULL ) {
        if (Head->Data == Target) {
            cout << "Target found: " << endl;
            cout << Head->Data << endl;
            return Head;
        }
        cout << "searching...."<<endl;
        Head = Head->Next;
    }
    cout << "Target not found" << endl;
    return NULL;
}

void InsertAtBeginningDLL(Node* &head, int data) {
    // creat a new node
    // assign value to the node
    // Set the next pointer of the new node to the current head of the list.
    // Set the previous pointer of the current head to the new node.
    // Set the new node as the new head of the list.
    Node * New = new Node();
    New->Data = data;
    New->Next = head;
    New->Prev = NULL;

    if (head != NULL) {
        head->Prev = New;
    }
    head = New;
}

int main() {
    Node * Head = NULL;
    InsertAtBeginningDLL(Head, 100);
    InsertAtBeginningDLL(Head, 90);
    InsertAtBeginningDLL(Head, 80);
    InsertAtBeginningDLL(Head, 70);
    InsertAtBeginningDLL(Head, 60);
    InsertAtBeginningDLL(Head, 50);

    PrintLinkedList(Head);

    Find(Head, 100);
    return 0;
}