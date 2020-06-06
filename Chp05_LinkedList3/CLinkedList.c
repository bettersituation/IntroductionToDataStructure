#include "stdio.h"
#include "stdlib.h"
#include "CLinkedList.h"


void ListInit(List* plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsertTail(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	if (plist->numOfData == 0)
	{
		newNode->next = newNode;
		plist->tail = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}
	++(plist->numOfData);
}

void LInsertHead(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->numOfData == 0)
	{
		newNode->next = newNode;
		plist->tail = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}
	++(plist->numOfData);
}

int LFirst(List* plist, Data* pdata)
{
	if (plist->numOfData == 0)
		return FALSE;

	plist->before = plist->tail;
	plist->cur = plist->tail->next;
	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List* plist, Data* pdata)
{
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}

Data LRemove(List* plist)
{
	Data rData = plist->cur->data;

	if (plist->numOfData == 1)
	{
		free(plist->cur);
		plist->tail = NULL;
		plist->cur = NULL;
		plist->before = NULL;
		plist->numOfData = 0;
	}
	else
	{
		plist->before->next = plist->cur->next;
		if (plist->tail == plist->cur)
			plist->tail = plist->before;

		free(plist->cur);
		plist->cur = plist->before;
		(plist->numOfData)--;
	}

	return rData;
}

int LCount(List* plist)
{
	return plist->numOfData;
}
