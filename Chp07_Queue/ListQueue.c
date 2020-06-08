#include "stdio.h"
#include "stdlib.h"
#include "ListQueue.h"

void LQueueInit(ListQueue* pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}

int LQIsEmpty(ListQueue* pq)
{
	if (pq->front == NULL)
	{
		return TRUE;
	}
	return FALSE;
}

void LEnqueue(ListQueue* pq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = NULL;

	if (LQIsEmpty(pq))
	{
		pq->front = newNode;
		pq->rear = newNode;
	}
	else
	{
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}

Data LDequeue(ListQueue* pq)
{
	Data rData;
	Node* fNode;

	if (LQIsEmpty(pq))
	{
		printf("MEM ERROR\n");
		exit(-1);
	}

	fNode = pq->front;
	rData = pq->front->data;

	pq->front = pq->front->next;
	free(fNode);

	return rData;
}

Data LQPeek(ListQueue* pq)
{
	Data rData;

	if (LQIsEmpty(pq))
	{
		printf("MEM ERROR\n");
		exit(-1);
	}

	rData = pq->front->data;

	return rData;
}
