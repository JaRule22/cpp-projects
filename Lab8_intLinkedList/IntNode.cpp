#include <iostream>
#include "IntNode.h"

IntNode::IntNode(){
    memberData = 0;
    nextNode = nullptr;
}

IntNode::IntNode(int memberData, IntNode *nextNode){
    this->memberData = memberData;
    this->nextNode = nextNode;
}

void IntNode::setMemberData(int memberData) {
    this->memberData = memberData;
}

void IntNode::setNextNode(IntNode *nextNode) {
    this->nextNode = nextNode;
}

int IntNode::getMemberData() const{
    return memberData;
}

IntNode* IntNode::getNextNode() const{
    return nextNode;
}

void IntNode::display(){
    std::cout << memberData << "->";

}

IntNode::~IntNode(){ }