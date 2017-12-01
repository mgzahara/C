#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void enqueue(float data, queueNode** f, queueNode** b)
//enqueue function: stores each node behind the previous
{
    queueNode *newNode, *temp;
    newNode = (queueNode*)malloc(sizeof(queueNode));

    if(isEmpty(*f))//if the queue is empty
    {
        *f = newNode; *b = newNode;  //point front and back to newNode
        newNode -> next = NULL;      //point newNode to NULL 
        newNode -> appData = data;   //store data
    }
    else//if the queue is not empty
    {
	(*b) -> next = newNode;
//change the last node's pointer to the position of newNode

	*b = newNode;              //make back point to newNode
	newNode -> next = NULL;    //make newNode point to NULL
	newNode -> appData = data; //input new data to newNode
    }
    return;
}

float dequeue(queueNode** f, queueNode** b)
//dequeue function: removes the first node from the queue
{
    float data = NULL;

    if(*f != NULL)                //if the queue is NOT empty
    {
	data = (*f) -> appData;   //store removed data to be returned

        queueNode *temp = *f;     //hold position of node to be deleted
        *f = (*f) -> next;        //change front to new front
        free(temp);               //remove old front from memory

        if(*f == NULL)            //after each deletion, check to see is queue is supposed to be empty
	    *b = NULL;            //if the queue is to be empty, make the back pointer NULL
    }
    else
	printf("\nThe queue is already empty.");   //if the queue is empty going into the function, display error

    return data;
}

void printAll(queueNode *f, queueNode *b)
//printAll function: displays all nodes' data
{
    queueNode *temp = f;
    int count = 0;

    if(temp == NULL)
	printf("\nThe queue is empty.");
    while (temp != NULL)
    {  
	    printf("\nData in Position %u: %f", count++, (temp -> appData));  //display each element
	    temp = temp -> next;     //move the pointer to the next node
    }
    return;
}

bool isEmpty(queueNode *f)
//isEmpty function: returns true if queue is empty, false otherwise
{
    return (f == NULL);
}

void deleteAll(queueNode **f, queueNode **b)
//deleteeAll function: deletes all nodes as well as front and back pointers
{
    queueNode *temp;

    while(*f != NULL)//loop until queue is empty
    {
	temp = *f;            //hold position of node to be deleted
	*f = (*f) -> next;    //move front to the next node
	free(temp);           //delete old front position
    }
    free(*f);                 //delete front after all nodes are gone
    free(*b);                 //delete back after all noeds are gone

    return;
}
