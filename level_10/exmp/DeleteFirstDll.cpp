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
void DeleteFirstDLL(Node* &head) {
    //check if linked list is empty
    if (head == NULL) {
        return;
    }
    Node * Temp = head;
    head = head->Next;
    if (head != NULL) {
        head->Prev = NULL;
    }
    delete Temp;
    Temp = NULL;

}

int main() {
    Node* Head = NULL;

    InsertAtBeginningDLL(Head,9);
    InsertAtBeginningDLL(Head,8);
    InsertAtBeginningDLL(Head,7);
    cout << "Before DeleteFirst Node:" << endl;
    cout << "==============" << endl;
    PrintLinkedList(Head);
    DeleteFirstDLL(Head);
    cout << "After DeleteFirst Node:" << endl;
    cout << "==============" << endl;
    PrintLinkedList(Head);

}