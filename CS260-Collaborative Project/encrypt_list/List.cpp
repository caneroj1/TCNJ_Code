/*
 *  List.cpp
 *  
 *
 *  Created by Joseph Canero on 11/17/12.
 * 
 *
 */

#include "List.h"

//******************************************************************************************
template <class T>
LinkedList<T>::LinkedList ()	
{	//Constructor
	//Initializes the head pointer of the set to NULL
	head = NULL;
	
}

//******************************************************************************************
template <class T>
LinkedList<T>::LinkedList (const LinkedList<T>& rhs)
{	//Copy constructor
	//Initializes the calling list with the same data as the parameter list
	//Postcondition: This copy constructor will create a deep copy of the rhs list in the calling list
	
	nodePtr fromPtr;	//Pointer into the list where the data is coming from	
	nodePtr toPtr;		//Pointer into list that will be initialized
	
	if (rhs.head == NULL) {
		head = NULL;
		return;
	}
	
	//Copy the first node from the rhs list
	fromPtr = rhs.head;
	head = new NodeType;
	head = fromPtr->component;
	//Copy remaining nodes from the rhs list
	toPtr = head;
	fromPtr = fromPtr->link;
	while (fromPtr != NULL) {
		toPtr->link = new NodeType;
		
		toPtr = toPtr->link;
		toPtr->component = fromPtr->component;
		fromPtr = fromPtr->link;
	}
	toPtr->link = NULL;
	
}

//******************************************************************************************
template <class T>
LinkedList<T>::~LinkedList ()
{	//Destructor
	//Postcondition: All nodes in this linked list will be deallocated
	
	nodePtr tempPtr;
	nodePtr currPtr = head;
	
	while (currPtr != NULL) {
		tempPtr = currPtr;
		currPtr = currPtr->link;
		delete tempPtr;
	}
}

//******************************************************************************************
template <class T>
LinkedList<T>& LinkedList<T>::clearList ()
{	//clears the contents of the list
	//Postcondition: All nodes of the linked list are deleted
	
	nodePtr currPtr = head;
    nodePtr tempPtr;
    
    while (currPtr != NULL)
    {
        tempPtr = currPtr;
        currPtr = currPtr->link;
        delete tempPtr;
    }
    
    head = NULL;
    
    return *this;
}

//******************************************************************************************
template <class T>
void LinkedList<T>::insertElement (T element)
{	//The list is kept in sorted order
	//Postcondition: The parameter will have been added to the linked list
	
	nodePtr newNode = new NodeType;
	newNode->component = element;
	newNode->link = NULL;
	
	nodePtr currPtr;
	nodePtr prevPtr;
	
	
	//if list is empty
	if (head == NULL) {
		head = newNode;
		return;
	}
	else {
		currPtr = head;
		prevPtr = NULL;
		
		while (currPtr != NULL && currPtr->component < element) {
			prevPtr = currPtr;
			currPtr = currPtr->link;
		}
		
		//INSERT THE NODE INTO LIST

		newNode->link = currPtr;
		if (prevPtr == NULL)
			head = newNode;
		
		else
			prevPtr->link = newNode;
	}
}

//******************************************************************************************
template <class T>
void LinkedList<T>::removeElement (T element)
{	//removes the specified element from the linked list
	//various checks are performed to see if the element can even be removed
	//Postcondition: if the element is in the list, it is removed
	
	if (isEmpty())
		return;
	else {
		
		nodePtr currPtr;
		nodePtr prevPtr;
		
		currPtr = head;
		prevPtr = NULL;
		
		while (currPtr != NULL && currPtr->component != element) {	//loops through list to see if element is in
			prevPtr = currPtr;
			currPtr = currPtr->link;
		}
		
		if (currPtr == NULL) { //reached the end of list, the element is not there
			return;
		}
		
		if (prevPtr == NULL) { //first item in list is the one to be removed
			head = head->link;
			delete currPtr;
			return;
		}
		
		//remove the element
		prevPtr->link = currPtr->link;
		delete currPtr;
	}
}

//******************************************************************************************
template <class T>
bool LinkedList<T>::isEmpty () const
{	//checks if the list is empty
	//Postconditon: a bool is returned indicating the list's status
	if (head == NULL)	//head will be NULL if list is empty
		return true;
	else				//else, return false;
		return false;
}

//******************************************************************************************
template <class T>
bool LinkedList<T>::listContains (T element)
{	//determines if the list contains the specified element
	//Postcondition: a bool is returned indicating if the list contains the element
	
	nodePtr currPtr = head;
	while (currPtr != NULL) {
		if (currPtr->component == element) {
			return true;
		}
		currPtr = currPtr->link;
	}
	
	return false;
	
}

//******************************************************************************************
template <class T>
T LinkedList<T>::returnElement (int nodeLocation)
{	//returns the component data at a specific node
	//Postcondition: the component is returned'
    
    bool success = false;
    nodePtr currPtr = head;
    
    if (nodeLocation <= sizeOfList())
    {
        int loopCount = 0;
        
        while (currPtr != NULL && loopCount < nodeLocation)
        {
            currPtr = currPtr->link;
            loopCount++;
        }
    }
    
    if (nodeLocation > sizeOfList()) {
        do {
            cout << "That location is not in the list." << endl << "Please enter a valid location from 0 up to " << sizeOfList() << "." << endl;
            cin >> nodeLocation;
            if (nodeLocation <= sizeOfList()) {
                success = true;
            }
            
        } while (!success);
        
    }
    
    return currPtr->component;
}

//******************************************************************************************
template <class T>
void LinkedList<T>::operator= (const LinkedList<T>& rhs)
{	//sets the data for the calling list equal to the data of the rhs list
	//Postcondition: the two lists are equal
	
	if (*this == rhs)
		return;
	
	clearList();
	
	nodePtr fromPtr;	//Pointer into the list where the data is coming from	
	nodePtr toPtr;		//Pointer into list that will be initialized
	
	if (rhs.head == NULL) {
		head = NULL;
		return;
	}
	
	//Copy the first node from the rhs list
	fromPtr = rhs.head;
	head = new NodeType;
	head->component = fromPtr->component;
	//Copy remaining nodes from the rhs list
	toPtr = head;
	fromPtr = fromPtr->link;
	while (fromPtr != NULL) {
		toPtr->link = new NodeType;
		
		toPtr = toPtr->link;
		toPtr->component = fromPtr->component;
		fromPtr = fromPtr->link;
	}
	toPtr->link = NULL;
	
}

//******************************************************************************************
template <class T>
bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const
{	//compares the two lists for equality
	//Postcondition: a bool is returned indicating if the two lists are the same
	
	if (isEmpty()) {	//if calling list is empty
		if (rhs.isEmpty())	//if the rhs list is empty
			return true;
		if (!rhs.isEmpty()) {	//if the rhs list is not empty
			return false;
		}
	}
	
	if (!isEmpty()) { //if the calling list is not empty
		if (rhs.isEmpty())	//if the rhs list is empty
			return false;
		if (!rhs.isEmpty()) { //if the rhs list is not empty
			
			nodePtr leftPtr = head;	//pointers to the heads of each list
			nodePtr rightPtr = rhs.head;
			
			while (leftPtr != NULL && rightPtr != NULL) {
				if (leftPtr->component != rightPtr->component)	//if this check fails just once, the two lists are dissimilar
					return false;
				leftPtr = leftPtr->link;	//keeps looping through the list until it reaches the end of one
				rightPtr = rightPtr->link;
			}
			
			if (leftPtr == NULL && rightPtr != NULL) //if the calling list is shorter
				return false;
			
			if (leftPtr != NULL && rightPtr == NULL) //if the rhs list is shorter
				return false;
		}
	}
	
	return true;
}

//******************************************************************************************
template <class S>
istream& operator>> (istream& istr, LinkedList<S>& rhs)
{	//allows for input into the linked list
	//Postcondition: elements input by user have been added to the list
	
	int numberElem = 0;
	
	cout << "Number of elements to be input: ";
	istr >> numberElem;
	cout << endl << endl;
	
	if (numberElem > 0) {
		S inData;
		for (int i = 0; i < numberElem; i++) {
			cout << "Element " << i+1 << ": ";
			istr >> inData;
			cout << endl;
			rhs.insertElement(inData);
		}
	}
	return istr;
	
}

//******************************************************************************************
template <class S>
ostream& operator<< (ostream& ostr, LinkedList<S>& rhs)
{	//outputs the contents of the linked list
	//Postcondition: the contents are displayed successfully. 
	
	if (rhs.isEmpty()) {
		return ostr;
	} 
	cout << "Length: " << rhs.sizeOfList() << endl;
	rhs.displayElements();
	
	return ostr;
}

//******************************************************************************************
template <class T>
void LinkedList<T>::displayElements ()
{   //will display all the elements of the list
    //Postcondition: the elements are displayed, or if the list is empty, a message is displayed
    
	int counter = 0;
	
    nodePtr currPtr = head;
    
    if (head == NULL) { //if the list is empty
        cout << "The list is empty." << endl;
    }
    
	while (currPtr != NULL) //loops through the list and outputs the elements
	{
		cout << "Contents of element " << counter+1 << ": " << currPtr->component << endl;
		currPtr = currPtr->link;
		counter++;
	}
    
}

//******************************************************************************************
template <class T>
int LinkedList<T>::sizeOfList ()
{   //returns the size of the list, useful for various processing purposes
    //Postcondition: an int value of the size of the list is returned
    int count = 0;
    
    nodePtr currPtr = head;
    while (currPtr != NULL) {
        currPtr = currPtr->link;
        count++;
    }
    
    return count;
}














