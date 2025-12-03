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
void InsertAfter(Node *&Current , int value) {
    /*
    1-Create a new node with the desired value.
    2-Set the next pointer of the new node to the current head of the list.
    3-Set the previous pointer of the current head to the new node.
    4-Set the new node as the new head of the list.
*/
    Node * NewNode = new Node();
    NewNode->Data = value;
    NewNode->Next = Current->Next;
    NewNode->Prev = Current;
    if(Current->Next != NULL) {
        Current->Next->Prev = NewNode;
    }
    Current->Next = NewNode;
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

    InsertAtBeginningDLL(Head, 10);
    InsertAtBeginningDLL(Head, 9);
    InsertAtBeginningDLL(Head, 8);
    InsertAtBeginningDLL(Head, 7);
    InsertAtBeginningDLL(Head, 6);
    cout << "--------------------------"<<endl;
    PrintLinkedList(Head);
    cout << endl;
    cout << "--------------------------"<<endl;
    Node * Target = Find(Head, 8);
    InsertAfter(Target, 98);
    cout << "--------------------------"<<endl;
    PrintLinkedList(Head);
}