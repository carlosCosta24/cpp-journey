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
void InsertAtBeginning(Node* &head, int data) {
    Node* newNode = new Node();

    newNode->Data = data;
    newNode->Next = head;

    head = newNode;
}
void DeleteFirstNode(Node * & Head){
    Node * Current = Head;
	if(Head == NULL){
	    cout << "Empty List" << endl;
		return;
	}
    Head = Current->Next;
    //always delete from the memory
    delete Current;
    return;


}

int main() {
    Node *Head = NULL;

    InsertAtBeginning(Head, 10);
    InsertAtBeginning(Head, 20);
    InsertAtBeginning(Head, 30);
    InsertAtBeginning(Head, 40);
    InsertAtBeginning(Head, 50);
    InsertAtBeginning(Head, 60);

    cout << "Before Deletion:" << endl;
    PrintList(Head);
    cout << "After Deletion:" << endl;
    DeleteFirstNode(Head);
    DeleteFirstNode(Head);
    DeleteFirstNode(Head);
    DeleteFirstNode(Head);
    PrintList(Head);
    return 0;
}