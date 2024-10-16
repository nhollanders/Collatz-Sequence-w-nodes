#include "collatzLList.h"
#include "collatzFinder.h"

using namespace std;

CollatzFinder::CollatzFinder() // constructor
{
    m_longestListCount = 0;
    m_longestListNum = 0;
    m_longestList = nullptr;
}

CollatzFinder::~CollatzFinder() // deconstructor
{
    if ( m_longestList != nullptr )
    {
        m_longestList->~CollatzLinkedList(); // if we have a stored list we need to deconstruct it properly so we dont cause a memory leak
    }
}