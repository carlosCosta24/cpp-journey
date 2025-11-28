#include <iostream>
using namespace std;

class Node {
    public:
    int Data;
    Node* Next;
};

int main() {
    Node* Head;

    Node* FirstNode  = NULL;
    Node* SecondNode = NULL ;
    Node* ThirdNode  = NULL;

    FirstNode = new Node();
    SecondNode = new Node();
    ThirdNode = new Node();

    FirstNode->Data = 10;
    SecondNode->Data = 20;
    ThirdNode->Data = 40;

    FirstNode->Next = SecondNode;
    SecondNode->Next = ThirdNode;
    ThirdNode->Next = NULL;

    Head = FirstNode;

    //Print the Linked List content
    while (Head != NULL) {

        cout << Head->Data << endl;
        Head = Head->Next;
    }

    return 0;

}