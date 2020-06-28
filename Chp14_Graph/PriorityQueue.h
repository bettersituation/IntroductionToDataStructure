#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include "Edge.h"
#include "PriorityComp.h"
#include "Heap.h"

typedef struct _priQ
{
	Heap* ph;
} PriQ;

void PriQInit(PriQ* ppq, PriorityComp pc);
int PriQIsEmpty(PriQ* ppq);

void PEnqueue(PriQ* ppq, Edge data);
Edge PDequeue(PriQ* ppq);

#endif
