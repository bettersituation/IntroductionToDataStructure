#include <stdio.h>
#include <stdlib.h>
#include "AVLRebalance.h"

int GetHeight(BTreeNode* bst)
{
	int lHeight;
	int rHeight;

	if (bst == NULL)
	{
		return 0;
	}

	lHeight = 1 + GetHeight(bst->left);
	rHeight = 1 + GetHeight(bst->right);

	if (lHeight < rHeight)
	{
		return rHeight;
	}
	else
	{
		return lHeight;
	}
}

int GetHeightDiff(BTreeNode* bst)
{
	if (bst == NULL)
	{
		return 0;
	}

	int LSubH = GetHeight(bst->left);
	int RSubH = GetHeight(bst->right);

	return LSubH - RSubH;
}

int GetMaxHeightDiff(BTreeNode* bst)
{
	if (bst == NULL)
	{
		return 0;
	}

	int hd = GetHeightDiff(bst);
	int lhd = GetMaxHeightDiff(bst->left);
	int rhd = GetMaxHeightDiff(bst->right);

	if (hd * hd >= lhd * lhd && hd * hd >= rhd * rhd)
	{
		return hd;
	}
	else if (lhd * lhd >= hd * hd && lhd * lhd >= rhd * rhd)
	{
		return lhd;
	}
	else {
		return rhd;
	}
}

BTreeNode* RotateLL(BTreeNode* bst)
{
	BTreeNode* LNode = bst->left;

	bst->left = LNode->right;
	LNode->right = bst;

	return LNode;
}

BTreeNode* RotateRR(BTreeNode* bst)
{
	BTreeNode* RNode = bst->right;
	
	bst->right = RNode->left;
	RNode->left = bst;

	return RNode;
}

BTreeNode* RotateLR(BTreeNode* bst)
{
	BTreeNode* LNode = bst->left;
	BTreeNode* LRNode = bst->left->right;

	LNode->right = LRNode->left;
	bst->left = LRNode->right;

	LRNode->left = LNode;
	LRNode->right = bst;

	return LRNode;
}

BTreeNode* RotateRL(BTreeNode* bst)
{
	BTreeNode* RNode = bst->right;
	BTreeNode* RLNode = bst->right->left;

	bst->right = RLNode->left;
	RNode->left = RLNode->right;

	RLNode->left = bst;
	RLNode->right = RNode;

	return RLNode;
}

BTreeNode* SubRebalance1(BTreeNode* pNode)
{
	int hDiff = GetHeightDiff(pNode);

	if (hDiff <= 1 && hDiff >= -1)
	{
		return pNode;
	}

	BTreeNode* newNode;

	if (hDiff > 1)
	{
		if (GetHeightDiff(pNode->left) > 0)
		{
			newNode = RotateLL(pNode);
		}
		else
		{
			newNode = RotateLR(pNode);
		}
	}
	else
	{
		if (GetHeightDiff(pNode->right) > 0)
		{
			newNode = RotateRL(pNode);
		}
		else
		{
			newNode = RotateRR(pNode);
		}
	}

	return newNode;
}

void SubRebalance2(BTreeNode* ppNode, BTreeNode* pNode)
{
	if (ppNode == NULL || pNode == NULL)
	{
		return;
	}

	int hDiff = GetHeightDiff(pNode);
	if (hDiff <= 1 && hDiff >= -1)
	{
		return;
	}

	BTreeNode* newNode = SubRebalance1(pNode);

	if (ppNode->left == pNode)
	{
		ppNode->left = newNode;
	}
	else
	{
		ppNode->right = newNode;
	}
}

void HandsRebalance(BTreeNode* bst)
{
	if (bst == NULL)
	{
		return;
	}

	HandsRebalance(bst->left);
	SubRebalance2(bst, bst->left);

	HandsRebalance(bst->right);
	SubRebalance2(bst, bst->right);
}

BTreeNode* Rebalance0(BTreeNode* bst)
{
	HandsRebalance(bst);
	BTreeNode* newNode = SubRebalance1(bst);

	return newNode;
}

BTreeNode* Rebalance(BTreeNode** pRoot)
{
	int hDiff;
	BTreeNode* bst = *pRoot;

	while (1)
	{
		hDiff = GetMaxHeightDiff(bst);

		if (hDiff >= -1 && hDiff <= 1)
		{
			return bst;
		}

		bst = Rebalance0(bst);
	}
}
