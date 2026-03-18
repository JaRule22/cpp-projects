#ifndef INT_LINKED_LIST_H
#define INT_LINKED_LIST_H
#include "IntNode.h"

class IntLinkedList {
public:
    IntLinkedList();
    IntLinkedList(IntNode *head);

    void prependNode(int data);
    void deleteNode(int data);
    void appendNode(int data);
    void purge();
    void display();
    void copy(IntLinkedList other);
    IntLinkedList &operator=(const IntLinkedList &other);
    void reverseDisplay(const IntLinkedList list);


    ~IntLinkedList();

private:
    // int data;
    IntNode *head;
};


#endif