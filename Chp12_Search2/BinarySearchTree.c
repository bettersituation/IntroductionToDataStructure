#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include "AVLRebalance.h"

void BSTMakeAndInit(BTreeNode** pRoot)
{
	*pRoot = NULL;
}

Data BSTGetNodeData(BTreeNode* bst)
{
	return GetData(bst);
}

void BSTInsert(BTreeNode** pRoot, Data data)
{
	BTreeNode* pNode = NULL;
	BTreeNode* cNode = *pRoot;
	BTreeNode* nNode = NULL;

	while (cNode != NULL)
	{
		if (data == GetData(cNode))
		{
			return;
		}

		pNode = cNode;

		if (data < GetData(cNode))
		{
			cNode = GetLeftSubTree(cNode);
		}
		else
		{
			cNode = GetRightSubTree(cNode);
		}
	}

	nNode = MakeBTreeNode();
	SetData(nNode, data);

	if (pNode != NULL)
	{
		if (data < GetData(pNode))
		{
			MakeLeftSubTree(pNode, nNode);
		}
		else
		{
			MakeRightSubTree(pNode, nNode);
		}
	}
	else
	{
		*pRoot = nNode;
	}

	BTreeNode* root = Rebalance(pRoot);
	*pRoot = root;
}

BTreeNode* BSTSearch(BTreeNode* bst, Data target)
{
	BTreeNode* cNode = bst;

	while (cNode != NULL)
	{
		if (target == GetData(cNode))
		{
			return cNode;
		}
		else if (target < GetData(cNode))
		{
			cNode = GetLeftSubTree(cNode);
		}
		else
		{
			cNode = GetRightSubTree(cNode);
		}
	}

	printf("There does not exist %d in the tree\n", target);

	return NULL;
}

BTreeNode* BSTDelete(BTreeNode** pRoot, Data target)
{
	BTreeNode* pVRoot = MakeBTreeNode();
	BTreeNode* pNode = pVRoot;
	BTreeNode* cNode = *pRoot;
	BTreeNode* dNode;

	ChangeRightSubTree(pVRoot, *pRoot);

	while (cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;

		if (target < GetData(cNode))
		{
			cNode = GetLeftSubTree(cNode);
		}
		else
		{
			cNode = GetRightSubTree(cNode);
		}
	}

	if (cNode == NULL)
	{
		return NULL;
	}

	dNode = cNode;

	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)
		{
			RemoveLeftSubTree(pNode);
		}
		else
		{
			RemoveRightSubTree(pNode);
		}
	}

	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode* dcNode;

		if (GetLeftSubTree(dNode) != NULL)
		{
			dcNode = GetLeftSubTree(dNode);
		}
		else
		{
			dcNode = GetRightSubTree(dNode);
		}

		if (GetLeftSubTree(pNode) == dNode)
		{
			ChangeLeftSubTree(pNode, dcNode);
		}
		else
		{
			ChangeRightSubTree(pNode, dcNode);
		}
	}

	else
	{
		BTreeNode* mNode = GetRightSubTree(dNode);
		BTreeNode* mpNode = dNode;
		int delData;

		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		delData = GetData(dNode);
		SetData(dNode, GetData(mNode));

		if (GetLeftSubTree(mpNode) == mNode)
		{
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		}
		else
		{
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
		}

		dNode = mNode;
		SetData(dNode, delData);
	}

	if (GetRightSubTree(pVRoot) != *pRoot)
	{
		*pRoot = GetRightSubTree(pVRoot);
	}

	free(pVRoot);

	BTreeNode* root = Rebalance(pRoot);
	*pRoot = root;

	return dNode;
}
