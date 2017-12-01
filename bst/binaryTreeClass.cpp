#include <iostream>
#include "itemType.h"
#include "binaryTreeClass.h"

using namespace std;

BTree::BTree()
{
    root = NULL;
}

BTree::~BTree()
{
    destructorHelper(root);
    root = NULL;
}

void BTree::destructorHelper(BTNode* current)
{
    if (current != NULL)
    {
        destructorHelper(current -> left);
        destructorHelper(current -> right);
	delete(current);
    }

    return;
}

void BTree::insert(ItemType insertData)
{
    insertHelper(root, root, insertData);
    return;
}

void BTree::insertHelper(BTNode* &parent, BTNode* current, ItemType insertData)
{

    if(current == NULL)
    {
	BTNode* newPtr  = new(BTNode);
	newPtr -> data  = insertData;
	newPtr -> left  = NULL;
	newPtr -> right = NULL;

	parent = newPtr;
    }
    else if(insertData < current -> data)
	insertHelper(current -> left, current -> left, insertData);
    else if(insertData > current -> data)
	insertHelper(current -> right, current -> right, insertData);
    else
	//insertData == current -> data so we overwrite
	current -> data = insertData;



/*
data passed as (ItemType insertData, BTNode* current)

    if(current == root && root == NULL)
    {//set root to new data
	BTNode *newNode;
        newNode = (BTNode*)malloc(sizeof(BTNode));

        root = newNode;
        newNode -> data  = insertData;
        newNode -> left  = NULL;
        newNode -> right = NULL;
    }
    else if(insertData < current -> data)
    {
	if(current -> left == NULL)
	{//leaf case
	    BTNode *newNode;
	    newNode = (BTNode*)malloc(sizeof(BTNode));

	    newNode -> data  = insertData;
	    newNode -> left  = NULL;
	    newNode -> right = NULL;

	    current -> left  = newNode;
	}
	else if(current -> left != NULL)
	{//recurse down left
	    insertHelper(insertData, current -> left);
	}
    }
    else if (insertData > current -> data)
    {
	if(current -> right == NULL)
        {//leaf case
	    BTNode *newNode;
	    newNode = (BTNode*)malloc(sizeof(BTNode));

            newNode -> data  = insertData;
            newNode -> left  = NULL;
            newNode -> right = NULL;

            current -> right = newNode;
        }
        else if(current -> right != NULL)
        {//recurse down right
            insertHelper(insertData, current -> right);
        }
    }
    else if(insertData == current -> data)
    {//over write pre existing data
	current -> data = insertData;
    }
*/
    return;
}

void BTree::remove(ItemType removeData)
{
    cout << "\nAttempting to remove " << removeData;
    return removeHelper(root, root, removeData);
}

void BTree::removeHelper(BTNode* &parent, BTNode* current, ItemType removeData)
{
    if(current == NULL)
    {// list is empty or reached end of tree
	cout << "Item not found.\n";
	return;
    }
    else
    {
	if(removeData == current -> data)
	{// removeData has been found, now which case is it?
	    if(current -> left == NULL && current -> right == NULL)
	    {// no child case
		delete(current);
		parent = NULL;

		cout << "Success!\n";
	    }
	    else if(current -> left == NULL && current -> right != NULL)
	    {// first one child case
		parent = (current -> right);
		current -> right = NULL;
                delete(current);

		cout << "Success!\n";
	    }
	    else if(current -> left != NULL && current -> right == NULL)
	    {// second one child case
		parent = (current -> left);
		current -> left = NULL;
                delete(current);

		cout << "Success!\n";
	    }
	    else
	    {// two child case
		BTNode* inOrderPred = current -> left;

		while(inOrderPred -> right != NULL)
		{// find in order predecessor
		    inOrderPred = inOrderPred -> right;
		}

		current -> data = inOrderPred -> data;
		removeHelper(current -> left, current -> left, current -> data);
		
		cout << "Success!\n";
	    }
	}
	else if(removeData < current -> data)
	{
	    removeHelper(current -> left, current -> left, removeData);
	}
	else if(removeData > current -> data)
	{
	    removeHelper(current -> right, current -> right, removeData);
	}
    }
    return;
}

void BTree::printInOrder()
{
    cout << "\nPrint In Order\n";
    fflush(stdout);

    printInOrderHelper(root);
    return;
}
void BTree::printInOrderHelper(BTNode* current)
{

    if (current != NULL)
    {
        printInOrderHelper(current -> left);

        cout << (current -> data);
        fflush(stdout);

        printInOrderHelper(current -> right);
    }
    return;
}

void BTree::printPreOrder()
{
    cout << "\nPrint Pre Order\n";
    fflush(stdout);

    printPreOrderHelper(root);
    return;
}
void BTree::printPreOrderHelper(BTNode* current)
{
    if (current != NULL)
    {
        cout << (current -> data);
        fflush(stdout);

        printPreOrderHelper(current -> left);

        printPreOrderHelper(current -> right);
    }

    return;
}

void BTree::printPostOrder()
{
    cout << "\nPrint Post Order\n";
    fflush(stdout);

    printPostOrderHelper(root);
    return;
}
void BTree::printPostOrderHelper(BTNode* current)
{
    if (current != NULL)
    {
        printPostOrderHelper(current -> left);

        printPostOrderHelper(current -> right);

        cout << (current -> data);
        fflush(stdout);

    }
    return;
}

ItemType BTree::find(ItemType findData)
{
    cout << "\nLooking for " << findData;
    return findHelper(findData, root);
}

ItemType BTree::findHelper(ItemType findData, BTNode* current)
{
    if(current == NULL)
    {
	ItemType dummy;
	return dummy;
    }
    else
    {
        if(findData < current -> data)
        {
	    if(current -> left != NULL)
	    {//recurse on left
	        return findHelper(findData, current -> left);
	    }
	    else
	    {//reached end of branch
	        ItemType dummy;
	        return dummy;
	    }
        }
        else if(findData > current -> data)
        {
	    if(current -> right != NULL)
	    {//recurse on right
	        return findHelper(findData, current -> right);
	    }
	    else
	    {//reached end of branch
	        ItemType dummy;
	        return dummy;
	    }
        }
        else
        {
	    ItemType dummy;
	    dummy = current -> data;
	    return dummy;
        }
    }
}

bool BTree::isEmpty()
{
    return(root == NULL);
}

ItemType BTree::max()
{
    ItemType temp;
    BTNode* current = root;

    while(current != NULL)
    {
	temp = current -> data;
	current = current -> right;
    }

    return temp;
}

ItemType BTree::min()
{
    ItemType temp;
    BTNode* current = root;

    while(current != NULL)
    {
        temp = current -> data;
        current = current -> left;
    }

    return temp;

}
