#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Stack.h"
#include "BinaryTree.h"
#include "TraverseFunc.h"

BTreeNode* MakeExpTree(char exp[])
{
	Stack stack;
	BTreeNode* pnode;

	int explen = strlen(exp);
	
	StackInit(&stack);

	for (int i = 0; i < explen; i++)
	{
		pnode = MakeBTreeNode();

		if (isdigit(exp[i]))
		{
			SetData(pnode, (Data) exp[i] - '0');
		}
		else
		{
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
			SetData(pnode, (Data) exp[i]);
		}

		SPush(&stack, pnode);
	}

	return SPop(&stack);
}


int EvaluateExpTree(BTreeNode* bt)
{
	return 1;
}

void ShowPrefixTypeExp(BTreeNode* bt)
{
	PreorderTraverse(bt, ShowAsExp);
}
void ShowInfixTypeExp(BTreeNode* bt)
{
	InorderTraverse(bt, ShowAsExp, 1);
}

void ShowPostfixTypeExp(BTreeNode* bt)
{
	PostorderTraverse(bt, ShowAsExp);
}
