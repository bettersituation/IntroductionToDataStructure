#ifndef __STACK_H__
#define __STACK_H__

#define TRUE	1
#define FALSE	0

#include "BinaryTree.h"

typedef struct _stackNode
{
	BTreeNode* data;
	struct _stackNode* next;
} SNode;

typedef struct _listStack
{
	SNode* head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, BTreeNode* sData);
BTreeNode* SPop(Stack* pstack);
BTreeNode* SPeek(Stack* pstack);


#endif