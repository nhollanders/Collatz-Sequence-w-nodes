#ifndef _collatzLList
#define _collatzLList

#include <list>

using namespace std;

struct CollatzNode
{
    int item; // the integer item
    CollatzNode* link; // next collatz node
};

class CollatzLinkedList {
    private:
        CollatzNode* m_head;
        int m_InitialNumber; // m_ is member variable incase of confusion. I think it looks clean


    public:
        CollatzLinkedList();
        void setInitialNumber(int intPar);
        void calculateSequence();
        void displayCollatzSequence();
};

#endif