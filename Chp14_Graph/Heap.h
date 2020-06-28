#ifndef __HEAP_H__
#define __HEAP_H__

#define HEAP_LEN	100

#include "Edge.h"
#include "PriorityComp.h"

typedef struct _heap
{
	int numOfData;
	Edge heapArr[HEAP_LEN];
	PriorityComp* comp;
} Heap;

void HeapInit(Heap* ph, PriorityComp pc);
int HeapIsEmpty(Heap* ph);

void HeapInsert(Heap* ph, Edge data);
Edge HeapDelete(Heap* ph);

void PrintHeap(Heap* ph);

#endif
