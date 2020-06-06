#include "stdlib.h"
#include "DBLinkedList.h"

void ListInit2(List2* plist)
{
	plist->head = NULL;
	plist->cur = NULL;
	plist->numOfData = 0;
}

void LInsert2(List2* plist, Data2 data)
{
	Node2* newNode = (Node2*)malloc(sizeof(Node2));
	newNode->data = data;

	if (plist->numOfData == 0)
	{
		newNode->prev = NULL;
		newNode->next = NULL;
		plist->head = newNode;
	}
	else
	{
		newNode->next = plist->head;
		newNode->prev = NULL;
		plist->head->prev = newNode;
		plist->head = newNode;
	}
	(plist->numOfData)++;
}

int LFirst2(List2* plist, Data2* pdata)
{
	if (plist->numOfData == 0)
		return FALSE;

	plist->cur = plist->head;
	*pdata = plist->cur->data;
	
	return TRUE;
}

int LNext2(List2* plist, Data2* pdata)
{
	if (plist->head == NULL)
		return FALSE;

	if (plist->cur == NULL && plist->head != NULL)
	{
		plist->cur = plist->head;
		*pdata = plist->head->data;

		return TRUE;
	}
	
	if (plist->cur->next == NULL)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}

Data2 LRemove2(List2* plist)
{
	Data2 rData = plist->cur->data;
	Node2* rpos = plist->cur;

	if (rpos->prev == NULL && rpos->next == NULL)
	{
		plist->head = NULL;
		plist->cur = NULL;
	}
	else if (rpos->prev == NULL && rpos->next != NULL)
	{
		plist->head = rpos->next;
		plist->head->prev = NULL;
		plist->cur = NULL;
	}
	else
	{
		plist->cur = rpos->prev;
		plist->cur->next = rpos->next;
	}
	
	free(rpos);
	(plist->numOfData)--;

	return rData;
}

int LCount2(List2* plist)
{
	return plist->numOfData;
}
