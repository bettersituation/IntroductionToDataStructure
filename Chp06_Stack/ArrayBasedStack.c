#include "stdio.h"
#include "stdlib.h"
#include "ArrayBasedStack.h"

void ABStackInit(ArrayStack* pstack)
{
	pstack->topIndex = -1;
}

int ABSIsEmpty(ArrayStack* pstack)
{
	if (pstack->topIndex == -1)
		return TRUE;
	return FALSE;
}

void ABSPush(ArrayStack* pstack, Data data)
{
	pstack->stackArr[++(pstack->topIndex)] = data;
}

Data ABSPop(ArrayStack* pstack)
{
	if (ABSIsEmpty(pstack))
	{
		printf("스택 메모리 에러\n");
		exit(-1);
	}

	return pstack->stackArr[(pstack->topIndex)--];
}

Data ABSPeek(ArrayStack* pstack) 
{
	if (ABSIsEmpty(pstack))
	{
		printf("스택 메모리 에러");
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex];
}
