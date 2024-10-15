#ifndef _collatzLList
#define _collatzLList

#include "collatzNode.h"

class CollatzLinkedList {
    private:
        CollatzNode* m_head; // the current top of the linked list
        CollatzNode m_currentNode; // m_ is member variable incase of confusion. I think it looks clean
        int m_nodeCount; // amount of nodes int he linked list, incremented every time one is added

        CollatzNode getCurrentNodeLink(); // gets the next node from the link pointer of the current node
    public:
        CollatzLinkedList(); // constructs a list

        void insertAtHead(int intPar); // makes new struct and inserts item at the head/top
        void traverseToNextNode(); // sets current node to the next current node in line

        int getCurrentNodeItem(); // returns the integer stored in the current node
};

#endif