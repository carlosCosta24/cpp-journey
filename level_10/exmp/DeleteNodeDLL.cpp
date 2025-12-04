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
            return Head;
        }
        Head = Head->Next;
    }
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

void DeleteDLL(Node*& head, Node*& Target ) {
    //is the LinkedList is empty
    if (head == NULL || Target == NULL) {
        return;
    }
    //is current is the only node
    if (head == Target) {
        head = Target->Next;
    }
    //set next of the current node
    if (Target->Next != NULL) {

        Target->Next->Prev = Target->Prev;
    }
    if (Target->Prev != NULL) {
        Target->Prev->Next = Target->Next;
    }
    delete Target;
}

int main() {
    Node * Head = NULL;
    InsertAtBeginningDLL(Head, 99);
    InsertAtBeginningDLL(Head, 98);
    InsertAtBeginningDLL(Head, 97);
    InsertAtBeginningDLL(Head, 96);
    InsertAtBeginningDLL(Head, 95);
    InsertAtBeginningDLL(Head, 94);
    cout << "Before Deletion" << endl;
    cout << "--------------------"<<endl;
    PrintLinkedList(Head);
    cout << "--------------------"<<endl;
    cout << "After Deletion" << endl;
    Node * Target = Find(Head, 96);
    DeleteDLL(Head, Target);
    cout << "--------------------"<<endl;
    PrintLinkedList(Head);
}