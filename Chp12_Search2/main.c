#include <stdio.h>
#include "BinarySearchTree.h"
#include "BinaryTree.h"
#include "AVLRebalance.h"
#include "TraverseFunc.h"

int main(void)
{
	BTreeNode* avlRoot;
	BSTMakeAndInit(&avlRoot);

	for (int i = 1; i < 37; i++)
	{
		BSTInsert(&avlRoot, i);
		printf("Root Node: %d Height %d\n", GetData(avlRoot), GetHeight(avlRoot));
	}

	PreorderTraverse(avlRoot, ShowData);
	printf("\n");
	printf("\n");
	printf("\n");

	for (int i = 1; i < 37; i++)
	{
		if (i % 3 == 0)
		{
			BSTDelete(&avlRoot, i);
		}
	}

	PreorderTraverse(avlRoot, ShowData);
	
	return 0;
}