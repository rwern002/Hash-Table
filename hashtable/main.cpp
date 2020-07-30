#include <iostream>
#include <string>
#include <stdio.h>
#include "hashtable.h"

using namespace std;

int main()
{
    int numTables = 50;
    hashTable* hT = new hashTable();

    //Testing that Add Profile works
    for (int i = 0; i < numTables; ++i)
    {
        string name = "rotem";
        string ID = "rwern" + to_string(i);
        hT->addProfile(name, ID);
    }
    
    if (numTables == hT->getSize())
    {
        cout << "Sizes are equal" << endl;
    }

    hT->profileExists("rwern4");
    hT->profileExists("randomID");
    hT->displayHT();//Displaying all profiles

    //Testing that Remove Profile Works
    for (int i = 0; i < numTables; ++i)
    {
        string ID = "rwern" + to_string(i);
        hT->removeProfile(ID);
    }

    if (hT->getSize() == 0)
    {
        cout << "All profiles removed" << endl;
    }

    hT->profileExists("rwern4");
    cout << endl;
    hT->displayHT();//All tables should be empty
    delete hT;

    return 0;
}