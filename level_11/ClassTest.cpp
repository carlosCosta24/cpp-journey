#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;

int main(){
    clsDblLinkedList<int> MyDblLinkedList;


    MyDblLinkedList.InsertAtBegin(5);
    MyDblLinkedList.InsertAtBegin(4);
    MyDblLinkedList.InsertAtBegin(3);
    MyDblLinkedList.InsertAtBegin(2);
    MyDblLinkedList.InsertAtBegin(1);

    cout << "Linked List Contents: " << endl;
    MyDblLinkedList.PrintList();
    cout << endl;

    clsDblLinkedList<int>::Node * N1 = MyDblLinkedList.Find(2);

    if(N1 != nullptr){
        cout<<"Node with value 2 was Found"<<endl;
    }else{
    cout << "Node with value 2 wasn't Found"<<endl;

    }
    cout << endl;

    MyDblLinkedList.InsertAfter(N1, 200);
    cout << "Linked list after inserting 200 after 2:" << endl;
    MyDblLinkedList.PrintList();
    cout << endl;

    MyDblLinkedList.InsertAtEnd(500);
    cout << "Linked list after inserting 500 at end:" << endl;
    MyDblLinkedList.PrintList();
    cout << endl;

    clsDblLinkedList<int>::Node * N2 = MyDblLinkedList.Find(4);

    MyDblLinkedList.DeleteNode(N2);
    cout << "Linked list after deleting 4:" << endl;
    MyDblLinkedList.PrintList();
    cout << endl;

    MyDblLinkedList.DeleteFirstNode();
    cout << "Linked list after deleting first node:" << endl;
    MyDblLinkedList.PrintList();
    cout << endl;

    MyDblLinkedList.DeleteLastNode();
    cout << "Linked list after deleting last node:" << endl;
    MyDblLinkedList.PrintList();

   cout << "The linkedlist size : " << MyDblLinkedList.Size();

    return 0;

}