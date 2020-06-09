#include <stdio.h>
#include "BinaryTree.h"
#include "TraverseFunc.h"
#include "ExpressionTree.h"

int main(void)
{
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();
	BTreeNode* bt5 = MakeBTreeNode();
	BTreeNode* bt6 = MakeBTreeNode();
	char exp[] = "19+4*2/";

	BTreeNode* expTree = MakeExpTree(exp);

	ShowInfixTypeExp(expTree);
	printf("\n");

	ShowPostfixTypeExp(expTree);
	printf("\n");

	ShowPrefixTypeExp(expTree);
	printf("\n");

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	SetData(bt5, 5);
	SetData(bt6, 6);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	MakeRightSubTree(bt2, bt5);
	MakeRightSubTree(bt3, bt6);

	InorderTraverse(bt1, ShowData, 0);
	printf("\n");

	PreorderTraverse(bt1, ShowData);
	printf("\n");

	PostorderTraverse(bt1, ShowData);
	printf("\n");

	return 0;
}