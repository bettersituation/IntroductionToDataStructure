#ifndef __AB_STACK_H__
#define __AB_STACK_H__
#define STACK_LEN	100

#include "StackData.h"

typedef struct _arrayStack
{
	Data stackArr[STACK_LEN];
	int topIndex;
} ArrayStack;

void ABStackInit(ArrayStack* pstack);
int ABSIsEmpty(ArrayStack* pstack);

void ABSPush(ArrayStack* pstack, Data data);
Data ABSPop(ArrayStack* pstack);
Data ABSPeek(ArrayStack* pstack);

#endif