#include <stdlib.h>
#include "PriorityQueue.h"
#include "Heap.h"

void PriQInit(PriQ* ppq, PriorityComp pc)
{
	Heap* ph = (Heap*)malloc(sizeof(Heap));

	HeapInit(ph, pc);

	ppq->ph = ph;
}

int PriQIsEmpty(PriQ* ppq)
{
	return HeapIsEmpty(ppq->ph);
}

void PEnqueue(PriQ* ppq, Edge data)
{
	HeapInsert(ppq->ph, data);
}

Edge PDequeue(PriQ* ppq)
{
	return HeapDelete(ppq->ph);
}
