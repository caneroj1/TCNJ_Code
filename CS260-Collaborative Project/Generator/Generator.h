//
//  Generator.h
//  
//
//  Created by Joseph Canero on 11/26/12.
//
//

#ifndef ____Generator__
#define ____Generator__

#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

class Generator
{
private:
    int passLength;
    
public:
    Generator ();
    string generatePass (int);
};

#endif /* defined(____Generator__) */
