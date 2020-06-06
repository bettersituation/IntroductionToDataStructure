#include "stdio.h"
#include "CLinkedList.h"
#include "DBLinkedList.h"

int main(void)
{
	List list;
	List2 list2;
	int data, data2, nodeNum;

	ListInit(&list);
	LInsertTail(&list, 3);
	LInsertTail(&list, 4);
	LInsertTail(&list, 5);
	LInsertHead(&list, 2);
	LInsertHead(&list, 1);

	ListInit2(&list2);
	LInsert2(&list2, 3);
	LInsert2(&list2, 4);
	LInsert2(&list2, 5);
	LInsert2(&list2, 2);
	LInsert2(&list2, 1);


	printf("C Linked List 개수: %d\n", list.numOfData);

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		for (int i = 0; i < LCount(&list) * 3 - 1; i++)
		{
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}
	printf("\n");

	printf("DB Linked List 개수: %d\n", list2.numOfData);

	if (LFirst2(&list2, &data2))
	{
		printf("%d ", data2);

		for (int i = 0; i < LCount2(&list2) * 3 - 1; i++)
		{
			if (LNext2(&list2, &data2))
				printf("%d ", data2);
		}
	}
	printf("\n");

	nodeNum = LCount(&list);

	if (nodeNum != 0)
	{
		LFirst(&list, &data);
		if (data % 2 == 0)
			LRemove(&list);

		for (int i = 0; i < nodeNum - 1; i++)
		{
			LNext(&list, &data);
			if (data % 2 == 0)
				LRemove(&list);
		}
	}

	printf("C Linked List 개수: %d\n", list.numOfData);


	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		for (int i = 0; i < LCount(&list) - 1; i++)
		{
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}
	printf("\n");

	nodeNum = LCount2(&list2);

	if (nodeNum != 0)
	{
		LFirst2(&list2, &data2);
		if (data2 % 2 == 1)
			LRemove2(&list2);

		for (int i = 0; i < nodeNum - 1; i++)
		{
			LNext2(&list2, &data2);
			if (data2 % 2 == 0)
				LRemove2(&list2);
		}
	}

	printf("DB Linked List 개수: %d\n", list2.numOfData);


	if (LFirst2(&list2, &data2))
	{
		printf("%d ", data2);

		for (int i = 0; i < LCount2(&list2) - 1; i++)
		{
			if (LNext2(&list2, &data2))
				printf("%d ", data2);
		}
	}

	return 0;
}