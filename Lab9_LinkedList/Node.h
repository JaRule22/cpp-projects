#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node();
    Node(void *memberData, Node *nextNode);

    //set void* to whatever it gets passed
    void setFunction(void(*func)(void *));
    void setMemberData(void* memberData);
    void setNextNode(Node *nextNode);
    void *getMemberData() const;
    Node* getNextNode() const;
    void display();

    ~Node();

private:
    void *memberData;
    Node *nextNode;
    void (*func)(void *);
};

#endif