//  Joe Canero
//  Term.h
//  CSC260
//  Dr. Pulimood
//
//  Assignment 4
//  Created by Joseph Canero on 10/8/12.
//
//
#ifndef ____Term__
#define ____Term__

using namespace std;

template<class T>
class Term {
    
private:
    T coeff;
    int deg;
    
public:
    //*************************************************************************************
    //Constructor
    /*
     Parameterized default constructor for Term
     Accepts a Template variable that will become the coefficient and an integer to become the degree of the Term
     */
    Term (T = 0, int = 0);
    
    //*************************************************************************************
    //Overloaded Add
    /*

     PARAMETERS: a const Term passed by reference
     PRECONDITION: the Term parameter takes the data from the right hand operand of the addition
     POSTCONDITION: the Terms are added if they have like degree and the result is returned
     */
    Term operator+(const Term<T>&) const;
    
    //*************************************************************************************
    //Overloaded Multiplication
    /*

     PARAMETERS: a const Term passed by reference
     PRECONDITION: the term that is on the right side of the multiplication statement is the one passed in as the parameter
     POSTCONDITION: the two Terms are multiplied and the result is returned
     
     */
    Term operator*(const Term<T>&) const;
    
    //*************************************************************************************
    //Overloaded Multiplication
    /*
     
     PARAMETERS: a data type of type T
     PRECONDITION: the T value on the right side of the multiplication statement becomes the T parameter
     POSTCONDITION: the Term has its coefficient multiplied by the parameter and the result is returned
     
     */
    Term operator*(T) const;
    
    //*************************************************************************************
    //Overloaded Assignment
    /*
     
     PARAMETERS: a const Term passed by reference
     PRECONDITION: the Term that is on the right side of the assignment statement is the one passed in as the parameter
     POSTCONDITION: the calling Term becomes the Term that was passed in. The result is returned
     
     */
    Term operator=(const Term<T>&);
    
    //*************************************************************************************
    //Input Term
    /*
     
     PARAMETERS: none
     PRECONDITION: the calling Term has its data written from the keyboard
     POSTCONDITION: the calling Term's data has been overwritten successfully
     
     */
    Term inputTerm();
    
    //*************************************************************************************
    //Return coefficient of Term
    /*
     
     PARAMETERS: none
     PRECONDITION: the calling Term is valid
     POSTCONDITION: the calling Term's coefficient is returned
     
     */
    T returnCo() const;
    
    //*************************************************************************************
    //ostream& displayTerm(ostream&);
    /*
     
     PARAMETERS: an ostream object passed by reference and a Term object passed by reference
     PRECONDITION: the calling object is cout and is passed in as the first parameter and the Term to be output is passed in as the second parameter
     POSTCONDITION: the Term is successfully output to the standard output stream
     
     */
    template<class S>
    friend ostream& operator<<(ostream&, Term<S>&);
    
    //*************************************************************************************
    //evalTerm
    /*
     
     PARAMETERS: a double
     PRECONDITION: the Term is valid and the value passed in becomes the first parameter
     POSTCONDITION: the variable part of the Term becomes the value passed in and the Term is evaluated with that value and the result is returned
     
     */
    T evalTerm(double) const;
    
    //*************************************************************************************
    //returnDegree
    /*
     
     PARAMETERS: none
     PRECONDITION: the Term is valid
     POSTCONDITION: the Term's degree is returned
     
     */
    int returnDegree() const;
    
    //*************************************************************************************
    //operator==
    /*
     
     PARAMETERS: a const Term by reference
     PRECONDITION: equality between Terms is in question
     POSTCONDITION: true or false is returned depending on if the Terms are equal
     
     ---------------------
     This function determines equality by comparing the degrees of the Terms
     
     */
    bool operator==(const Term<T>&) const;
    
    //*************************************************************************************
    //operator==
    /*
     
     PARAMETERS: an int
     PRECONDITION: equality between a Term and an int is in question
     POSTCONDITION: true or false is returned depending on if the Term is equal to the int
     
     ---------------------
     This function determines equality by comparing the degree of the Term to parameterized int
     
     */
    bool operator==(int) const;
    
    //*************************************************************************************
    //operator>
    /*
     
     PARAMETERS: a const Term by reference
     PRECONDITION: the Term needs to be compared to another Term
     POSTCONDITION: true or false is returned depending on the result of the inequality
     
     ---------------------
     This function determines greater than status by comparing the degrees of the Terms
     
     */
    bool operator>(const Term<T>&) const;
    
    //*************************************************************************************
    //operator>
    /*
     
     PARAMETERS: an int
     PRECONDITION: the Term needs to be compared to an int
     POSTCONDITION: true or false is returned depending on the result of the inequality
     
     ---------------------
     This function determines greater than status by comparing the degree of the Term to parameterized int
     
     */
    bool operator>(int) const;
    
    //*************************************************************************************
    //operator<
    /*
     
     PARAMETERS: a const Term by reference
     PRECONDITION: the Term needs to be compared to another Term
     POSTCONDITION: true or false is returned depending on the result of the inequality
     
     ---------------------
     This function determines less than status by comparing the degrees of the Terms
     
     */
    bool operator<(const Term<T>&) const;
    
    //*************************************************************************************
    //operator<
    /*
     
     PARAMETERS: an int
     PRECONDITION: the Term needs to be compared to an int
     POSTCONDITION: true or false is returned depending on the result of the inequality
     
     ---------------------
     This function determines equality by comparing the degree of the Term to parameterized int
     
     */
    bool operator<(int) const;
    
    //*************************************************************************************
    //operator!=
    /*
     
     PARAMETERS: a const Term by reference
     PRECONDITION: the Term needs to be compared to another Term
     POSTCONDITION: true or false is returned depending on the result of the inequality
     
     ---------------------
     This function determines equality by comparing the degrees of the Terms
     
     */
    bool operator!=(const Term<T>&) const;
    
    //*************************************************************************************
    //operator!=
    /*
     
     PARAMETERS: an int
     PRECONDITION: the Term needs to be compared to an int
     POSTCONDITION: true or false is returned depending on the reuslt of the inequality
     
     ---------------------
     This function determines equality by comparing the degree of the Term to parameterized int
     
     */
    bool operator!=(int) const;
    
    Term<T> derive();
    
};

//#include <iostream>

#endif /* defined(____Term__) */

