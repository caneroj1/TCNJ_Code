//
//  Set.h
//  This is the header file for the  Set class
//  It provides private and public data for the class
//  Joe Canero
//  CSC260. Dr. Pulimood
//  Created by Joseph Canero on 11/14/12.
//
//

#ifndef ____Set__
#define ____Set__

#include <iostream>
#include <fstream>
#include <cstddef>

using namespace std;

//promotes reusability by redefining the type of item to be inserted into the set
typedef int ItemType;

class Set
{
    
private:
    
    struct NodeType
    {
        ItemType component;
        NodeType* link;
    };
    typedef NodeType* nodePtr;
    nodePtr head;
    
public:
    
    
    /*  CONSTRUCTOR
    Precondition: none
    Postcondition: A instance of the Set class is created
    Parameters: none
     */
    Set();
    /*  COPY CONSTRUCTOR
    Precondition: another Set object has been created
    Postcondition: A new set instance will be created that is a copy of the parameter set
    Parameters: a single Set object 
     */
    Set(const Set&);
    /*  DESTRUCTOR
    Precondition: a Set object exists
    Postcondition: a Set instance and its elements will be deallocated and returned to memory
    Parameters: none 
     */
    ~Set();                             
    /*  INSERT ELEMENT
    Precondition: a Set object exists, the element is a positive even integer (i.e. of the form 2m where m is an integer)
    Postcondition: a valid element will be added to the set
    Parameter: a single int
     */
    void insertElement (ItemType);
    /*  REMOVE ELEMENT
    Precondition: the item to be removed is in the Set and the Set is not empty
    Postcondition: the item is removed
    Parameter: a single int 
     */
    bool removeElement (ItemType);
    /*  CHECK IF SET CONTAINS A SPECIFC ELEMENT
    Precondition: none
    Postcondition: if the Set is empty or does not contain the element, false is returned; if the Set is not empty and contains the element, true is returned
    Parameter: a single int
     */
    bool setContains (ItemType);
    /*  CLEAR SET
    Precondition: none
    Postcondition: the Set instance is completely cleared; that is, any and all elements are deallocated and head is set to NULL
    Parameter: none
     */
    void clearSet ();
    /*  CHECK IF SET IS EMPTY
    Precondition: none
    Postcondition: if the Set instance is empty, true is returned; if the set contains at least one element, false is returned
    Parameter: none 
     */
    bool isEmpty () const;
    /*  DISPLAY ELEMENTS
    Precondition: none
    Postcondition: prints any elements in the Set instance
    Parameter: none
     */
    void displayElements ();            
    /*  OVERLOADED ADDITION (UNION OF SETS)
    Precondition: another Set object has been created
    Postcondition: a Set instance will be returned that is the union of two sets as defined in Set Theory (i.e. all elements of both sets placed into a single set discounting the repeats)
    Parameter: a single Set object 
     */
    Set operator+ (Set&);
    /*  OVERLOADED DIVISION (INTERSECTION OF SETS)
    Precondition: another Set object has been created
    Postcondition: a Set instance will be returned that is the intersection of the two sets as defined in Set Theory (i.e. the shared elements of both sets placed into a single set) 
     Parameter: a single Set object
     */
    Set operator/ (Set&);
    /*  OVERLOADED ASSIGNMENT
    Precondition: another Set object has been created
    Postcondition: the calling Set will be modified to be an exact copy of the parameter Set
    Parameter: a single Set object 
     */
    void operator= (const Set&);
    /*  OVERLOADED ==
    Precondition: another Set object has been created
    Postcondition: true is returned if the two Sets are equal; false is returned if the two Sets are unequal
    Parameter: a single Set object 
     */
    bool operator== (const Set&) const; 
    /*  OVERLOADED INPUT
    Precondition: none
    Postcondition: elements defined by the user will be added into the Set
    Parameter: an istream object and a Set object
     */
    friend istream& operator>> (istream&, Set&);
    /*  OVERLOADED OUTPUT
    Precondition: none
    Postcondition: the elements in the Set instance will be displayed to the screen
    Parameter: an ostream object and a Set object 
     */
    friend ostream& operator<< (ostream&, Set&);    
    /*  READ FROM FILE
    Precondition: none
    Postcondition: elements defined in a file are added to the Set
    Parameter: an ifstream object and a Set object
     */
    friend ifstream& operator>> (ifstream&, Set&);
    
};

#endif /* defined(____Set__) */
