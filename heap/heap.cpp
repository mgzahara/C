#include <iostream>
#include "itemType.h"
#include "heap.h"

using namespace std;

Heap::Heap()
{
    size = 0;
}
Heap::~Heap()
{
}
void Heap::insert(ItemType insertData)
{
    ItemType temp; //hold one ItemType while current and parent switch
    int curr, par; //used as indicies, assigned later

    if(size >= MAXHEAP)
    {
	string fullHeap = "Sorry, but the heap is full. (insert)\n\n";

	throw fullHeap;
    }
    else
    {
	data[size + 1] = insertData;	
	size++;
    }


    curr = size; //current index
    par = curr / 2; //parent index
    
    //re-heap-ify
    while(data[curr] > data[par] && size > 1 && curr > 1)
    {   //while parent data is larger than current data,
	//the array is populated,
	//and current is not the root

	temp = data[par]; //hold parent node's data
	data[par] = data[curr]; //move new node into parent
	data[curr] = temp; //move parent data into 'new' node

	//move up the 'tree'
	curr = par;
	par = curr / 2;
    }
    return;
}
void Heap::extractMax()
{
    ItemType temp;
    int curr = 1, left = curr * 2, right = left + 1;
    bool bigR = false, bigL = false; //decides is left and/or right is larger than curr
    int* switchTo = NULL; //holds which index to switch curr to

    if(size <= 0)
    {
	string emptyHeap = "Sorry, but the heap is empty. (extractMax)\n\n";

        throw emptyHeap;
    }

    else
    {

	temp = data[size]; //hold last node
	data[size] = data[1]; //set last = to root
	data[1] = temp; //set root to last node
	size--;
	//'root' is now 'removed'

	while( (left <= size || right <= size)
		&& (data[left] > data[curr] || data[right] > data[curr]) )
	{   //if either child is larger than curr AND children are within the size constraint

	    //re-heap-ify
	    if(data[left] > data[curr] && left <= size)
	    {   //left child is larger
		bigL = true;
		switchTo = &left;
	    }
	    if(data[right] > data[curr] && right <= size)
	    {   //rigth child is larger
		bigR = true;
		switchTo = &right;
	    }
	    if(bigL && bigR)
	    {   //both children are larger, which of them is larger?

		if(data[left] > data[right])
		{
		    switchTo = &left;
		}
		else if(data[right] > data[left])
		{
		    switchTo = &right;
		}
	    }

	    if(switchTo == NULL)
	    {   //right value larger that curr is still in array, 
		//but not on tree, could let you into while loop
		//and not allow either bool to become true
		//making switchTo still NULL
		//causing a seg. fault in the code below

		return;
	    }

	    //switch curr w/ appropriate child
	    temp = data[curr];
	    data[curr] = data[*switchTo];
	    data[*switchTo] = temp;

 	    //reset
	    curr = *switchTo;
	    left = curr * 2;
	    right = left + 1;
	    bigL = false;
	    bigR = false;

	}
    }
}
void Heap::printAllIndicies()
{
    cout << "Printing all indicies\n";

    for(int i = 1; i <= MAXHEAP; i++)
    {
        cout << "index " << i << ": " << data[i] << endl;
    }
    cout << endl;
    return;
}
void Heap::printContents()
{
    string msg = "";
    if (size <= 0)
    {
	msg = " None";
    }
    cout << "Contents of heap:" << msg << endl;

    for(int i = 1; i <= size; i++)
    {
	cout << "index " << i << ": " << data[i] << endl;
    }
    cout << endl;
    return;
}

int Heap::getSize()
{
    return size;
}
