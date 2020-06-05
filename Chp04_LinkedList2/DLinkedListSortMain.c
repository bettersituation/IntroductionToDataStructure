#include "stdio.h"
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2)
{
	if (d1 < d2)
		return 0;
	else
		return 1;
}

int main(void)
{
	List list;
	List list2;
	int data;
	ListInit(&list);
	ListInit(&list2);

	SetSortRule(&list, WhoIsPrecede);

	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 33);
	LInsert(&list2, 11);
	LInsert(&list2, 22);
	LInsert(&list2, 11);
	LInsert(&list2, 22);
	LInsert(&list2, 33);

	printf("List 의 데이터 수: %d\n", list.numOfData);
	printf("List2 의 데이터 수: %d\n", list2.numOfData);

	if (LFirst(&list, &data))
	{
		if (data == 22)
			LRemove(&list);
		while (LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}

	printf("List 의 데이터 수: %d\n", list.numOfData);

	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n");

	if (LFirst(&list2, &data))
	{
		if (data == 22)
			LRemove(&list2);

		while (LNext(&list2, &data))
		{
			if (data == 22)
				LRemove(&list2);
		}
	}

	printf("List2 의 데이터 수: %d\n", list2.numOfData);

	if (LFirst(&list2, &data))
	{
		printf("%d ", data);

		while (LNext(&list2, &data))
			printf("%d ", data);
	}
}