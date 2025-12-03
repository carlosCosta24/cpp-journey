#include <iostream>
using namespace std;

class Node {
public:
    int Data;
    Node* Next;
    Node * Prev;
};

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

void PrintNodeDetails(Node * Head) {
    if (Head->Prev != NULL)
        cout << Head->Prev->Data;
    else
        cout << "NULL";

    cout << " <--> " << Head->Data << " <--> ";

    if (Head->Next != NULL)
        cout << Head->Next->Data << "\n";
    else
        cout << "NULL";

}

void PrintLinkedList(Node * Head) {
    while (Head != NULL) {

        PrintNodeDetails(Head);
        Head = Head->Next;
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

int main() {

    Node* Head = NULL;

    InsertAtBeginningDLL(Head, 5);
    InsertAtBeginningDLL(Head, 4);
    InsertAtBeginningDLL(Head, 3);
    InsertAtBeginningDLL(Head, 2);
    InsertAtBeginningDLL(Head, 1);
    PrintList(Head);
    cout << endl << endl;
    PrintLinkedList(Head);

    return 0;

}