#include "stdio.h"
#include "stdlib.h"
#include "Queue.h"


void QueueInit(Queue* pq)
{
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue* pq)
{
	if (pq->front == pq->rear)
		return 1;
	return 0;
}

void Enqueue(Queue* pq, int data)
{
	if ((pq->rear + 1) % (QUEUE_LEN + 1) == pq->front)
	{
		printf("ENQUEUE MEMORY ERROR\n");
		exit(-1);
	}

	pq->rear = (pq->rear + 1) % (QUEUE_LEN + 1);
	pq->data[pq->rear] = data;
}

int Dequeue(Queue* pq)
{
	int rData;

	if (QIsEmpty(pq))
	{
		printf("DEQUEUE MEMORY ERROR\n");
		exit(-1);
	}

	rData = pq->data[++(pq->front)];
	return rData;
}

int QPeek(Queue* pq)
{
	int rData;

	if (QIsEmpty(pq))
	{
		printf("MEMORY ERROR\n");
		exit(-1);
	}

	rData = pq->data[pq->front + 1];
	return rData;
}
