#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;

int main(){
    clsDblLinkedList<int> MyDblLinkedList;

    if (MyDblLinkedList.IsEmpty()) {
        cout << "Linked List is Empty!!!" << endl;
        cout << "-----------------------------" << endl;
    }else {
        cout << "Linked List is Not Empty!!!"<< endl;
        cout << "-----------------------------" << endl;
    }

    MyDblLinkedList.InsertAtBegin(5);
    MyDblLinkedList.InsertAtBegin(4);
    MyDblLinkedList.InsertAtBegin(3);
    MyDblLinkedList.InsertAtBegin(2);
    MyDblLinkedList.InsertAtBegin(1);

    MyDblLinkedList.CLear();

    if (MyDblLinkedList.IsEmpty()) {
        cout << "Linked List is Empty!!!"<< endl;
        cout << "-----------------------------" << endl;
    }else {
        cout << "Linked List is Not Empty!!!"<< endl;
        MyDblLinkedList.PrintList();
        cout << "-----------------------------" << endl;
        cout << "Linked List Size : " << MyDblLinkedList.Size();
    }



    return 0;

}