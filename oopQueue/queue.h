#ifndef QUEUE
#define QUEUE
#define DEBUG 1

#include "appData.h"
class Queue
{
    public:
	Queue();		// Constructor
	~Queue();		// Destructor
	bool isEmpty();		// Empty queue test
	void enqueue(AppData data);	// Insert data into the queue
	AppData dequeue();	// Delete data from the queue
	void printAll();	// Prettyprint the contents of the queue

    private:
	struct QueueNode
	{
	    AppData item;
	    QueueNode *next;
	};

	QueueNode *front, *back;
};
#endif

