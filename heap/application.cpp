#include <iostream>
#include <fstream>
#include <string>
#include "itemType.h"
#include "heap.h"

using namespace std;

int main(int argc, char *argv[])
{
    ItemType fileData;
    char command;
    ifstream infile;
    Heap myHeap;
    int temp;

    if (argc != 2)
    {
        cout << "ERROR: Wrong number of arguments\n";
        cout << "Usage: " << argv[0] << " <input filename>\n";
        return(-1);
    }

    else
    {
        cout << "Trying to open file " << argv[1] << endl;
        fflush(stdout);
        infile.open(argv[1]);
        if (infile.fail())
        {
            cout << "ERROR: Could not open file " << argv[1] << " for input.\n";
            return(-2);
        }
        cout << "Successfully opened.\n\n";
        fflush(stdout);
    }

    while (command != 'q' && command != 'Q')
    {
        infile >> command;
        switch (command)
        {
            case 'i':
            case 'I':
                infile >> fileData;
                // call my insert method
		try
		{
		    myHeap.insert(fileData);
		}
		catch(string fullHeap)
		{
		    cout << fullHeap;
		    fflush(stdout);
		}
                break;

            case 'e':
            case 'E':
                // call my extract max method
		try
		{
		    myHeap.extractMax();
		}
		catch(string emptyHeap)
		{
		    cout << emptyHeap;
		    fflush(stdout);
		}
                break;

            case 'p':
            case 'P':
                // call the print all indicies method
		    myHeap.printAllIndicies();
                break;

	    case 's':
	    case 'S':
		//call size of heap method
		temp = myHeap.getSize();
		cout << "Heap size is " << temp << endl;
		break;

	    case 'c':
	    case 'C':
		//call contents of heap method
		myHeap.printContents();
		break;

            case 'd':
            case 'D':
                //call destructor manually

		break;

            case 'q':
            case 'Q': break;

            default:
                cout << "ERROR: Bad command " << command << " in file " << argv[1] << endl;
                cout << "Shutting down...\n";
                command = 'q';
                break;
        }
    }

    //call destructor here

    infile.close();
    return 0;
}

