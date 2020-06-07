#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#include "StackData.h"

typedef struct _node
{
	Data data;
	struct _node* next;
} Node;

typedef struct _listStack
{
	Node* head;
} ListStack;

void LBStackInit(ListStack* pstack);
int LBSIsEmpty(ListStack* pstack);

void LBSPush(ListStack* pstack, Data data);
Data LBSPop(ListStack* pstack);
Data LBSPeek(ListStack* pstack);


#endif