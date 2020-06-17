#include <stdio.h>
#include "TraverseFunc.h"

void ShowData(Data data)
{
	printf("%d ", data);
}

void ShowAsExp(Data data)
{
	if (0 <= data && data <= 9)
	{
		printf("%d", data);
	}
	else
	{
		printf(" %c ", data);
	}
}
