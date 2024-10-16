#ifndef _collatzFinder
#define _collatzFinder

#include "collatzLList.h"

class CollatzFinder {
    private:
        int m_longestListCount;
        int m_longestNum;
        CollatzLinkedList* m_longestList;

        int processNumberWithCollatz(int n);
    public:
        CollatzFinder();
        ~CollatzFinder();

        void findLongestSequence(int n);
        void displayLongestSequence();
};

#endif