#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

typedef int Data2;

typedef struct _node2
{
	Data2 data;
	struct _node2* prev;
	struct _node2* next;
} Node2;

typedef struct _DBLL
{
	Node2* head;
	Node2* cur;
	int numOfData;
} DBList;

typedef DBList List2;

void ListInit2(List2* plist);
void LInsert2(List2* plist, Data2 data);

int LFirst2(List2* plist, Data2* pdata);
int LNext2(List2* plist, Data2* pdata);
Data2 LRemove2(List2* plist);
int LCount2(List2* plist);

#endif