#include <iostream>
#include <string>

using namespace std;

/*
Double linked list file
Profile node stores the name, ID, the next ID the in the table, and the previous ID
Linked list has a head and tail, this way we can pop/push front and pop/push back
*/

struct ProfileNode 
{
    string name;
    string ID;
    ProfileNode* next;
    ProfileNode* prev;

    ProfileNode()//Constructor
    {
        name = "";
        ID = "";
        next = NULL;
        prev = NULL;
    }

    ProfileNode(string name, string ID, ProfileNode* next, ProfileNode* prev)
    {
        name = name;
        ID = ID;
        next = next;
        prev = prev;

    }

    
};

class LinkedList //Use a double linked list to make adding and removing users easier
{
    private:
        int size;
        ProfileNode* head;
        ProfileNode* tail;

        bool checkID(string ID)
        {
            if (size == 0)
            {
                return false;
            }

            ProfileNode* curr = head;
            while (curr != NULL)
            {
                if (curr->ID == ID)
                {
                    return true;
                }
                curr = curr->next;
            }

            return false;
        }

    public:
        LinkedList() :
            size(0), head(NULL), tail(NULL)
            {}

        ~LinkedList()
        {
            ProfileNode *curr = head;
            while (curr != NULL)
            {
                ProfileNode *next = curr->next;
                delete curr;
                curr = next;
            }
        }

        void display()
        {
            if (size == 0)
            {
                cout << "Table is Empty" << endl;
                return;
            }

            ProfileNode *curr = head;
            while (curr != NULL)
            {
                cout << "Name: " << curr->name << " ID: " << curr->ID;
                curr = curr->next;
                cout << endl;
            }

        }

        void push_back(ProfileNode* newP)
        {
            if (size == 0)
            {
                head = newP;
                head->next = NULL;
                head->prev = NULL;
            }

            else if (size == 1)
            {
                tail = newP;
                tail->next = NULL;
                tail->prev = head;
                head->next = tail;
            }

            else
            {
                ProfileNode* temp = tail;
                tail = newP;
                temp->next = tail;
                tail->prev = temp;
                tail->next = NULL;
            }

            size = size + 1;
            
        }

        void push_front(ProfileNode* newP)
        {
            if (size == 0)
            {
                head = newP;
                head->next = NULL;
                head->prev = NULL;
            }

            if (size == 1)
            {
                tail = head;
                tail->next = NULL;
                tail->prev = newP;
                head = newP;
                head->prev = NULL;
                head->next = tail;
            }

            else
            {
                ProfileNode* temp = head;
                head = newP;
                head->prev = NULL;
                head->next = temp;
                temp->prev = head;

            }
            
            size = size + 1;
        }

        void pop_back()//Remove tail
        {
            if (size == 0)
            {
                return;
            }

            else if (size == 1)
            {
                head->next = NULL;
                head->prev = NULL;
                delete head;
                head = NULL;
                tail = NULL;
            }
            
            else if (size == 2)
            {
                head->next = NULL;
                tail->prev = NULL;
                delete tail;
                tail = NULL;
            }

            else
            {
                ProfileNode* temp = tail->prev;
                temp->next = NULL;
                tail->prev = NULL;
                delete tail;
                tail = temp;
            }

            size = size - 1;
        }

        void pop_front()//Remove head
        {
            if (size == 0)
            {
                return;
            }

            else if (size == 1)
            {
                head->next = NULL;
                head->prev = NULL;
                delete head;
                head = NULL;
                tail = NULL;
            }

            else if (size == 2)
            {
                head->next = NULL;
                tail->prev = NULL;
                delete head;
                head = tail;
                head->next = NULL;
                tail = NULL;
            }

            else
            {
                ProfileNode* temp = head->next;
                temp->prev = NULL;
                head->next = NULL;
                delete head;
                head = temp;
            }

            size = size - 1;
        }
        
        void removeUser(string ID)//We can use pop_back and pop_front
        {
            ProfileNode* curr = head;
            while (curr != NULL)
            {
                if (curr->ID == ID)
                {
                    if (curr == head)
                    {
                        pop_front();
                        return;
                    }

                    else if (curr == tail)
                    {
                        pop_back();
                        return;
                    }

                    else
                    {
                        ProfileNode* newNext = curr->next;
                        ProfileNode* newPrev = curr->prev;
                        curr->next = NULL;
                        curr->prev = NULL;
                        delete curr;
                        newPrev->next = newNext;
                        newNext->prev = newPrev;
                        size = size - 1;
                        return;
                    }
                }
            }
        }
        
        //Check to see if ID is still in table
        //Good to test if profile was added/removed properly
        void checkIDP(string ID)
        {
            if (checkID(ID) == true)
            {
                cout << "Profile " << ID << " Exists" << endl;
            }

            else
            {
                cout << "Profile " << ID << " Does Not Exist" << endl;
            }
        }

        int getSize()
        {
            return size;
        }
};

