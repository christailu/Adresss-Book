// ---------------------------------------------------------------------------
// Name: Christelle Mbemba
// Course-Section: CS255-02
// Assignment: Project 8
// Date due: 04/09/2023
// Description:  implementation of an address class with overloaded operators for comparison and output.
// ---------------------------------------------------------------------------

#ifndef H_LinkedListType
#define H_LinkedListType

#include <iostream>
#include <cassert>
using namespace std;


template <typename TypeList>
struct nodeType
{
	TypeList info;
	nodeType<TypeList> *link;
};


template<class TypeList>
class linkedListType
{
public:
    const linkedListType<TypeList>& operator=(const linkedListType<TypeList>& otherList)
    {
        if (this != &otherList) //avoid self-copy
        {
            copyList(otherList);
        }
        return *this;
    }

    void initializeList()
    {
        destroyList();
    }

    bool isEmptyList() const
    {
        return (first == nullptr);
    }

    void print() const
    {
        nodeType<TypeList> *current;

        current = first;
        while (current != nullptr)
        {
            cout << current->info << " ";
            current = current->link;
        }
    }

    int length() const
    {
        return count;
    }

    void destroyList()
    {
        nodeType<TypeList> *temp;
        while (first != nullptr)
        {
            temp = first;
            first = first->link;
            delete temp;
        }
        last = nullptr;
        count = 0;
    }

    TypeList front() const
    {
        assert(first != nullptr);
        return first->info;
    }

    TypeList back() const
    {
        assert(last != nullptr);
        return last->info;
    }

    bool search(const TypeList& searchItem)
    {
        nodeType<TypeList> *current;
        bool found = false;

        current = first;

        while (current != nullptr && !found)
            if (current->info == searchItem)
                found = true;
            else
                current = current->link;
        return found;
    }

    void insert(const TypeList& newItem)
    {
        nodeType<TypeList> *newNode;

        newNode = new nodeType<TypeList>;

        newNode->info = newItem;
        newNode->link = first;
        first = newNode;
        count++;

        if (last == nullptr)
            last = newNode;
    }

	void deleteNode(const TypeList& deleteItem)
	{
	    nodeType<TypeList> *current, *trailCurrent;
	    bool found;
	
	    if (first == nullptr) //Case 1
	        cerr << "Cannot delete from an empty list." << endl;
	    else
	    {
	        if (first->info == deleteItem) //Case 2
	        {
	            current = first;
	            first = first->link;
	            count--;
	            if (first == nullptr)
	                last = nullptr;
	            delete current;
	        }
	        else //search the list for the node with the given info
	        {
	            found = false;
	            trailCurrent = first;  //set trailCurrent to point
	                                   //to the first node
	            current = first->link; //set current to point to
	                                   //the second node
	
	            while (current != nullptr && !found)
	            {
	                if (current->info != deleteItem)
	                {
	                    trailCurrent = current;
	                    current = current->link;
	                }
	                else
	                    found = true;
	            }//end while
	
	            if (found) //Case 3
	            {
	                trailCurrent->link = current->link;
	                count--;
	                if (last == current) //node to be deleted was the last node
	                    last = trailCurrent; //update the value of last
	                delete current;  //delete the node from the list
	            }
	            else
	                cout << "The item to be deleted is not in the list." << endl;
	        }//end else
	    }
	}//end deleteNode	
	
	void sort()
	{
	    nodeType<TypeList>* current = nullptr;
	    nodeType<TypeList>* temp = nullptr;
	    nodeType<TypeList>* tC = nullptr;
	    for(int i=0; i<count; i++)
	    {
	        current = first;
	        while(current->link!=nullptr)
	        {
	            if(current->info > current->link->info)
	            {
	                temp = current->link;
	                current->link = temp->link;
	                temp->link = current;
	                if(current == first)
	                {
	                    first = temp;
	                }
	                else
	                {
	                    tC->link = temp;
	                }
	                tC = temp;
	            }
	            else
	            {
	                tC = current;
	                current = current->link;
	            }
	        }
	        last = current;
	    }
	}
		

    linkedListType()
      //Default constructor
      //Initializes the list to an empty state.
      //Postcondition: first = nullptr, last = nullptr,
      //               count = 0;
      
	{
	    first = nullptr;
	    last = nullptr;
	    count = 0;
	}      

    linkedListType(const TypeList& otherList)
      //copy constructor
	{
	    first = nullptr;
	    copyList(otherList);
	}//end copy constructor 
	     

    ~linkedListType()
      //Destructor
      //Deletes all the nodes from the list.
      //Postcondition: The list object is destroyed.
      
	{
	   destroyList();
	}//end destructor      

private:
    int count;   //variable to store the number of elements in the list
    nodeType<TypeList> *first; //pointer to the first node of the list
    nodeType<TypeList> *last;  //pointer to the last node of the list

    void copyList(const TypeList& otherList)
      //Function to make a copy of otherList.
      //Postcondition: A copy of otherList is created and
      //               assigned to this list.
	      
	{
	    nodeType<TypeList> *newNode; //pointer to create a node
	    nodeType<TypeList> *current; //pointer to traverse the list
	
	    if (first != nullptr) //if the list is nonempty, make it empty
	       destroyList();
	
	    if (otherList.first == nullptr) //otherList is empty
	    {
	        first = nullptr;
	        last = nullptr;
	        count = 0;
	    }
	    else
	    {
	        current = otherList.first; //current points to the
	                                   //list to be copied
	        count = otherList.count;
	
	            //copy the first node
	        first = new nodeType<TypeList>;  //create the node
	
	        first->info = current->info; //copy the info
	        first->link = nullptr;        //set the link field of
	                                   //the node to nullptr
	        last = first;              //make last point to the
	                                   //first node
	        current = current->link;     //make current point to
	                                     //the next node
	
	           //copy the remaining list
	        while (current != nullptr)
	        {
	            newNode = new nodeType<TypeList>;  //create a node
	            newNode->info = current->info; //copy the info
	            newNode->link = nullptr;       //set the link of
	                                        //newNode to nullptr
	            last->link = newNode;  //attach newNode after last
	            last = newNode;        //make last point to
	                                   //the actual last node
	            current = current->link;   //make current point
	                                       //to the next node
	        }//end while
	    }//end else
	}//end copyList
      
};
#endif
