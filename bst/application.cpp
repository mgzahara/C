#include <iostream>
#include <fstream>
#include "itemType.h"
#include "binaryTreeClass.h"

using namespace std;

int main(int argc, char *argv[])
{
    ItemType fileData, find;
    char command;
    ifstream infile;
    BTree employeeTree;

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
                // call my BTree insert method
                employeeTree.insert(fileData);
                break;

            case 'r':
            case 'R':
                infile >> fileData;
                // call my BTree remove method
		employeeTree.remove(fileData);
                break;

	    case 'f':
	    case 'F':
		infile >> fileData;
		find = employeeTree.find(fileData);

		if (find.getID() >= 0)
		    cout << "Found it! \n" << find << endl;
		else
		    cout << "Data not found :(\n";
		break;

            case 'p':
            case 'P':
                // call the in order print
                employeeTree.printInOrder();
                break;

	    case 'b':
	    case 'B':
		// call the pre order print
		employeeTree.printPreOrder();
                break;

	    case 'a':
            case 'A':
                // call the post order print
                employeeTree.printPostOrder();
                break;

            case 'e':
            case 'E':
                // call my BTree isEmpty method
                if (employeeTree.isEmpty())
                    cout << "The list is Empty.\n";
                else
                    cout << "The list is not Empty.\n";
                break;

	    case 'd':
	    case 'D':
		//call destructor manually
		employeeTree.~BTree();

            case 'q':
            case 'Q': break;

            default:
                cout << "ERROR: Bad command " << command << " in file " << argv[1] << endl;
                cout << "Shutting down...\n";
                command = 'q';
                break;
        }
    }

    employeeTree.~BTree();

    infile.close();

    return 0;
}
