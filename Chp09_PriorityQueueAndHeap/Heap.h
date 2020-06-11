#ifndef __HEAP_H__
#define __HEAP_H__

#define HEAP_LEN	100

#include "Data.h"
#include "PriorityComp.h"

typedef struct _heap
{
	int numOfData;
	Data heapArr[HEAP_LEN];
	PriorityComp* comp;
} Heap;

void HeapInit(Heap* ph, PriorityComp pc);
int HeapIsEmpty(Heap* ph);

void HeapInsert(Heap* ph, Data data);
Data HeapDelete(Heap* ph);

void PrintHeap(Heap* ph);

#endif