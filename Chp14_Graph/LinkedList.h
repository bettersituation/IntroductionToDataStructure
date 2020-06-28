#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "Data.h"

typedef struct _linkedlist
{
	Node* head;
	Node* cur;
	Node* before;
	int numOfData;
	int (*comp)(LData d1, LData d2);
} LinkedList;

typedef LinkedList List;

void ListInit(List* plist);
void LInsert(List* plist, LData data);

int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);

LData LRemove(List* plist);
int LCount(List* plist);

void SetSortRule(List* plist, int (*comp)(LData d1, LData d2));
int WhoIsPrecede(LData d1, LData d2);

#endif