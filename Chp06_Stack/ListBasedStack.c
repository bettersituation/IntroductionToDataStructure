#include "stdio.h"
#include "stdlib.h"
#include "ListBasedStack.h"

void LBStackInit(ListStack* pstack)
{
	pstack->head = NULL;
}

int LBSIsEmpty(ListStack* pstack)
{
	if (pstack->head == NULL)
		return TRUE;
	return FALSE;
}

void LBSPush(ListStack* pstack, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = data;
	newNode->next = pstack->head;
	pstack->head = newNode;
}

Data LBSPop(ListStack* pstack)
{
	Node* hNode;
	Data rData;

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

Data LBSPeek(ListStack* pstack)
{
	if (pstack->head == NULL)
	{
		printf("STACK MEMORY ERROR\n");
		exit(-1);
	}

	return pstack->head->data;
}
