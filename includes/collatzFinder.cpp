#include <iostream>

#include "collatzLList.h"
#include "collatzFinder.h"

using namespace std;

CollatzFinder::CollatzFinder() // constructor
{
    m_longestListCount = 1;
    m_longestNum = 1;
    m_longestList = nullptr;
}

CollatzFinder::~CollatzFinder() // deconstructor
{
    if ( m_longestList != nullptr )
    {
        m_longestList->~CollatzLinkedList(); // if we have a stored list we need to deconstruct it properly so we dont cause a memory leak
    }
}

// takes a input and determines the output using the logic from collatz
int CollatzFinder::processNumberWithCollatz(int n)
{
    if ( n % 2 == 0 ) // is even
    {
        return n / 2;
    }
    else // odd
    {
        return ( 3 * n ) + 1;
    }
}

// finds and stores the longest sequence
void CollatzFinder::findLongestSequence(int n)
{
    for (int i = 1; i <= n; i++) // for each number, 0 is already of 0 length because its below 1 so it auto loses making 1 the minumum
    {
        int tempN = i;
        CollatzLinkedList* seqList = new CollatzLinkedList();

        seqList -> AppendAtTail(tempN); // add the first number to the list

        while ( tempN > 1) // as long as it hasnt reached the end of the sequence which is 1
        {
            tempN = processNumberWithCollatz(tempN); // get the next number in the sequence
            seqList -> AppendAtTail(tempN); // add the number to the list
        }

        //seqList -> AppendAtTail(1); // add the last number to the list. we always guess 1 is the final since it always is anyways

        if ( seqList -> getItems() > m_longestListCount )
        {
            m_longestListCount = seqList -> getItems();
            m_longestList = seqList;
            m_longestNum = i;
        }
        else
        {
            seqList->~CollatzLinkedList(); // free the memory since it isnt used anymore
        }
    }
}

void CollatzFinder::displayLongestSequence()
{
    cout << "The number " << m_longestNum << " produces the longest Collatz sequence of " << m_longestListCount << " terms." << endl;
    cout << "Here are those terms: " << endl;

    if ( m_longestList != nullptr )
    {
        m_longestList -> traverseToHead();

        while ( !m_longestList -> isLastNode() ) // while we arent on the last node
        {
            cout << m_longestList -> getCurrentNodeItem() << "->";
            m_longestList -> traverseToNextNode();
        }
        // it ends on last node so we just print the last one and endl to fix this
        cout << m_longestList -> getCurrentNodeItem() << endl;
    }
}