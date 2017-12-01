#include <iostream>
#include <fstream>
#include <string>
#include "itemType.h"

using namespace std;

const int MAXHEAP = 16;

class Heap
{
    public:
	Heap();
	~Heap();

	void insert(ItemType insertData);
	void extractMax();
	void printAllIndicies();
	void printContents();
	int  getSize();

    private:
	ItemType data[MAXHEAP + 1];
	int size;



};
