#include <iostream> 
#include <fstream> 
#include "itemType.h" 
#include "linkedListClass.h"

using namespace std; 

int main(int argc, char *argv[]) 
{
    ItemType fileData;
    char command;
    ifstream infile;
    LinkedList employeeList;

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
	cout << "Successfully opened.\n";
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
		// call my list's insert method
		employeeList.insert(fileData);
		break;

	    case 'r':
	    case 'R':
		infile >> fileData;
		// call the remove method in your list
		employeeList.remove(fileData);
		break;

	    case 'p':
	    case 'P':
		// call the print all method in the list
		employeeList.printAll();
		break;

	    case 'e':
	    case 'E':
		// call the is empty method in our list
		if (employeeList.isEmpty())
		    cout << "The list is Empty.\n";
		else
		    cout << "The list is not Empty.\n";
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

    employeeList.~LinkedList();

    infile.close();

    return 0; 
}
