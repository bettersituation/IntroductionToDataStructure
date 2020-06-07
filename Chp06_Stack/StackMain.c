#include "stdio.h"
#include "ArrayBasedStack.h"
#include "ListBasedStack.h"

int main(void)
{
	ArrayStack arrayStack;
	ListStack listStack;

	ABStackInit(&arrayStack);
	LBStackInit(&listStack);

	ABSPush(&arrayStack, 'a');
	ABSPush(&arrayStack, 'b');
	ABSPush(&arrayStack, 'c');
	ABSPush(&arrayStack, 'd');
	ABSPush(&arrayStack, 'e');

	LBSPush(&listStack, 'a');
	LBSPush(&listStack, 'b');
	LBSPush(&listStack, 'd');
	LBSPush(&listStack, 'f');
	LBSPush(&listStack, 'c');

	while (!ABSIsEmpty(&arrayStack))
		printf("%c ", ABSPop(&arrayStack));
	printf("\n");

	while (!LBSIsEmpty(&listStack))
		printf("%c ", LBSPop(&listStack));

	return 0;
}