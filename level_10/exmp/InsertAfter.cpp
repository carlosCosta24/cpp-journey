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
Node * Find(Node *Head, int Target) {
    while (Head != NULL) {
        if (Head->Data == Target) {
            return Head;
        }
        Head = Head->Next;
    }
    return NULL;
}

void InsertAfter(Node * &Head,int Value) {

    //find the value to insert after
    if (Head == NULL) {
        cout << "Invalid Header" << endl;
        return;
    }
    //creat new node with the value provided
    Node * NewNode = new Node();
    //let the pointer of the founded value equal to the nww node
    NewNode->Data = Value;
    NewNode->Next = Head->Next;
    //let the pointer of the founded value equal current node
    Head->Next = NewNode;
}
void InsertAtBeginning(Node* &head, int data) {
    Node* newNode = new Node();

    newNode->Data = data;
    newNode->Next = head;

    head = newNode;
}
int main() {
    Node *Head = NULL;

    InsertAtBeginning(Head, 10);
    InsertAtBeginning(Head, 20);
    InsertAtBeginning(Head, 30);
    cout << "Before Inserting:" << endl;
    PrintList(Head);
    cout << "After Inserting:" << endl;
    Node * InsertionPoint = Find(Head, 20);
    InsertAfter(InsertionPoint, 500);
    PrintList(Head);
    return 0;
}