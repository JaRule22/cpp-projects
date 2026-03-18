#include <iostream>
#include <cstring>
#include "IntLinkedList.h"
#include "IntNode.h"

IntLinkedList::IntLinkedList() : head(nullptr) {}

IntLinkedList::IntLinkedList(IntNode *head){
    this->head = head;
}

void IntLinkedList::prependNode(int data){
    IntNode *newNode = new IntNode();
    newNode->setNextNode(head);
    newNode->setMemberData(data);
    head = newNode;
}

void IntLinkedList::deleteNode(int data){
    IntNode* travel = head;
    IntNode* trail = head->getNextNode();

    if(travel->getNextNode() == 0x0){ //If list is empty
        std::cout << "There is nothing.\n";
    } else if(data == travel->getMemberData()) { //If head's key is equal to target value
        head = travel;
        head = head->getNextNode();
        delete travel;
    } else {
        head = travel;
        while(travel != nullptr && travel->getMemberData() != data){
            trail = travel;
            travel = travel->getNextNode();
        }

        if(travel == nullptr){
            std::cout << "Error\n";
        } else {
            trail->setNextNode(travel->getNextNode());
            delete travel;
        }
    }
}

void IntLinkedList::appendNode(int data) {
    IntNode *newNode = new IntNode();
    newNode->setMemberData(data);
    newNode->setNextNode(nullptr);

    if (head == nullptr) {
        head = newNode;
    } else {
        IntNode *travel = head;
        while (travel->getNextNode() != nullptr) {
            travel = travel->getNextNode();
        }
        travel->setNextNode(newNode);
    }
}

void IntLinkedList::purge(){
    while(head != nullptr){
        IntNode *travel = head;
        head = head->getNextNode();
        delete travel;
    }

    if(head == nullptr){
        std::cout << "PURGE SUCCESSFUL.\n";
    }
}

void IntLinkedList::display(){
    IntNode* travel = head;

    if(travel == nullptr){
        std::cout << "List is empty" << std::endl;
        return;
    }

    while(travel != nullptr){
        travel->display();
        travel = travel->getNextNode();
    }
    std::cout << std::endl;
}

void IntLinkedList::copy(const IntLinkedList other){
    head = nullptr;
    IntNode* current = other.head;
    while (current != nullptr){
        appendNode(current->getMemberData());
        current = current->getNextNode();
    }
}

IntLinkedList &IntLinkedList::operator=(const IntLinkedList &other){

    //operator=: LinkedList1 [1 2 3], LinkedList2 [4 5 6]: List1 = list2 -> list1 = [4 5 6]
    if(this != &other) {
        // Clear list1
        purge();
        if(other.head != nullptr){
            IntNode* current = other.head;

        //copy the other list
            while (current != nullptr) {
                appendNode(current->getMemberData());
                current = current->getNextNode();
            }//set head -> nullptr
        } else {
            head = nullptr;
        }
    }
    return *this;
}

void IntLinkedList::reverseDisplay(const IntLinkedList list){
    IntNode* current = head;
    if(current != nullptr){
        reverseDisplay(current->getNextNode());
    }

    std::cout << current->getMemberData() << std::endl;
}

IntLinkedList::~IntLinkedList(){ }
