#ifndef INT_NODE_H
#define INT_NODE_H

class IntNode {
public:
    IntNode();
    IntNode(int memberData, IntNode *nextNode);

    void setMemberData(int memberData);
    void setNextNode(IntNode *nextNode);
    int getMemberData() const;
    IntNode* getNextNode() const;
    void display();

    ~IntNode();

private:
    int memberData;
    IntNode *nextNode;
};

#endif