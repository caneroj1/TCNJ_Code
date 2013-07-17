/*
 *  List.cpp
 *  CSC260/Dr. Pulimood
 *  Collaborative Project
 *  Created by Joseph Canero on 11/17/12.
 * 
 *
 */

#include "../headers/List.h"

//******************************************************************************************
LinkedList::LinkedList ()	
{	//Constructor
	//Initializes the head pointer of the set to NULL
	head = NULL;
	size = 0;
}

//******************************************************************************************
LinkedList::LinkedList (const LinkedList& rhs)
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
	size = rhs.size;
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
LinkedList::~LinkedList ()
{	//Destructor
	//Postcondition: All nodes in this linked list will be deallocated
	
	nodePtr tempPtr;
	nodePtr currPtr = head;
	
	while (currPtr != NULL) {
		tempPtr = currPtr;
		currPtr = currPtr->link;
		delete tempPtr->component;
		delete tempPtr;
	}
}

//******************************************************************************************
LinkedList& LinkedList::clearList ()
{	//clears the contents of the list
	//Postcondition: All nodes of the linked list are deleted
	
	nodePtr currPtr = head;
    nodePtr tempPtr;
    
    while (currPtr != NULL)
    {
        tempPtr = currPtr;
        currPtr = currPtr->link;
        delete tempPtr->component;
        delete tempPtr;
    }
    
    head = NULL;
    
    return *this;
}

//******************************************************************************************
void LinkedList::insertElement (Account* element)
{	//The list is kept in sorted order
	//Postcondition: The parameter will have been added to the linked list
	
	if (isEmpty())
	{
		head = new NodeType;
		head->link = NULL;
		head->component = element;
		size++;
	}
	else
	{
		nodePtr temp = head, prev = NULL, newNode = NULL;
		while (temp!=NULL && ((*element) > temp->component))
		{
			prev = temp;
			temp = temp->link;
		}
		newNode = new NodeType;
		newNode->component = element;
		newNode->link = temp;
		if (prev!=NULL) prev->link = newNode;
        else head = newNode;
		size++;
	}
}

//******************************************************************************************
bool LinkedList::removeElement (Account* element)
{	//removes the specified element from the linked list
	//various checks are performed to see if the element can even be removed
	//Postcondition: if the element is in the list, it is removed
	if (!listContains(element)) return false;
	else
	{
		bool found = false;
		nodePtr next=head, prev=NULL;
		while (!found && next!=NULL)
		{
			if ((*(next->component)) == element)
			{
				found = true;
				if (prev!=NULL)	prev->link = next->link;
				else head = head->link;
				delete next->component;
				delete next;
				size--;
			}	
			else
			{
				prev = next;
				next = next->link;
			}
		}
		return found;
	}
}

//******************************************************************************************
bool LinkedList::isEmpty () const
{	//checks if the list is empty
	//Postconditon: a bool is returned indicating the list's status
	if (size <= 0) return true;
	else return false;
}

//******************************************************************************************
bool LinkedList::listContains (const Account* element)
{	//determines if the list contains the specified element
	//Postcondition: a bool is returned indicating if the list contains the element
	
	nodePtr currPtr = head;
	while (currPtr != NULL) {
		if ((*(currPtr->component)) == element) {
			return true;
		}
		currPtr = currPtr->link;
	}
	
	return false;
	
}

//******************************************************************************************
int LinkedList::sizeOfList()
{
	//returns the size of the list, useful for various processing purposes
    //Postcondition: an int value of the size of the list is returned
    return size;
}

//******************************************************************************************
Account* LinkedList::returnElement (int index) const
{	//returns the component data at a specific node
	//Postcondition: the component is returned'
	bool cont = (index>=0 && index<size);
	if (cont)
	{
		nodePtr temp = head;
		for (int i=0; i<index; i++)
			temp = temp->link;
		return (temp->component);
	}
	else
	{
		//Account temp;
		return NULL;
	}
}

//******************************************************************************************
void LinkedList::operator= (const LinkedList& rhs)
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
	size = rhs.size;
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
bool LinkedList::operator== (const LinkedList& rhs) const
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
				if (!(leftPtr->component == rightPtr->component))	//if this check fails just once, the two lists are dissimilar
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
ostream& operator<< (ostream& ostr, LinkedList& rhs)
{	//outputs the contents of the linked list
	//Postcondition: the contents are displayed successfully. 
	ostr << "***Front Of List***" << endl << endl;
    if (rhs.isEmpty()) ostr << "Sorry the list is empty, you have no data, you are awarded no points, you FAIL." << endl;
    else
    {
		LinkedList::NodeType* temp = rhs.head;
		while (temp != NULL)
		{
			(temp->component)->printToFile(ostr);
			temp = temp->link;
		}
    }
    ostr << "\n***End Of List***" << endl;
    return ostr;
}

//******************************************************************************************
void LinkedList::displayElements ()
{   //will display all the elements of the list
    //Postcondition: the elements are displayed, or if the list is empty, a message is displayed
    cout << "***Front Of List***" << endl << endl;
    if (isEmpty()) cout << "Sorry the list is empty, you have no data, you are awarded no points, you FAIL." << endl;
    else
    {
		nodePtr temp = head;
		while (temp!=NULL)
		{
			cout << endl;
			(temp->component)->printToScreen();
			cout << endl;
			temp = temp->link;
		}
    }
    cout << "\n***End Of List***" << endl;
}

//*********************************************************************
Account* LinkedList::search(Account* acct) const
{
	bool found = false;
	nodePtr temp = head;
	while (!found && temp!=NULL)
	{
		if ((*(temp->component))==acct) found = true;
		else temp = temp->link;
	}
	
	if (found) return temp->component;
	else return NULL;
}

/*void LinkedList::printElements(void) const
{
	cout << "\n***Front Of List***" << endl << endl;
    if (isEmpty()) cout << "Sorry the list is empty, you have no data, you are awarded no points, you FAIL." << endl;
    else
    {
		nodePtr temp = head;
		while (temp != NULL)
		{
			cout << endl << endl;
			(temp->component)->printToScreen();
			temp = temp->link;
		}
    }
    ostr << "\n***End Of List***" << endl;
}*/
