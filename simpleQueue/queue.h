#include <stdlib.h>
#include <stdio.h>

struct queueNode
{
    float appData;    //contents of node
    queueNode *next;  //points to next node
};

//function prototypes (queueNode** indicates the pointer will be changed inside function)
void enqueue(float, queueNode**, queueNode**);	
float dequeue(queueNode**, queueNode **);
void printAll(queueNode*, queueNode*);
bool isEmpty(queueNode *);
void deleteAll(queueNode **, queueNode **);
