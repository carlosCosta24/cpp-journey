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
void DeleteLastNodeDLL(Node* &head) {
    if (head == NULL) {
        return;
    }
    if (head->Next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    //find the second to last node
    Node * Current = head;

    while (Current->Next->Next != NULL) {
        Current = Current->Next;
    }
    Node * Temp = Current->Next;
    Current->Next = NULL;
    delete Temp;
    Temp = NULL;
}