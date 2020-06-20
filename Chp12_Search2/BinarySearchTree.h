#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "BinaryTree.h"

void BSTMakeAndInit(BTreeNode** pRoot);
Data BSTGetNodeData(BTreeNode* bst);
void BSTInsert(BTreeNode** pRoot, Data data);
BTreeNode* BSTSearch(BTreeNode* bst, Data target);
BTreeNode* BSTDelete(BTreeNode** pRoot, Data target);

#endif