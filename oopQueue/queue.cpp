#include "appData.h"
#include "queue.h"

Queue::Queue()
//constructor
{
    #if DEBUG
        cout << "\nConstructor " << endl;
    #endif

    front = back = NULL;
}


Queue::~Queue()
//destructor aka deleteAll()
{
    #if DEBUG
        cout << "\nDestructor " << endl;
    #endif

    QueueNode *temp;

    while(front != NULL)//loop until queue is empty
    {
        temp = front;            //hold position of node to be deleted
        front = front -> next;    //move front to the next node
        free(temp);           //delete old front position
    }

    return;
}

void Queue::enqueue(AppData data)
//enqueue function: stores each node behind the previous
{
    QueueNode *newNode, *temp;
    newNode = (QueueNode*)malloc(sizeof(QueueNode));

    if( front == NULL )//if the queue is empty
    {
        front = newNode; back = newNode;  //point front and back to newNode
        newNode -> next = NULL;           //point newNode to NULL 
        newNode -> item = data;           //store data
    }
    else    //if the queue is not empty
    {
	back -> next = newNode; //change the last node's pointer to the position of newNode

	back = newNode;              //make back point to newNode
	newNode -> next = NULL;      //make newNode point to NULL
	newNode -> item = data;      //input new data to newNode
    }
    return;
}


AppData Queue::dequeue()
//dequeue function: removes the first node from the queue
{
    AppData data;

    if(front != NULL)             //if the queue is NOT empty
    {
	data = front -> item;  //store removed data to be returned

        QueueNode *temp = front;  //hold position of node to be deleted
        front = front -> next;    //change front to new front
        free(temp);               //remove old front from memory

        if(front == NULL)     //after each deletion, check to see if queue is supposed to be empty
	    back = NULL;      //if the queue is to be empty, make the back pointer NULL
    }
    else
	printf("\nThe queue is already empty.");   //if the queue is empty going into the function, display error

    return data;
}


void Queue::printAll()
//printAll function: displays all nodes' data
{
    QueueNode *temp = front;
    int count = 0;

    if(temp == NULL)
	printf("\nThe queue is empty.");
    while (temp != NULL)
    {  
	    cout << "\nData in Position " << count++ << ": " << temp -> item << endl;
	    temp = temp -> next;     //move the pointer to the next node
    }
    return;
}


bool Queue::isEmpty()
//isEmpty function: returns true if queue is empty, false otherwise
{
    return (front == NULL);
}
