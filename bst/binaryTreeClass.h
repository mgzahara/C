#include <iostream>
#include <fstream>
#include "itemType.h"

using namespace std;

class BTree
{
    public:
        BTree();
        ~BTree();

        void insert(ItemType insertData);
        void remove(ItemType removeData);

        void printInOrder();
        void printPreOrder();
        void printPostOrder();

	ItemType find(ItemType);
        bool isEmpty();
	ItemType max();
	ItemType min();


    private:
        struct BTNode
        {
            BTNode *left;
            ItemType data;
            BTNode *right;
        };
        BTNode *root;

        void destructorHelper(BTNode*);
        void insertHelper(BTNode* &, BTNode*, ItemType);
        void removeHelper(BTNode* &, BTNode*, ItemType);

        void printInOrderHelper(BTNode*);
        void printPreOrderHelper(BTNode*);
        void printPostOrderHelper(BTNode*);

        ItemType findHelper(ItemType, BTNode*);
	ItemType maxHelper();
	ItemType minHelper();
};
