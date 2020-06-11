#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include "Data.h"
#include "PriorityComp.h"
#include "Heap.h"

typedef struct _priQ
{
	Heap* ph;
} PriQ;

void PriQInit(PriQ* ppq, PriorityComp pc);
int PriQIsEmpty(PriQ* ppq);

void Enqueue(PriQ* ppq, Data data);
Data Dequeue(PriQ* ppq);

#endif