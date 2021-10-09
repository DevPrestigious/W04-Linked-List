/***********************************************************************
 * Header:
 *    NODE
 * Summary:
 *    One node in a linked list (and the functions to support them).
 *      __      __     _______        __
 *     /  |    /  |   |  _____|   _  / /
 *     `| |    `| |   | |____    (_)/ /
 *      | |     | |   '_.____''.   / / _
 *     _| |_   _| |_  | \____) |  / / (_)
 *    |_____| |_____|  \______.' /_/
 *
 *    This will contain the class definition of:
 *        Node         : A class representing a Node
 *    Additionally, it will contain a few functions working on Node
 * Author
 *    Stephen Costigan, Alexander Dohms, Jonathan Colwell
 ************************************************************************/

#pragma once

#include <cassert>     // for ASSERT
#include <iostream>    // for NULL

/*************************************************
 * NODE
 * the node class.  Since we do not validate any
 * of the setters, there is no point in making them
 * private.  This is the case because only the
 * List class can make validation decisions
 *************************************************/
template <class T>
class Node
{
public:
   //
   // Construct
   //
    Node(               ) : pNext(nullptr), pPrev(nullptr), data(               ) { } // Default constructor
    Node(const T &  data) : pNext(nullptr), pPrev(nullptr), data(data           ) { } // Copy Constructor
    Node(      T && data) : pNext(nullptr), pPrev(nullptr), data(std::move(data)) { } // Move Constructor
   //
   // Member variables
   //

   T data;                 // user data
   Node <T> * pNext;       // pointer to next node
   Node <T> * pPrev;       // pointer to previous node
};

/***********************************************
 * COPY
 * Copy the list from the pSource and return
 * the new list
 *   INPUT  : the list to be copied
 *   OUTPUT : return the new list
 *   COST   : O(n)
 **********************************************/
template <class T>
inline Node <T> * copy(const Node <T> * pSource)
{
    if (pSource == nullptr)
        return nullptr;

    Node <T> * pDestination = new Node<T>(pSource->data);
    const Node <T> * pSrc = pSource;
    Node <T> * pDes = pDestination;

    for (pSrc = pSrc->pNext; pSrc; pSrc = pSrc->pNext) {
        pDes = insert(pDes, pSrc->data, true);
    }

    return pDestination;
}

/***********************************************
 * Assign
 * Copy the values from pSource into pDestination
 * reusing the nodes already created in pDestination if possible.
 *   INPUT  : the list to be copied
 *   OUTPUT : return the new list
 *   COST   : O(n)
 **********************************************/
template <class T>
inline void assign(Node <T>*& pDestination, const Node <T>* pSource)
{
    const Node <T> * pSrc;
    Node <T> * pDes = pDestination;
    Node <T> * pDesPrevious = nullptr;

    // replace the slots the are already filled using the assignment operator
    for (pSrc = pSource; pSrc != nullptr && pDes != nullptr; pSrc = pSrc->pNext)
    {
       pDes->data = pSrc->data;
       pDesPrevious = pDes;
       pDes = pDes->pNext;
    }

    // if there are still items the source list, then insert them on the end
    if (pSrc != nullptr)
    {
       // since pDes must equal nullptr, we need to set pDes to end of the list.
       pDes = pDesPrevious;
       // for each node extra that pSrc has but not pDes.
       for (; pSrc != nullptr; pSrc = pSrc->pNext)
       {
          // create a new node
          pDes = insert(pDes, pSrc->data, true /* after */);
          // if the destination list was previously empty, fill it now
          if (nullptr == pDestination)
             pDestination = pDes;
       }
    }
    // if there are still items in the destination list that are not needed, then delete them
    else if (pDes != nullptr)
    {
       bool setToNull = false;
       // make the previous item in the list the last
       if (pDes->pPrev)
          pDes->pPrev->pNext = nullptr;
       else
          setToNull = true;
       // now delete the list from here on out
       clear(pDes);
       if (setToNull)
          pDestination = nullptr;
    }
}

/***********************************************
 * SWAP
 * Swap the list from LHS to RHS
 *   COST   : O(1)
 **********************************************/
template <class T>
inline void swap(Node <T>* &pLHS, Node <T>* &pRHS)
{
    Node <T>* test = std::move(pLHS);
    pLHS = std::move(pRHS);
    pRHS = std::move(test);
}

/***********************************************
 * REMOVE
 * Remove the node pSource in the linked list
 *   INPUT  : the node to be removed
 *   OUTPUT : the pointer to the parent node
 *   COST   : O(1)
 **********************************************/
template <class T>
inline Node <T> * remove(const Node <T> * pRemove)
{
    Node <T>* pReturn = NULL;
    if (pRemove == NULL)
        return pReturn;

    if (pRemove->pPrev)
        pRemove->pPrev->pNext = pRemove->pNext;

    if (pRemove->pNext)
        pRemove->pNext->pPrev = pRemove->pPrev;

    pReturn = pRemove->pPrev ? pRemove->pPrev : pRemove->pNext;

    delete pRemove;
    return pReturn;
}


/**********************************************
 * INSERT 
 * Insert a new node the the value in "t" into a linked
 * list immediately before the current position.
 *   INPUT   : t - the value to be used for the new node
 *             pCurrent - a pointer to the node before which
 *                we will be inserting the new node
 *             after - whether we will be inserting after
 *   OUTPUT  : return the newly inserted item
 *   COST    : O(1)
 **********************************************/
template <class T>
inline Node <T> * insert(Node <T> * pCurrent,
                  const T & t,
                  bool after = false)
{
    Node <T>* pNew = new Node <T>(t);

    if (pCurrent != NULL && !after)
    {
        pNew->pPrev = pCurrent->pPrev;
        pNew->pNext = pCurrent;
        
        pCurrent->pPrev = pNew;
        if (pNew->pPrev)
            pNew->pPrev->pNext = pNew;
    }
    else if (pCurrent != NULL && after)
    {  
        pNew->pNext = pCurrent->pNext;
        pNew->pPrev = pCurrent;
        
        pCurrent->pNext = pNew;
        if (pNew->pNext)
            pNew->pNext->pPrev = pNew;
    }
    return pNew;
}

/******************************************************
 * FIND
 * Find a given node in an unsorted linked list.  Return
 * a pointer to the node if it is found, NULL otherwise.
 *  INPUT   : a pointer to the head of the linked list
 *            the value to be found
 *  OUTPUT  : a pointer to the node if it is found
 *  COST    : O(n)
 ********************************************************/
template <class T>
inline size_t size(const Node <T> * pHead)
{
    if (pHead == nullptr) {
        return 0;
    }
    return size(pHead->pNext) + 1;
}

/***********************************************
 * DISPLAY
 * Display all the items in the linked list from here on back
 *    INPUT  : the output stream
 *             pointer to the linked list
 *    OUTPUT : the data from the linked list on the screen
 *    COST   : O(n)
 **********************************************/
template <class T>
inline std::ostream & operator << (std::ostream & out, const Node <T> * pHead)
{
    // I don't think this contributes to our %
    for (auto p = pHead; p; p = p->pNext) {
        if (p->pNext != nullptr) {
            out << p->data << ", "; // comma separation in case there are multiple
        }
        else {
            out << p->data; // if one value, just return 1
        }
    }
    return out;
}

/*****************************************************
 * FREE DATA
 * Free all the data currently in the linked list
 *   INPUT   : pointer to the head of the linked list
 *   OUTPUT  : pHead set to NULL
 *   COST    : O(n)
 ****************************************************/
template <class T>
inline void clear(Node <T> * & pHead)
{

    Node <T>* pDelete = pHead; // redundant for first loop, but oh well
    while (pHead != nullptr) {
        pDelete = pHead;
        pHead = pHead->pNext;
        delete pDelete;
    }
    delete pHead;
}
