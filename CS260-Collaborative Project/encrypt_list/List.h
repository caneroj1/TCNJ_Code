/*
 *  List.h
 *  
 *
 *  Created by Joseph Canero on 11/17/12.
 *  
 *
 */

/*
 This is the template header file of a linked list.
 It will allow for the linked list to store a generic data type.
 
 */
#ifndef ____List__
#define ____List__


#include <iostream>
#include <cstddef>

using namespace std;

template <class T>
class LinkedList
{
	
	struct NodeType;
	typedef NodeType* nodePtr;
	
private:

	struct NodeType {
		T component;
		nodePtr link;
	};
	nodePtr head;
	
public:
	
	LinkedList ();									//CONSTRUCTOR
	LinkedList (const LinkedList<T>&);				//COPY CONSTRUCTOR
	~LinkedList ();									//DESTRUCTOR
	LinkedList<T>& clearList ();								//clears the list
	
	void insertElement (T);							//INSERT ELEMENT
	void removeElement (T);							//REMOVE
	void operator= (const LinkedList&);				//OVERLOADED OPERATOR =
	bool operator== (const LinkedList&) const;			//OVERLOADED OPERATOR ==. determines if the two lists are equal. returns a bool
	
	bool isEmpty () const;								//returns a bool depending on if the list contains at least one element
	bool listContains (T);							//searches list to see if it contains the specified element
	
	void displayElements();							//Displays the contents of the linked list
	
	template <class S>
	friend istream& operator>> (istream&, LinkedList<S>&);	//OVERLOADED >>. allows a user to input elements of the list
	template <class S>
	friend ostream& operator<< (ostream&, LinkedList<S>&);	//OVERLOADED <<. display all elements of the list
	
	T returnElement (int);						//returns the component of the node
    
    int sizeOfList ();
};
#endif /* defined(____testCrypt__) */