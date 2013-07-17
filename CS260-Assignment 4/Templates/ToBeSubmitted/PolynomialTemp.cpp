//  Joe Canero
//  Polynomial.cpp
//  CSC260
//  Dr. Pulimood
//
//  Assignment 4
//  Created by Joseph Canero on 10/9/12.
//
//

#include "PolynomialTemp.h"

//*************************************************************************************
template<class T>
Polynomial<T>::Polynomial()
{
    //The term count for this polynomial is set to 0
    
    tCount = 0;
}

//*************************************************************************************
template<class T>
Polynomial<T>::Polynomial(T a, int b)
{
    //the parameterized constructor
    //tCount is set to 1 and the Term becomes int a and the degree becomes int b
    
    tCount = 1;
    polyArr[0] = Term<T>(a,b);
}

//*************************************************************************************
template<class T>
Polynomial<T> Polynomial<T>::operator+(const Polynomial<T>& poly2) const
{
    //Placeholder polynomials are created
    //Polynomial poly3 is created to store the result of the Polynomial addition
    
    Polynomial<T> poly3;
    Polynomial<T> placeHold2 = poly2;
    Polynomial<T> placeHold;
    
    //Setting placeHold Polynomial equal to the calling Polynomial
    for(int a = tCount-1; a >= 0; a--)
        placeHold.polyArr[a] = polyArr[a];
    placeHold.tCount = tCount;
    
    int place = 0; //place in the array of Polynomial 3
    
    //When first polynomial is longer
    //Loops through both Polynomials and adds terms that have like degree
    //if a Term is added, the place in array is incremented, as is the Term Count for Polynomial 3
    
    if(placeHold.tCount > placeHold2.tCount)
    {
        for(int i = placeHold.tCount-1; i >= 0; i--)
        {
            for(int f = placeHold2.tCount - 1; f >= 0; f--)
            {
                if(placeHold.polyArr[i].returnDegree() == placeHold2.polyArr[f].returnDegree() && (poly3.tCount < 10))
                {
                    poly3.polyArr[place] = Term<T>(placeHold.polyArr[i].returnCo() + placeHold2.polyArr[f].returnCo(), placeHold.polyArr[i].returnDegree());
                    poly3.tCount = poly3.tCount + 1;
                    place += 1;
                }
            }
        }
    }
    
    //When second polynomial is longer
    //Loops through both Polynomials and adds terms that have like degree
    //if a Term is added, the place in array is incremented, as is the Term Count for Polynomial 3
    
    if(placeHold.tCount < placeHold2.tCount)
    {
        for(int i = placeHold2.tCount-1; i >= 0; i--)
        {
            for(int f = placeHold.tCount-1; f >= 0; f--)
            {
                if(placeHold2.polyArr[i].returnDegree() == placeHold.polyArr[f].returnDegree() && (poly3.tCount < 10))
                {
                    poly3.polyArr[place] = Term<T>(placeHold.polyArr[f].returnCo() + placeHold2.polyArr[i].returnCo(), placeHold2.polyArr[i].returnDegree());
                    poly3.tCount = poly3.tCount + 1;
                    place += 1;
                }
            }
        }
    }
    
    //When polynomials are equal in length
    //Loops through both Polynomials and adds terms that have like degree
    //if a Term is added, the place in array is incremented, as is the Term Count for Polynomial 3
    
    if(placeHold.tCount-1 == placeHold2.tCount-1)
    {
        //cout<< "IN ADD." << endl;
        for(int i = placeHold2.tCount-1; i >= 0; i--)
        {
            //cout<< "IN FOR LOOP 1." << endl;
            for(int f = placeHold.tCount-1; f >= 0; f--)
            {
                //cout<< "IN FOR LOOP 2." << endl;
                if(placeHold2.polyArr[i].returnDegree() == placeHold.polyArr[f].returnDegree() && (poly3.tCount < 10))
                {
                    //cout << "ADDED" << endl;
                    poly3.polyArr[place] = Term<T>(placeHold.polyArr[f].returnCo() + placeHold2.polyArr[i].returnCo(), placeHold2.polyArr[i].returnDegree());
                    poly3.tCount = poly3.tCount + 1;
                    place += 1;
                }
            }
        }
    }
    
    //Indices are created for both Polynomials
    //They store the position of the last Term in the Term array
    
    int index1 = placeHold.tCount-1;
    int index2 = placeHold2.tCount-1;
    
    
    /*
     This section of code loops through both Polynomials
     The index of each Polynomial is used for comparison
     If the term at an index is greater than the term in the opposite index, the index containing the greater term is incremented
     This loops the two Polynomials adding the biggest remaining Terms, with respect to degree
     
     */
    
    while(index1 >= 0 && index2 >= 0)
    {
        if(placeHold.polyArr[index1].returnDegree() > placeHold2.polyArr[index2].returnDegree() && poly3.tCount < MAX_TERMS)
        {
            //cout << "CONDITION 1. " << endl;
            poly3.polyArr[place] = placeHold.polyArr[index1];
            poly3.tCount = poly3.tCount+1;
            place+= 1;
            index1--;
        }
        
        if(placeHold.polyArr[index1].returnDegree() < placeHold2.polyArr[index2].returnDegree() && poly3.tCount < MAX_TERMS)
        {
            //cout << "CONDITION 2. " << endl;
            poly3.polyArr[place] = placeHold2.polyArr[index2];
            poly3.tCount = poly3.tCount+1;
            place+=1;
            index2--;
        }
        
        if(placeHold.polyArr[index1].returnDegree() == placeHold2.polyArr[index2].returnDegree() && poly3.tCount < MAX_TERMS)
        {
            //cout << "CONDITION 3. " << endl;
            index1--;
            index2--;
        }
        
        if(poly3.tCount == MAX_TERMS)
        {
            index1--;
            index2--;
        }
    }
    
    //The next two code blocks add the rest of the Terms in a Polynomial if the number of Terms in Polynomial 3 is < 10
    
    if (index1 >= 0)
    {
        for (int i = index1; i >= 0; i--)
        {
            //cout << i << endl;
            if(poly3.tCount < MAX_TERMS)
            {
                poly3.polyArr[place] = placeHold.polyArr[i];
                poly3.tCount = poly3.tCount + 1;
                place+=1;
            }
        }
    }
    
    if (index2 >= 0)
    {
        for (int i = index2; i>= 0; i--)
        {
            if(poly3.tCount < MAX_TERMS)
            {
                poly3.polyArr[place] = placeHold2.polyArr[i];
                poly3.tCount = poly3.tCount + 1;
                place+=1;
            }
        }
    }
    
    poly3.tCount = place;

    if(placeHold.tCount > 0 && placeHold2.tCount == 0)
        poly3 = placeHold;
    
    if(placeHold.tCount == 0 && placeHold2.tCount > 0)
        poly3 = placeHold2;
    
    poly3 = sortPoly(poly3);
    return poly3;
}

//*************************************************************************************
template<class T>
Polynomial<T> Polynomial<T>::operator+(T rhs) const
{
    //This function adds an integer to a Polynomial
    
    //If there is still space in the Polynomial, the integer is added as a new term
    
    Polynomial<T> result = *this;
    bool added = false;
    //This checks if the last Term in the array has a degree of 0, and is therefore capable of being added to an integer
    if(result.tCount < MAX_TERMS)
    {
        if(result.polyArr[result.tCount-1].returnCo() != 0 && result.polyArr[result.tCount-1].returnDegree() != 0)
        {
            result.polyArr[result.tCount] = Term<T>(rhs, 0);
            result.tCount = result.tCount + 1;
        }
        if(result.polyArr[result.tCount-1].returnCo() == 0 && result.polyArr[result.tCount-1].returnDegree() == 0)
        {
            result.polyArr[result.tCount-1] = Term<T>(rhs, 0);
        }
    }
    
    //If there are 10 terms it looks for Term of degree 0. If there is not one, the integer is not added
    if(result.tCount == MAX_TERMS)
    {
        for(int i = 0; i < tCount; i++)
        {
            if(result.polyArr[i].returnDegree() == 0 && !added)
            {
                result.polyArr[i] = Term<T>(rhs + result.polyArr[i].returnCo(), 0);
                added = true;
            }
        }
    }
    result = sortPoly(result);
    result = simplifyTerms(result);
    return result;
    
}

//*************************************************************************************
template<class T>
Polynomial<T> operator+(T lhs, const Polynomial<T>& rhs)
{
    //This adds an integer to the Polynomial
    Polynomial<T> result = rhs;
    bool added = false;
    
    
    //This checks if the last Term in the array has a degree of 0, and is therefore capable of being added to an integer
    if(result.tCount < MAX_TERMS)
    {
        if(result.polyArr[result.tCount-1].returnCo() != 0 && result.polyArr[result.tCount-1].returnDegree() != 0)
        {
            result.polyArr[result.tCount] = Term<T>(lhs, 0);
            result.tCount = result.tCount + 1;
        }
        if(result.polyArr[result.tCount-1].returnCo() == 0 && result.polyArr[result.tCount-1].returnDegree() == 0)
        {
            result.polyArr[result.tCount-1] = Term<T>(lhs, 0);
        }
    }
    if(result.tCount == MAX_TERMS)
    {
        for(int i = 0; i < result.tCount; i++)
        {
            if(result.polyArr[i].returnDegree() == 0 && !added)
            {
                result.polyArr[i] = Term<T>(lhs + result.polyArr[i].returnCo(), 0);
                added = true;
            }
        }
    }
    result = sortPoly(result);
    result = simplifyTerms(result);
    return result;
}

//*************************************************************************************
template<class T>
Polynomial<T> Polynomial<T>::operator* (const Polynomial<T>& p2) const
{
    //This multiplies two Polynomials
    //It loops through each position in both Term arrays and multiplies the Terms
    //See NOTE in the Polynomial.h file
    
    Polynomial<T> result;
    
    for(int i = tCount-1; i >= 0; i--)
    {
        for(int f = p2.tCount-1; f >= 0; f--)
        {
            if(result.tCount < MAX_TERMS)
            {
                result.polyArr[result.tCount] = Term<T>(polyArr[i].returnCo() * p2.polyArr[f].returnCo(), polyArr[i].returnDegree() + p2.polyArr[f].returnDegree());
                result.tCount = result.tCount + 1;
            }
        }
    }
    result = sortPoly(result);
    result = simplifyTerms(result);
    return result;
}

//*************************************************************************************
template<class T>
Polynomial<T> Polynomial<T>::operator* (T rhs) const
{
    //This multiplies every term in the Polynomial by an integer by looping through every term and doing the multiplication
    
    Polynomial<T> result;
    
    for (int i = tCount-1; i >= 0; i--)
    {
        result.polyArr[result.tCount] = polyArr[i] * rhs;
        result.tCount = result.tCount + 1;
    }
    
    result = simplifyTerms(result);
    result = sortPoly(result);
    return result;
}

//*************************************************************************************
template<class T>
Polynomial<T> operator* (T lhs, const Polynomial<T>& rhs)
{
    //This effectively is the same as the previous function, but the difference lies in the calling data type. This function is a friend function
    Polynomial<T> result;
    
    for (int i = rhs.tCount-1; i >= 0; i--)
    {
        result.polyArr[result.tCount] = rhs.polyArr[i] * lhs;
        result.tCount = result.tCount + 1;
    }
    
    result = simplifyTerms(result);
    result = sortPoly(result);
    return result;
}


//*************************************************************************************
template<class T>
Polynomial<T> Polynomial<T>::operator=(const Polynomial<T>& poly2)
{
    //This loops through each Term in both Polynomials and sets the position in the calling Polynomial's array equal to the one in the corresponding position of the other Polynomial
    
    //Next, it sets all Terms that were not rewritten equal to 0
    
    for(int i = 0; i < poly2.tCount; i++)
        polyArr[i] = poly2.polyArr[i];
    
    for(int i = tCount-1; i > poly2.tCount-1; i--)
        polyArr[i] = Term<T>(0,0);
    
    tCount = poly2.tCount;
    
    return *this;
}

//*************************************************************************************
template<class T>
Polynomial<T> Polynomial<T>::operator= (T rhs)
{
    //This sets every term in the Polynomial equal to 0
    //The first position in the array becomes a Term of degree 0 with a coefficient of rhs
    
    for(int i = tCount-1; i > -1; i--)
        polyArr[i] = Term<T>(0,0);
    polyArr[0] = Term<T>(rhs, 0);
    tCount = 1;
    
    return *this;
}

//*************************************************************************************
template<class T>
istream& operator>> (istream& ins, Polynomial<T>& poly1)
{
    //This asks for how many terms in the Polynomial and reads in data for the number specified. Error handling occurs in the inputTerm function in Term.cpp
    
    cout << "How many terms in this polynomial? ";
    ins >> poly1.tCount;
    
    if(poly1.tCount < 0)
        poly1.tCount = poly1.tCount * -1;
    
    if(poly1.tCount > 0)
    {
        for(int i = 0; i < poly1.tCount; i++)
        {
            cout << endl << "Enter the data for term " << i+1 << " of the polynomial." << endl;
            poly1.polyArr[i] = poly1.polyArr[i].inputTerm();
        }
    }
    poly1 = sortPoly(poly1);
    poly1 = simplifyTerms(poly1);
    return ins;
}

//*************************************************************************************
template<class T>
Polynomial<T>& sortPoly (Polynomial<T>& poly)
{
    //This sorts the Terms of the Polynomial by degree, placing the largest ones at the end of the array
    //It is an insertion sort algorithm
    
    int i = 0;
    int j = 0;
    Polynomial<T> poly2 = poly;
    for (i = 1; i < poly.tCount; i++)
    {
        poly2.polyArr[0] = poly.polyArr[i];
        j = i;
        while ( j > 0 && poly2.polyArr[0].returnDegree() < poly.polyArr[j-1].returnDegree())
        {
            poly.polyArr[j] = poly.polyArr[j-1];
            j--;
        }
        poly.polyArr[j] = poly2.polyArr[0];
    }
    return poly;
}

//*************************************************************************************
template<class T>
ostream& operator<< (ostream& outs, Polynomial<T>& poly1)
{
    //This outputs the Polynomial to the screen
    
    bool allZero = true;
    
    //If the Term Count for the Polynomial is 0, the Polynomial is effectively a single term of coefficient and degree 0, and that is what is output
    
    if(poly1.tCount == 0)
        outs << "0";
    
    //This checks to make sure at least one Term in the Polynomial is not a Term of degree and coefficient 0
    
    if(poly1.tCount > 0)
    {
        for (int i = poly1.tCount-1; i >= 0; i--)
        {
            if (poly1.polyArr[i].returnCo() != 0)
                allZero = false;
        }
        
        if(allZero)
            outs << "0";
    }
    
    //If there is at least one Term that is not degree and coefficient 0, this block is executed
    
    if(!allZero)
    {
        //cout << "In the block. Term count is: " << poly1.tCount << endl;
        //This code block outputs the first term in the Polynomial, which is the Term of greatest degree. Because of the sort, that term is at the end of the array
        
        if(poly1.polyArr[poly1.tCount-1].returnCo() != 0 && poly1.polyArr[poly1.tCount-1].returnDegree() != 0)
            outs << poly1.polyArr[poly1.tCount-1].returnCo() << "x^" << poly1.polyArr[poly1.tCount-1].returnDegree();
        if(poly1.polyArr[poly1.tCount-1].returnCo() == 0 && poly1.polyArr[poly1.tCount-1].returnDegree() != 0)
            outs << "0";
        if(poly1.polyArr[poly1.tCount-1].returnCo() != 0 && poly1.polyArr[poly1.tCount-1].returnDegree() == 0)
            outs << poly1.polyArr[poly1.tCount-1].returnCo();
        if(poly1.polyArr[poly1.tCount-1].returnCo() == 0 && poly1.polyArr[poly1.tCount-1].returnDegree() == 0)
            outs << "0";
        
        //If there is more than one term in the array, this block is executed
        
        if(poly1.tCount > 1)
        {
            //cout << "In the second block. Term count is: " << poly1.tCount << endl;
            //This determines what the term looks like and outputs the appropriate sign symbol and the term
            
            for(int i = poly1.tCount-2; i >= 0; i--)
            {
                if(poly1.polyArr[i].returnCo() != 0 && poly1.polyArr[i]/*.returnDegree()*/ != 0)
                {
                    //cout << "Here1" << endl;
                    if(poly1.polyArr[i].returnCo() > 0)
                        outs << " + " << poly1.polyArr[i].returnCo() << "x^" << poly1.polyArr[i].returnDegree();
                    if(poly1.polyArr[i].returnCo() < 0)
                        outs << " " << poly1.polyArr[i].returnCo() << "x^" << poly1.polyArr[i].returnDegree();
                }
                if(poly1.polyArr[i].returnCo() == 0)
                    outs << " ";
                if(poly1.polyArr[i].returnDegree() == 0)
                {
                    //cout << "Here2" << endl;
                    if(poly1.polyArr[i].returnCo() > 0)
                        outs << " + " << poly1.polyArr[i].returnCo();
                    if(poly1.polyArr[i].returnCo() < 0)
                        outs << " " << poly1.polyArr[i].returnCo();
                }
                
            }
        }
    }
    outs << endl;
    return outs;
}

//*************************************************************************************
template<class T>
Polynomial<T> simplifyTerms (Polynomial<T>& poly)
{
    //This simplifies the Terms in the Polynomial array
    //It combines Terms of like degree
    //The Polynomial is sorted once again
    
    Polynomial<T> result;
    int place = 0;
    int termsAdded = 0;
    
    for (int i = poly.tCount-1; i > 0; i--)
    {
        if (poly.polyArr[i].returnDegree() != poly.polyArr[i-1].returnDegree())
        {
            result.polyArr[place] = poly.polyArr[i];
            result.tCount+=1;
            place+=1;
        }
        if (poly.polyArr[i].returnDegree() == poly.polyArr[i-1].returnDegree())
        {
            result.polyArr[place] = poly.polyArr[i];
            
            for(int a = i-1; a >= 0; a--)
            {
                if (result.polyArr[place].returnDegree() == poly.polyArr[a].returnDegree())
                {
                    result.polyArr[place] = Term<T>(result.polyArr[place].returnCo() + poly.polyArr[a].returnCo(), result.polyArr[place].returnDegree());
                    termsAdded += 1;
                }
            }
            result.tCount+=1;
            place+=1;
            
        }
        i -= termsAdded;
        termsAdded = 0;
    }
    
    if(poly.polyArr[0].returnDegree() != result.polyArr[place-1].returnDegree())
    {
        result.polyArr[place] = poly.polyArr[0];
        result.tCount+=1;
    }

    result = sortPoly(result);
    return result;
}

//*************************************************************************************
template<class T>
ifstream& operator>> (ifstream& istr, Polynomial<T>& poly)
{
    //This reads in a Polynomial from a file
    //The first int read in determines the length of the Polynomial
    //All following data become the degree and coefficient for each Term
    
    int termsIn = 0;
    int termDeg = 0;
    T termCo = 0;
    
    istr >> termsIn;
    
    if(termsIn > 10)
        termsIn = 10;
    
    for (int i = 0; i < termsIn; i++)
    {
        istr >> termCo;
        istr >> termDeg;
        
        poly.polyArr[i] = Term<T>(termCo, termDeg);
    }
    poly.tCount = termsIn;
    poly = simplifyTerms(poly);
    poly = sortPoly(poly);
    
    return istr;
}

//*************************************************************************************
template<class T>
T Polynomial<T>::evalPoly (double num) const
{
    //This evaluates each term with the specified parameter
    //Num is raised to the degree of the Term
    //Next it is multiplied by the coefficient
    
    T sum = 0;
    for (int i = tCount-1; i >= 0; i--)
    {
        //cout << "Evaluation: " << polyArr[i].evalTerm(num) << endl;
        //cout << "The sum: " << sum << endl;
        sum = sum + polyArr[i].evalTerm(num);
    }
    
    return sum;
}

//*************************************************************************************
template<class T>
void Polynomial<T>::writeToFile () const
{
    //This writes the Polynomial to a file
    //The file is output.txt
    //The format of the output is the same as the format of the in files
    
    ofstream outF;
    outF.open("output.txt");
    cout << "Writing to file." << endl;
    outF << tCount << endl;
    
    for (int i = tCount - 1; i >= 0; i--)
    {
        outF << polyArr[i].returnCo() << " " << polyArr[i].returnDegree() << endl;
    }
}

template <class T>
Polynomial<T> Polynomial<T>::derivative ()
{
    for(int i = tCount-1; i >= 0; i--)
    {
        polyArr[i] = Term<T>(polyArr[i].returnCo() * polyArr[i].returnDegree(), polyArr[i].returnDegree() - 1);
    }
    
    return *this;
    
}









