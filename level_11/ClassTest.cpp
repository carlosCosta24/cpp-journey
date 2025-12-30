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

    MyDblLinkedList.InsertAfter(1, 600);
    MyDblLinkedList.PrintList();

    return 0;

}