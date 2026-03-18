#include <iostream>
#include "LinkedList.h"
#include "Node.h"

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(Node *head){
    this->head = head;
}

void LinkedList::prependNode(void *data){
    Node *newNode = new Node();
    newNode->setNextNode(head);
    newNode->setMemberData(data);
    head = newNode;
}

void LinkedList::deleteNode(void *data){
    Node* travel = head;
    Node* trail = head->getNextNode();

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

void LinkedList::appendNode(void *data) {
    Node *newNode = new Node();
    newNode->setMemberData(data);
    newNode->setNextNode(nullptr);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node *travel = head;
        while (travel->getNextNode() != nullptr) {
            travel = travel->getNextNode();
        }
        travel->setNextNode(newNode);
    }
}

void LinkedList::purge(){
    while(head != nullptr){
        Node *travel = head;
        head = head->getNextNode();
        delete travel;
    }

    if(head == nullptr){
        std::cout << "PURGE SUCCESSFUL.\n";
    }
}

void LinkedList::display(){
    Node* travel = head;

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

void LinkedList::copy(LinkedList other){
    head = nullptr;
    Node* current = other.head;
    while (current){
        appendNode(current->getMemberData());
        current = current->getNextNode();
    }
}

void LinkedList::insert(void *value, int (*func)(void *a, void *b)){
    Node *newNode = new Node();
    newNode->setMemberData(value);

    if(head == nullptr || func(newNode->getMemberData(), head->getMemberData()) <= 0){
        newNode->setNextNode(head);
        head = newNode;
    } else {
        Node *travel = head;
        Node *trail = nullptr;

        while(travel != nullptr && func(travel->getMemberData(), newNode->getMemberData()) < 0){
            trail = travel;
            travel = travel->getNextNode();
        }
        trail->setNextNode(newNode);
        newNode->setNextNode(travel);
    }
}

void LinkedList::setDisplay(void (*displayFunc)(void *)){
    Node *travel = head;

    while(travel != nullptr){
        travel->setFunction(displayFunc);
        travel = travel->getNextNode();
    }
}

// LinkedList &LinkedList::operator=(const LinkedList &other){

//     if(this->head != other.head){
        
//     }
    
// }

LinkedList::~LinkedList(){ }
