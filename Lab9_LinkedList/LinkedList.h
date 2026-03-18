#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"

class LinkedList {
public:
    LinkedList();
    LinkedList(Node *head);

    void prependNode(void *data);
    void deleteNode(void *data);
    void appendNode(void *data);
    void purge();
    void display();
    void copy(LinkedList other);
    void insert(void *value, int (*func)(void *a, void *b));
    void setDisplay(void (*displayFunc)(void *));
    LinkedList &operator=(const LinkedList &other);


    ~LinkedList();

private:
    Node *head;
};


#endif