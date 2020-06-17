#include <stdlib.h>
#include "InterpolateSearch.h"
#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include "TraverseFunc.h"

int main(void)
{
	int arr[12] = { 1, 3, 5, 7, 9, 10, 14, 15, 18, 19, 20, 22 };

	ISearch(arr, 0, 11, 20);

	BTreeNode* bstRoot;
	BTreeNode* sNode;

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 5);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 4);
	BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 7);

	InorderTraverse(bstRoot, ShowData, -1);

	sNode = BSTDelete(&bstRoot, 3);
	printf("\n");
	printf("del Data %d\n", sNode->data);
	free(sNode);
	InorderTraverse(bstRoot, ShowData, -1);

	sNode = BSTDelete(&bstRoot, 8);
	printf("\n");
	printf("del Data %d\n", sNode->data);
	free(sNode);
	InorderTraverse(bstRoot, ShowData, -1);

	sNode = BSTDelete(&bstRoot, 1);
	printf("\n");
	printf("del Data %d\n", sNode->data);
	free(sNode);
	InorderTraverse(bstRoot, ShowData, -1);

	sNode = BSTDelete(&bstRoot, 6);
	printf("\n");
	printf("del Data %d\n", sNode->data);
	free(sNode);
	InorderTraverse(bstRoot, ShowData, -1);

	return 0;
}