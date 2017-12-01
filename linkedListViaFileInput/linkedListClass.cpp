#include <iostream>
#include "itemType.h"
#include "linkedListClass.h"

using namespace std;

LinkedList::LinkedList()
{
    head = NULL;
//    cout << "Constructor\n";
}

LinkedList::~LinkedList()
{
    LLNode *current = head, *parent;

    while(current != NULL)
    {
	parent  = current;
	current = current -> next;

        parent -> next = NULL;
	delete(parent);
    }

//    cout << "Desctructor.\n";
}

void LinkedList::insert(ItemType insertData)
{
    LLNode *newNode;
    newNode = (LLNode*)malloc(sizeof(LLNode));

    if( !isEmpty() )//if list is not empty
    {
	LLNode *current = head, *parent;

	while(current != NULL && insertData > current -> data)
	{//walk the pointers down the list
	    parent = current;
	    current = current -> next;
	}

	if(current == head)
	{//if insertData is to be put at head of list
	    //cout << "adding to head\n";
            //fflush(stdout);

	    newNode -> data = insertData;
	    newNode -> next = current;
	    head = newNode;
	}

	else if(current == NULL && insertData > parent -> data)
	{//if insertData is to be put at end of list
	    //cout << "adding to end\n";
	    //fflush(stdout);

	    newNode -> data = insertData;
	    parent -> next = newNode;
	    newNode -> next = NULL;
	}

	else if(insertData == current -> data)
	{//if the data already exists -> replace
	    //cout << "replacing pre-existing node\n";
            //fflush(stdout);

	    newNode -> data = insertData;
	    parent  -> next = newNode;
	    newNode -> next = current -> next;
	    delete(current);
	}	

	else
	{//if insertData is to be put in middle OR
	    //cout << "adding to middle\n";
            //fflush(stdout);

	    newNode -> data = insertData;
	    parent -> next = newNode;
	    newNode -> next = current; 
	}

    }
    else//if list is empty
    {
	//cout << "inserting first node\n";
        //fflush(stdout);

	newNode -> data = insertData;
	head = newNode;
	newNode -> next = NULL;
    }

    return;
}

void LinkedList::remove(ItemType removeData)
{
    if( !isEmpty())//if list is NOT empty
    {
	LLNode *current = head, *parent;

        while(current != NULL && removeData > current -> data)
        {    //walk the pointers down the list
            parent = current;
            current = current -> next;
        }
	if(removeData == (current -> data) && current == head)
	{//if removing the head
	    head = head -> next;
	    current -> next = NULL;
	    delete(current);
	}

	else if(removeData == (current -> data) && current != head)//if removeData is found
        {
	    //cout << "found removeData\n";
            //fflush(stdout);

            (parent -> next) = (current -> next);
            delete(current);
        }
        
	else 
	{    //if current == head OR 
	     //current -> data > removeData OR 
	     //current == NULL
	    cout << "Data dos not exist\n";
            fflush(stdout);
	}

    }

    else//list is already empty
    {
	cout << "List is already empty\n";
	fflush(stdout);
    }

    return;
}

void LinkedList::printAll()
{
    LLNode *current = head;

    while(current != NULL)
    {
	cout << current -> data << endl;
	current = current -> next;
    }

    if(isEmpty())
    {
        cout << "The list is empty.\n";
    }

    cout << endl;

    return;
}

bool LinkedList::isEmpty()
{
    return(head == NULL);
}
