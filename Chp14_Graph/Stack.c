#include "stdio.h"
#include "stdlib.h"
#include "Stack.h"

void StackInit(Stack* pstack)
{
	pstack->topIndex = -1;
}

int SIsEmpty(Stack* pstack)
{
	if (pstack->topIndex == -1)
		return TRUE;
	return FALSE;
}

void SPush(Stack* pstack, Data data)
{
	pstack->stackArr[++(pstack->topIndex)] = data;
}

Data SPop(Stack* pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("스택 메모리 에러\n");
		exit(-1);
	}

	return pstack->stackArr[(pstack->topIndex)--];
}

Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("스택 메모리 에러");
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex];
}
