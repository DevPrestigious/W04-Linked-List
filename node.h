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
    
   Node() // DEFAULT -- Alex
   { 
       /*Node.default - constructor()
           data <- T()
           pNext <- NULL
           pPrev <- NULL*/
      pNext = pPrev = NULL; // added by steve
   }
   Node(const T& data) // COPY -- Jon
   {
       // COPY VALUE CONSTRUCTOR
       /*Node.copy-constructor(t)
             data <- t
             pNext <- NULL
             pPrev <- NULL*/

      pNext = pPrev = this;
   }

   Node(T&& data) // MOVE -- Steve
   {
       this->data = data;
   }

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
inline Node <T> * copy(const Node <T> * pSource) // --Alex
{
    // COPY CONSTRUCTOR
       /*copy(pSource)
           pDestination <- new Node(pSource.data)
           pSrc <- pSource
           pDes <- pDestination
           FOR pSrc <- pSrc.pNext … end of the list
           pDes <- insert(pSrc.data, pDes, true)
           RETURN pDestination*/

   return new Node<T>;
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
inline void assign(Node <T>*& pDestination, const Node <T>* pSource) // -- Jon
{
    /*IF pSrc ≠ NULL
        setToNull <- FALSE
        IF pDes.pRev != NULL
        pDEs.pPrev.pNext <- NULL
        ELSE
        setToNull <- TRUE
        freeData(pDes)
        IF setToNull
        pDestination <- NULL*/
    if (pSrc != NULL)
    {
        setToNull = false;
        if (pDes.pRev != NULL)
            pDes.pPrev.pNext = NULL;
        else
            setToNull = true;
            freeData(pDes);
        if (setToNull)
            pDestination = NULL;
    }
}

/***********************************************
 * SWAP
 * Swap the list from LHS to RHS
 *   COST   : O(1)
 **********************************************/
template <class T>
inline void swap(Node <T>* &pLHS, Node <T>* &pRHS) // -- Steve
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
inline Node <T> * remove(const Node <T> * pRemove) // -- Alex (Added to by Steve)
{
    /*remove(pRemove)
        IF NULL = pRemove
        RETURN
        IF pRemove.pPrev
        pRemove.pPrev.pNext <- pRemove.pNext
        IF pRemove.pNext
        pRemove.pNext.pPrev <- pRemove.pPrev
        IF pRemove.pPrev
        pReturn <- pRemove.pPrev;
    ELSE
        pReturn <- pRemove.pNext
        DELETE pRemove
        RETURN pReturn*/

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
template <class T> // -- Jon
inline Node <T> * insert(Node <T> * pCurrent,
                  const T & t,
                  bool after = false)
{
    /*insert(t, pCurrent, after)
        pNew <- NEW Node(t)
        IF pCurrent != NULLand after = false
        pNew.pNext <- pCurrent
        pNew.pPrev <- pCurrent.pPrev
        pCurrent.pPrev <- pNew
        IF pNew.pPrev
        pNew.pPrev.pNext <- pNew
        IF pCurrent != NULL and after = true
        … something similar …
        RETURN pNew*/
   return new Node<T>();
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
inline size_t size(const Node <T> * pHead) // -- Steve
{
    //size(pHead)
    //    IF pHead = NULL
    //RETURN 0
    //    ELSE
    //RETURN 1 + size(pHead.pNext)
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
inline std::ostream & operator << (std::ostream & out, const Node <T> * pHead) // -- Alex (Added to by steve)
{
    while (pHead != nullptr) {
        out << pHead ; // Wasn't sure how they wanted the data returned, just returned the value. Edit if you find anything
        pHead = pHead->pNext;
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
inline void clear(Node <T> * & pHead) // -- Steve
{
    /*clear(pHead)
        WHILE pHead != NULL
        pDelete <- pHead
        pHead <- pHead.pNext
        DELETE pDelete*/

    Node <T>* pDelete = pHead; // redundant for first loop, but oh well
    while (pHead != nullptr) {
        pDelete = pHead;
        pHead = pHead->pNext;
        delete pDelete;
    }
    delete pHead;
}


