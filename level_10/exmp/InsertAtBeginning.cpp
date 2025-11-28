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

int main() {

    Node* Head = NULL;

    InsertAtBeginning(Head, 80);
    InsertAtBeginning(Head, 70);
    InsertAtBeginning(Head, 60);
    InsertAtBeginning(Head, 50);
    InsertAtBeginning(Head, 40);

    PrintList(Head);
    return 0;

}