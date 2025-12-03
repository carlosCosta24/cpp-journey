#include <iostream>
using namespace std;

class Node {
public:
    int Data;
    Node* Next;
    Node * Prev;
};

void InsertAtEndDLL(Node* &head, int data) {

    //Create a new node with desired value
    Node* New = new Node();
    New->Data = data;
    New->Next = NULL;
    //Set the next of the new node to NULL
    //Check if the linked list is empty
    if (head == NULL) {
        New->Prev = NULL;
        head = New;
        return;
    }
    else {
        // Traverse the linked list until the last node
        Node * Current = head;
        while (Current->Next != NULL) {
            Current = Current->Next;
        }
        Current->Next = New;
        New->Prev = Current;
    }
}

void PrintList(Node* head)
{
    cout << "NULL <--> ";
    while (head != NULL) {
        cout << head->Data << " <--> ";
        head = head->Next;
    }
    cout << "NULL";

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
    InsertAtBeginningDLL(Head, 5);
    InsertAtBeginningDLL(Head, 4);
    InsertAtBeginningDLL(Head, 3);
    InsertAtBeginningDLL(Head, 2);
    InsertAtBeginningDLL(Head, 1);
    cout << "Before Insertion: ";
    PrintList(Head);
    cout << endl;
    InsertAtEndDLL(Head, 6);
    cout << "After Insertion: ";
    PrintList(Head);
}