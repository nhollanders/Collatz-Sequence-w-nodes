
#include "collatzLList.h"
#include "collatzNode.h"

using namespace std;

CollatzLinkedList::CollatzLinkedList() // constructor
{
    m_head = nullptr;
    m_tail = nullptr;
    m_currentNode = nullptr;
    m_nodeCount = 0;
}

// when the list gets deconstructed the actual nodes are sorta just floating so we need to get rid of them when the list gets deconstructed
CollatzLinkedList::~CollatzLinkedList() // deconstructor
{
    CollatzNode* temp;
    while ( m_head != nullptr ) // basically frees all the dynamic memory the linked list was taking up
    {
        traverseToHead();
        temp = m_head;
        m_head = m_head -> link;
        delete temp;
    }
}

// return the int stored on the current node object.
int CollatzLinkedList::getCurrentNodeItem() { return m_currentNode -> item; }

// returns bool determining if the curnode+1 pos will be outside the max count of nodes
bool CollatzLinkedList::isLastNode() { return ( m_currentNode -> link == nullptr ); }

// returns count of nodes
int CollatzLinkedList::getItems() { return m_nodeCount; }

// sets the current node to the head of the list
void CollatzLinkedList::traverseToHead() { m_currentNode = m_head; } // if you are traversing to head then we will assume you have atleast a head in the list, otherwise its fair to throw a error

// moves the m_curnode one node forward in the list. if at the end then it returns and does nothing
void CollatzLinkedList::traverseToNextNode()
{
    // incase we traverse outside the list we just do nothing. isLastNode should say we are at the end of the list anyways
    if ( isLastNode() ) { return; }

    // this stuff happens if we are within the list still.
    m_currentNode = m_currentNode -> link;
}

// adds the a new node at the end of the linked list
void CollatzLinkedList::AppendAtTail(int intPar)
{
    CollatzNode* newNode = new CollatzNode();
    newNode -> item = intPar;
    newNode -> link = nullptr;

    if ( m_head == nullptr ) // tends to happen when this is the first node being inserted into the list
    {
        m_head = newNode;
        m_currentNode = m_head;
        m_tail = m_head; // since only one node exist rn we make the tail the head
    }
    else // basically every other node
    {
        m_tail -> link = newNode;
        m_tail = newNode; // new tail is the added node, we keep track so we can skip traversing every node infront of it
    }
}