#include <iostream>
#include <string>
#include "IntNode.h"
#include "IntLinkedList.h"
using namespace std;

void menu(IntLinkedList &list);
void addNodeMenu(IntLinkedList &list);
void deleteNodeMenu(IntLinkedList &list);
void appendNodeMenu(IntLinkedList &list);
void purgeMenu(IntLinkedList &list);
void copyMenu(IntLinkedList &list);
void equalsOperatorMenu(IntLinkedList &list);
void reverseDisplayMenu(IntLinkedList &list);

int main(){
    IntLinkedList list;

    menu(list);

    return 0;
}

void menu(IntLinkedList &list){
    string userInput;

    while(userInput != "9"){
        cout << "\n\tMenu\n";
        cout << "----------------------\n";
        cout << "1 - Prepend Node\n2 - Append Node\n3 - Delete Node\n4 - Display\n5 - Purge\n6 - Copy\n7 - =\n8 - Exit\n";

        cout << "Enter: ";
        cin >> userInput;

        if (userInput == "1"){
            addNodeMenu(list);
        } else if (userInput == "2"){
            appendNodeMenu(list);
        } else if (userInput == "3"){
            deleteNodeMenu(list);
        } else if (userInput == "4"){
            list.display();
        } else if(userInput == "5"){
            purgeMenu(list);
        } else if(userInput == "6"){
            copyMenu(list);
        } else if(userInput == "7"){
            equalsOperatorMenu(list);
        } else if(userInput == "8"){
            reverseDisplayMenu(list);
        }
    }
}

void addNodeMenu(IntLinkedList &list){
    string userInput;

    cout << "Enter a number to add to the back of the list: ";
    cin >> userInput;

    list.prependNode(stoi(userInput));
}

void deleteNodeMenu(IntLinkedList &list){
    string userInput;

    cout << "Enter a number to delete: ";
    cin >> userInput;

    list.deleteNode(stoi(userInput));
}

void appendNodeMenu(IntLinkedList &list){
    string userInput;

    cout << "Enter a number to add to the end of the list: ";
    cin >> userInput;

    list.appendNode(stoi(userInput));
}

void purgeMenu(IntLinkedList &list){
    string userInput;

    cout << "Are you sure you want to purge all Nodes? [Y/N]: ";
    cin >> userInput;

    if(userInput == "Y"){
        list.purge();
    }
}

void copyMenu(IntLinkedList &list){
    IntLinkedList copyList(list);

    copyList.copy(list);
    cout << "Original list: ";
    list.display();
    cout << "Copy list: ";
    copyList.display();
}

void equalsOperatorMenu(IntLinkedList &list){
    IntLinkedList otherList;

    otherList.appendNode(5);
    otherList.appendNode(10);

    list = otherList;
}

void reverseDisplayMenu(IntLinkedList &list){
    list.prependNode(1);
    list.prependNode(2);
    list.prependNode(3);// 3 2 1

    list.reverseDisplay(list);
}