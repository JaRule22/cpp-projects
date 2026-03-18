#include <iostream>
#include <cstring>
#include "Node.h"

Node::Node(){
    memberData = 0;
    nextNode = nullptr;
    func = nullptr;
}

Node::Node(void *memberData, Node *nextNode){
    this->memberData = memberData;
    this->nextNode = nextNode;
    func = nullptr;
}

void Node::setFunction(void(*func)(void *)){
    this->func = func;
}

void Node::setMemberData(void *memberData)
{
    this->memberData = memberData;
}

void Node::setNextNode(Node *nextNode) {
    this->nextNode = nextNode;
}

void *Node::getMemberData() const{
    return memberData;
}

Node* Node::getNextNode() const{
    return nextNode;
}

void Node::display(){
    if (func) {
        func(memberData);
    } else {
        std::cout << memberData << "->";
    }
}

Node::~Node(){ }