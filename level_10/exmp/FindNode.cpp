#include <iostream>
using namespace std;

class Node {
public:
    int Data;
    Node* Next;
};
void InsertAtBeginning(Node* &head, int data) {
    Node* newNode = new Node();

    newNode->Data = data;
    newNode->Next = head;

    head = newNode;
}
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

int main() {
    Node* Head = NULL;

    InsertAtBeginning(Head, 100);
    InsertAtBeginning(Head, 90);
    InsertAtBeginning(Head, 80);
    InsertAtBeginning(Head, 40);
    InsertAtBeginning(Head, 20);
    InsertAtBeginning(Head, 500);

    PrintList(Head);

    Node * N1 = Find(Head, 500);

    if (N1 != NULL) {
        cout << "Node Dose exist :-)" << endl;
        cout << N1->Data << endl;
    }else {
        cout << "Node Dose not existed :-(" << endl;
    }

}