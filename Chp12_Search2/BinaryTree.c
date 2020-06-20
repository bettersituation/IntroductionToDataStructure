#include "stdio.h"
#include "stdlib.h"
#include "BinaryTree.h"

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* bt = (BTreeNode*)malloc(sizeof(BTreeNode));

	bt->left = NULL;
	bt->right = NULL;

	return bt;
}

Data GetData(BTreeNode* bt)
{
	return bt->data;
}

void SetData(BTreeNode* bt, Data data)
{
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
	return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt)
{
	return bt->right;
}

BTreeNode* RemoveLeftSubTree(BTreeNode* bt)
{
	BTreeNode* lNode = bt->left;
	bt->left = NULL;

	return lNode;
}

BTreeNode* RemoveRightSubTree(BTreeNode* bt)
{
	BTreeNode* rNode = bt->right;
	bt->right = NULL;

	return rNode;
}

void RemoveTree(BTreeNode* bt)
{
	BTreeNode* RightNode;

	if (bt == NULL)
	{
		return;
	}

	RightNode = bt->right;

	RemoveTree(bt->left);
	free(bt);
	RemoveTree(RightNode);
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	RemoveTree(main->left);
	main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	RemoveTree(main->right);
	main->right = sub;
}

void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	RemoveLeftSubTree(main);
	main->left = sub;
}

void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	RemoveRightSubTree(main);
	main->right = sub;
}

void InorderTraverse(BTreeNode* bt, VisitFuncPtr action, int withP)
{
	if (bt == NULL)
	{
		return;
	}

	if (withP && !(bt->data >= 0 && bt->data <= 9))
	{
		printf("(");
		InorderTraverse(bt->left, action, withP);
		action(bt->data);
		InorderTraverse(bt->right, action, withP);
		printf(")");
	}
	else
	{
		InorderTraverse(bt->left, action, withP);
		action(bt->data);
		InorderTraverse(bt->right, action, withP);
	}
}

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
	{
		return;
	}

	action(bt->data);
	if (bt->left != NULL || bt->right != NULL)
	{
		printf("[ ");
		PreorderTraverse(bt->left, action);
		PreorderTraverse(bt->right, action);
		printf("] ");
	}

}

void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
	{
		return;
	}

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}
