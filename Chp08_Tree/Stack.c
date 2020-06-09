#include "stdio.h"
#include "stdlib.h"
#include "Stack.h"

void StackInit(Stack* pstack)
{
	pstack->head = NULL;
}

int SIsEmpty(Stack* pstack)
{
	if (pstack->head == NULL)
		return TRUE;
	return FALSE;
}

void SPush(Stack* pstack, BTreeNode* sData)
{
	SNode* newNode = (SNode*)malloc(sizeof(SNode));

	newNode->data = sData;
	newNode->next = pstack->head;
	pstack->head = newNode;
}

BTreeNode* SPop(Stack* pstack)
{
	SNode* hNode;
	BTreeNode* rData;

	if (pstack->head == NULL)
	{
		printf("STACK MEMORY ERROR\n");
		exit(-1);
	}

	hNode = pstack->head;
	rData = hNode->data;
	pstack->head = hNode->next;

	free(hNode);

	return rData;
}

BTreeNode* SPeek(Stack* pstack)
{
	if (pstack->head == NULL)
	{
		printf("STACK MEMORY ERROR\n");
		exit(-1);
	}

	return pstack->head->data;
}
