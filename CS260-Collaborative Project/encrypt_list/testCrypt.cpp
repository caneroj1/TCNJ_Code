//
//  testCrypt.cpp
//  
//
//  Created by Joseph Canero on 11/17/12.
//
//

#include "testCrypt.h"
#include "Cryptography.cpp"

int main ()
{
    
    Cryptography unit('s');
    string str ("K");
    string enc;
    enc = unit.encryptPass(str);
    cout << "Encrypted: " << enc << endl;
    
    enc = unit.decryptPass(enc);
    cout << "Decrypted: " << enc << endl;
    
    LinkedList<string> stringList;
    
    cin >> stringList;
  
    bool success = unit.encryptAll(stringList);

    if (success) {
        cout << stringList;
        success = unit.decryptAll(stringList);
        if(success)
            cout << stringList;
    
    
    }
    return 0;
}