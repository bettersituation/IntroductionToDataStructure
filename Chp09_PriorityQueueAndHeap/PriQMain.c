#include <stdio.h>
#include "Heap.h"
#include "PriorityQueue.h"
#include "PriorityComp.h"

int main(void)
{
	Heap ph;
	PriQ ppq;

	HeapInit(&ph, IsLess);
	PriQInit(&ppq, IsLess);

	HeapInsert(&ph, 5);
	HeapInsert(&ph, 3);
	HeapInsert(&ph, 4);
	HeapInsert(&ph, 1);
	HeapInsert(&ph, 6);
	HeapInsert(&ph, 4);
	HeapInsert(&ph, 5);
	HeapInsert(&ph, 7);

	Enqueue(&ppq, 5);
	Enqueue(&ppq, 3);
	Enqueue(&ppq, 4);
	Enqueue(&ppq, 1);
	Enqueue(&ppq, 6);
	Enqueue(&ppq, 4);
	Enqueue(&ppq, 5);
	Enqueue(&ppq, 7);

	printf("Heap Structure\n");
	PrintHeap(&ph);
	printf("\n");

	printf("del from q: %d\n", Dequeue(&ppq));
	printf("del from heap: %d\n", HeapDelete(&ph));
	printf("Heap Structure\n");
	PrintHeap(&ph);
	printf("\n");

	printf("del from q: %d\n", Dequeue(&ppq));
	printf("del from heap: %d\n", HeapDelete(&ph));
	printf("Heap Structure\n");
	PrintHeap(&ph);
	printf("\n");

	printf("del from q: %d\n", Dequeue(&ppq));
	printf("del from heap: %d\n", HeapDelete(&ph));
	printf("Heap Structure\n");
	PrintHeap(&ph);
	printf("\n");

	return 0;
}