#ifndef _collatzFinder
#define _collatzFinder

#include "collatzLList.h"

class CollatzFinder {
    private:
        int m_longestListCount;
        int m_longestListNum;
        CollatzLinkedList* m_longestList;

        
    public:
        CollatzFinder();
        ~CollatzFinder();

        void findLongestSequence(int intPar);
        void displayLongestSequence();
};

#endif