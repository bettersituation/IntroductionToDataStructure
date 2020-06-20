#ifndef __AVL_REBALANCE_H__
#define __AVL_REBALANCE_H__

#include "BinarySearchTree.h"

int GetHeight(BTreeNode* bst);
int GetHeightDiff(BTreeNode* bst);
BTreeNode* RotateLL(BTreeNode* bst);
BTreeNode* RotateRR(BTreeNode* bst);
BTreeNode* RotateLR(BTreeNode* bst);
BTreeNode* RotateRL(BTreeNode* bst);
BTreeNode* Rebalance(BTreeNode** pRoot);

#endif