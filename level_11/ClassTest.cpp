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

    clsDblLinkedList<int> ::Node * N;
    N = MyDblLinkedList.GetNode(3);

    cout << MyDblLinkedList.GetItem(1);

    return 0;

}