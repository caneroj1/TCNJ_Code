//
//  Set.cpp
//  This is the implementation file for the Set class
//  Defines the functions specified in the header file
//  Joe Canero
//  CSC260, Dr. Pulimood
//  Created by Joseph Canero on 11/14/12.
//
//

#include "Set.h"

using namespace std;


//CONSTRUCTOR
Set::Set()
{
    head = NULL;
}

//COPY CONSTRUCTOR
Set::Set(const Set& copySet)
{
    nodePtr fromPtr;
    nodePtr toPtr;
    
    if (copySet.isEmpty())
    {
        head = NULL;
        return;
    }
    
    //copying the first node
    fromPtr = copySet.head;
    head = new NodeType;
    head->component = fromPtr->component;
    
    //copying the remaining nodes
    
    toPtr = head;
    fromPtr = fromPtr->link;
    
    while (fromPtr != NULL)
    {
        toPtr->link = new NodeType;
        toPtr = toPtr->link;
        toPtr->component = fromPtr->component;
        fromPtr = fromPtr->link;
    }
    toPtr->link = NULL;
}

//DESTRUCTOR
Set::~Set()
{
    nodePtr currPtr = head;
    nodePtr tempPtr;
    
    while (currPtr != NULL)
    {
        tempPtr = currPtr;
        currPtr = currPtr->link;
        delete tempPtr;
    }
}

//SET IS EMPTY
bool Set::isEmpty() const
{
    return (head == NULL);
}

//SET CONTAINS A SPECIFIED ELEMENT
bool Set::setContains (ItemType item)
{
    nodePtr currPtr = head;
    
    while (currPtr != NULL)
    {
        if (currPtr->component == item)
            return true;
        else
        {
            currPtr = currPtr->link;
        }
    }
    
    return false;
}

//CLEAR THE SET
void Set::clearSet ()
{
    nodePtr currPtr = head;
    nodePtr tempPtr;
    
    while (currPtr != NULL)
    {
        tempPtr = currPtr;
        currPtr = currPtr->link;
        delete tempPtr;
    }
    
    head = NULL;
    
}

//ADD ELEMENT
void Set::insertElement (ItemType item)
{
    if (item > -1 && item % 2 == 0) //check if the item is a positive even
    {
        nodePtr currPtr = head;
        nodePtr prevPtr = NULL;
        nodePtr newNode = new NodeType;
        newNode->component = item;
        newNode->link = NULL;
        
        if(!isEmpty()) //check if list is empty
        {
            if(!setContains(item))
            {
                while (currPtr != NULL)
                {
                    prevPtr = currPtr;
                    currPtr = currPtr->link;
                }
                
                //insert the node
                currPtr = newNode;
                prevPtr->link = currPtr;
            }
        }
        else
            head = newNode;
    }
}

//REMOVE ELEMENT
bool Set::removeElement (ItemType item)
{
    if (!isEmpty())
    {
        if (setContains(item))
        {
            nodePtr currPtr = head;
            nodePtr prevPtr = NULL;

            while (currPtr != NULL && currPtr->component != item)
            {
                prevPtr = currPtr;
                currPtr = currPtr->link;
            }
            
            //check if the node is the first element in the set
            if(prevPtr == NULL) {
                head = head->link;
                delete currPtr;
            }
            
            //if not the first element
            else {
                prevPtr->link = currPtr->link;
                delete currPtr;
            }
            
            return true;
        }
        else
            cout << "That element is not in the set." << endl;
        return false;
    }
    else
        cout << "The set is empty--nothing can be removed." << endl;
    
    return true;
}

//OVERLOADED ADDITION
Set Set::operator+ (Set& rhs)
{
    Set unionSet (*this);
    nodePtr rightPtr = rhs.head;
    while (rightPtr != NULL)
    {
        unionSet.insertElement(rightPtr->component);
        rightPtr = rightPtr->link;
    }
    
    //cout << unionSet;
    return unionSet;
}

//OVERLOADED DIVSION (INTERSECTION)
Set Set::operator/ (Set& rhs)
{
    Set intersectionSet(*this);
    nodePtr leftPtr = intersectionSet.head;
    
    while (leftPtr != NULL) {
        if (!rhs.setContains(leftPtr->component))
            intersectionSet.removeElement(leftPtr->component);
        
        leftPtr = leftPtr->link;
    }
    
    return intersectionSet;
}

//OVERLOADED ASSIGNMENT
void Set::operator= (const Set& copySet)
{
    if(*this == copySet)
        return;
    
    clearSet();
    
    if (copySet.isEmpty())
    {
        head = NULL;
        return;
    }
    
    nodePtr fromPtr;
    nodePtr toPtr;
    
    //copying the first node
    fromPtr = copySet.head;
    head = new NodeType;
    head->component = fromPtr->component;
    
    //copying the remaining nodes
    
    toPtr = head;
    fromPtr = fromPtr->link;
    
    while (fromPtr != NULL)
    {
        toPtr->link = new NodeType;
        toPtr = toPtr->link;
        toPtr->component = fromPtr->component;
        fromPtr = fromPtr->link;
    }
    toPtr->link = NULL;
}

//DISPLAY ELEMENTS
void Set::displayElements ()
{
    nodePtr currPtr = head;
    if(!isEmpty())
    {
        while (currPtr != NULL)
        {
            if (currPtr->link != NULL)
                cout << currPtr->component << ", ";
            if (currPtr->link == NULL)
                cout << currPtr->component;
            currPtr = currPtr->link;
        }
    }
}

//OVERLOADED EQUALS EQUALS
bool Set::operator== (const Set& rhs) const
{
    nodePtr leftPtr = head;
    nodePtr rightPtr = rhs.head;
    
    if (isEmpty())
    {
        if (rhs.isEmpty())
            return true;
        else
            return false;
    }
    
    if (!isEmpty())
    {
        if (rhs.isEmpty())
            return false;
        if(!rhs.isEmpty())
        {
            while (leftPtr != NULL && rightPtr != NULL)
            {
                if(leftPtr->component != rightPtr->component)
                    return false;
                
                leftPtr = leftPtr->link;
                rightPtr = rightPtr->link;
            }
        }
    }
    
    if((leftPtr == NULL && rightPtr != NULL) || (leftPtr != NULL && rightPtr == NULL))
        return false;
    
    return true;
    
    
}

//OVERLOADED INPUT
istream& operator>> (istream& istr, Set& set1)
{
    int x = 0;
    int data = 0;
    
        cout << "How many elements would you like to add? ";
        istr >> x;
        
        for (int i = 0; i < x; i++)
        {
            cout << "Element " << i+1 << ": ";
            istr >> data;
            set1.insertElement(data);
        }
    
    return istr;
    
}

//OVERLOADED OUTPUT
ostream& operator<< (ostream& ostr, Set& set1)
{
    ostr << "{";
    set1.displayElements();
    ostr << "}" << endl;
    return ostr;
}

//READ DATA FROM A FILE
ifstream& operator>> (ifstream& fileIn, Set& set1)
{
    int input = 0;
    
    while (!fileIn.eof()) {
        fileIn >> input;
        set1.insertElement(input);
    }
}

















