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

void DeleteNode(Node * & Head, int Target){
	Node * Prev = Head;
	Node * Current = Head;

	if(Head == NULL){
		return;
	}
	if(Current->Data == Target){
		Head = Current->Next;
		delete Current;
		return;

	}
	while(Current != NULL && Current->Data != Target){
		Prev = Current;
		Current = Current->Next;
	}

	if(Current == NULL){
		cout << "Value dose not exist "<< "( " << Target << " )" << endl;
		return;
	}
	Prev->Next = Current->Next;
	delete Current;

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
	DeleteNode(Head, 30);
	cout << "-------------------------------" << endl;
	cout << "processed List" << endl;
	cout << "-------------------------------" << endl;

	PrintList(Head);

}