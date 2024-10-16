#ifndef _collatzLList
#define _collatzLList

#include "collatzNode.h"

class CollatzLinkedList {
    private:
        CollatzNode* m_head; // the current top of the linked list
        CollatzNode* m_currentNode; // current node selected in the linked list
        CollatzNode* m_tail; // the last node. this makes it easy to add things without traversing the entire list making appends faster, it would actually be 1 instead of n
        int m_nodeCount; // amount of nodes in the linked list, incremented every time one is added
    public:
        CollatzLinkedList(); // constructor
        ~CollatzLinkedList(); // deconstructor

        void AppendAtTail(int intPar); // makes new struct and inserts item at the end of the list (tail)
        void traverseToNextNode(); // sets current node to the next current node in line
        void traverseToHead(); // just moves the current to the head to start from the top
        void removeContent(); // removes everything returning it to its initial form

        bool isLastNode(); // determines wether the current node has a link destination to traverse to next
        int getItems();
        int getCurrentNodeItem(); // returns the integer stored in the current node
};

#endif