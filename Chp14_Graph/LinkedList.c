#include "stdio.h"
#include "stdlib.h"
#include "LinkedList.h"


void ListInit(List* plist) {
	Node* dummyNode = (Node*)malloc(sizeof(Node));
	dummyNode->next = NULL;
	plist->head = dummyNode;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = plist->head->next;

	plist->head->next = newNode;
	(plist->numOfData)++;
}

void SInsert(List* plist, LData data)
{
	Node* tmpCur = plist->head;
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->numOfData == 0)
	{
		newNode->next = NULL;
		plist->head->next = newNode;
		(plist->numOfData)++;
		return;
	}

	while (tmpCur->next != NULL && plist->comp(data, tmpCur->next->data) != 0)
	{
		tmpCur = tmpCur->next;
	}
	newNode->next = tmpCur->next;
	tmpCur->next = newNode;

	(plist->numOfData)++;
}

void LInsert(List* plist, LData data)
{
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->numOfData == 0)
		return FALSE;

	plist->cur = plist->head->next;
	plist->before = plist->head;

	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List* plist, LData* pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;

	return TRUE;
}

LData LRemove(List* plist)
{
	LData data = plist->cur->data;

	plist->before->next = plist->cur->next;
	free(plist->cur);
	plist->cur = plist->before;

	(plist->numOfData)--;

	return data;
}

void SetSortRule(List* plist, int (*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}

int WhoIsPrecede(LData d1, LData d2)
{
	if (d1 < d2)
		return 0;
	else
		return 1;
}
