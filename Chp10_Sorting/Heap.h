#ifndef __HEAP_H__
#define __HEAP_H__

#define HEAP_LEN	100

#define TRUE	1
#define FALSE	0

#include "Priority.h"

typedef int Data;

typedef struct _heap
{
	int numOfData;
	Data heapArr[HEAP_LEN];
	Priority* p;
} Heap;

void HeapInit(Heap* ph, Priority p);
int HeapIsEmpty(Heap* ph);

void HeapInsert(Heap* ph, Data data);
Data HeapDelete(Heap* ph);

void PrintHeap(Heap* ph);

#endif
