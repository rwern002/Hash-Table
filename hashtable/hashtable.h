#include <iostream>
#include <string>
#include <stdio.h>
#include "linkedlist.h"

using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

/*
Hashtable with double linked list
This makes it easier to add and remove profiles
Also uses the ID of the profile in the hash function
*/
class hashTable
{
    private:
        const int tableSize = 30;
        LinkedList** tables;
        int hashFunction(string hashK)//Use a simple hash function to store
        {
            int hash = 0;
            for (int i = 0; i < (int)hashK.length(); ++i)
            {
                hash = hash + (int)hashK[i];
            }

            return hash % tableSize;
        }

    public:
        hashTable() //Constructor
        {
            tables = new LinkedList*[tableSize];
            for (int i = 0; i < tableSize; ++i)
            {
                tables[i] = NULL;
            }
        } 

        ~hashTable()
        {
            for (int i = 0; i < tableSize; ++i)
            {
                if (tables[i] != NULL)
                {
                    delete tables[i];
                }
            }
        }

        void addProfile(string name, string ID)
        {
            int key = hashFunction(ID);
            ProfileNode* newID = new ProfileNode();
            newID->name = name;
            newID->ID = ID;
            LinkedList* table = tables[key];
            if (table == NULL)
            {
                table = new LinkedList();
                tables[key] = table;
            }
            table->push_back(newID);
        }

        void removeProfile(string ID)
        {
            int key = hashFunction(ID);
            //cout << "removing profile" << endl;
            if (tables[key] == NULL)
            {
                return;
            }

            else
            {
                //cout << "found profile while removing" << endl;
                tables[key]->removeUser(ID);
            }
        }

        
        void profileExists(string ID)
        {
            int key = hashFunction(ID);
            LinkedList* checkProfile = tables[key];
            if (checkProfile == NULL)
            {
                return;
            }

            else
            {
                checkProfile->checkIDP(ID);
            }
            
        }

        int getSize()
        {
            int size = 0;
            for (int i = 0; i < tableSize; ++i)
            {
                if (tables[i] != NULL)
                {
                    size += tables[i]->getSize();
                }
            }

            return size;
        }

        void displayHT()
        {
            //cout << "display" << endl;
            for (int i = 0; i < tableSize; ++i)
            {
                if (tables[i] != NULL)
                {
                    cout << "Table " << i << ":" << endl; 
                    tables[i]->display();
                    cout << endl;
                }
            }
        }

};

#endif

