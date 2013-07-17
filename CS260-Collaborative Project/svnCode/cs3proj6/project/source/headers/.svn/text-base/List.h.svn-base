/*
 *  List.h
 *  CSC260/Dr. Pulimood
 *  Collaborative Project
 *  Created by Joseph Canero on 11/17/12.
 *  
 *
 */

/*
    This is the header file for the linked list data structure for our password manager. The linked list manages a list of User Accounts, which store username, password, etc. for different web services. 
    The component is an Account pointer type; this is necessary as there certain kinds of accounts that are more specialized than the parent class.
 */

#include <iostream>
#include "Account.h"
#if !defined (LIST_H)
#define LIST_H

using namespace std;

class LinkedList
{
	
	struct NodeType; //forward declaration
	typedef NodeType* nodePtr;
	
private:
	
	struct NodeType {
		Account* component; //this is a pointer to an account object. this provides polymorphism and inheritance
		nodePtr link;
	};
	nodePtr head; //the first node in the list
	int size; //size of the list
	
public:
	/* Default Constructor
     Postcondition: a linkedList is instantiated
     Parameters: none
     */
	LinkedList ();
    /* Copy Constructor
     Postcondition: a copy linkedList is instantiated
     Parameters: a linkedList
     */
	LinkedList (const LinkedList&);
    /* Destructor
     Postcondition: dynamically allocated memory is systematically deallocated
     Parameters: none
     */
	~LinkedList ();
    /* clearList
     Precondition: a list needs to have no elements
     Postcondition: the calling list is reset to an empty list
     Parameters: none
     Returns: a linkedList
     */
	LinkedList& clearList ();								
	/* insertElement
     Precondition: an account needs to be added to the list
     Postcondition: the account is added to the list if it is not already in
     Parameters: an account pointer
     Returns: void
     */
	void insertElement (Account*);
    /* removeElement
     Precondition: an account in the list needs to be removed
     Postcondition: the account is removed from the list if it is in
     Parameters: an account pointer
     Returns: void
     */
	bool removeElement (Account*);
    /* operator=
     Precondition: the calling list need to be the same as the right-hand side list
     Postcondition: the two lists are equal
     Parameters: a linkedList
     Returns: void
     */
	void operator= (const LinkedList&);
    /* operator==
     Precondition: two lists need to be checked for equality
     Postcondition: a bool is returned indicating whether or not the lists are equal
     Parameters: a linked list
     Returns: a bool
     */
	bool operator== (const LinkedList&) const;
    /* isEmpty
     Precondition: it needs to be ascertained whether or not the list is empty
     Postcondition: the boolean indicating if the list is empty or false is returned
     Parameters: none
     Returns: a bool
     */
	bool isEmpty () const;
    /* listContains
     Precondition: it needs to be ascertained whether or not a certain account is in the list
     Postcondition: the boolean indicating the presence of the account is returned
     Parameters: an account pointer
     Returns: a bool
     */
	bool listContains (const Account*);
    /* sizeOfList
     Precondition: the size of the linkedList is desired
     Postcondition: the size is returned
     Parameters: none
     Returns: an int
     */
	int sizeOfList();
    /* displayElements
     Precondition: elements need to be printed to the screen
     Postcondition: the elements are printed successfuly
     Parameters: none
     Returns: void
     */
	void displayElements();							
    /* operator<<
     Precondition: the list needs to be displayed
     Postcondition: the list has been printed to the screen
     Parameters: an ostream object and a linkedList
     Returns: an ostream object
     */
	friend ostream& operator<< (ostream&, LinkedList&);	
	/* returnElement
     Precondition: a specific element is desired
     Postcondition: the element is returned
     Parameters: an int indicating the account at that position
     Returns: an account pointer
     */
	Account* returnElement (int) const;
    /* search
     Precondition: a certain account is desired
     Postcondition: the account is found if present
     Parameters: an account pointer
     Returns: an account pointer
     */
    Account* search (Account *) const;
	/* printElements
	 Precondition: User wants to see all data
	 Postcondition: All accounts printed to screen
	 Parameters: none
	 Return type: void
	 */
	 //void printElements(void) const;
};

#endif /* defined(____testCrypt__) */
