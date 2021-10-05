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
 *    Stephen Costigan, Alexander Dohms
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
    
   Node() // DEFAULT
   { 
       /*Node.default - constructor()
           data <- T()
           pNext <- NULL
           pPrev <- NULL*/

      pNext = pPrev = this;
   }
   Node(const T& data) // COPY
   {
       // COPY VALUE CONSTRUCTOR
       /*Node.copy-constructor(t)
             data <- t
             pNext <- NULL
             pPrev <- NULL*/

      pNext = pPrev = this;
   }

   Node(T&& data) // MOVE
   {
      // SWAP????
       /*this->data = data;
       pNext = sizeof(data);
       pPrev = pNext - 1;*/

      pNext = pPrev = this;
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
inline Node <T> * copy(const Node <T> * pSource) 
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
inline void assign(Node <T> * & pDestination, const Node <T> * pSource)
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
}

/***********************************************
 * SWAP
 * Swap the list from LHS to RHS
 *   COST   : O(1)
 **********************************************/
template <class T>
inline void swap(Node <T>* &pLHS, Node <T>* &pRHS)
{
   
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
   return new Node<T>;
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
inline size_t size(const Node <T> * pHead)
{
    //size(pHead)
    //    IF pHead = NULL
    //RETURN 0
    //    ELSE
    //RETURN 1 + size(pHead.pNext)
   return 99;
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
    //inline friend std::ostream& operator << (std::ostream & out,
    //    const Complex & rhs)
    //{
    //    out << rhs.r;
    //    if (rhs.i != 0.0)                       // only display the imaginary
    //        out << " + " << rhs.i << "i";        //    component if non-zero
    //    return out;                             // return "out"
    //}
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
    /*clear(pHead)
        WHILE pHead != NULL
        pDelete <- pHead
        pHead <- pHead.pNext
        DELETE pDelete*/

}


