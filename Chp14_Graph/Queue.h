#ifndef __QUEUE_H__
#define __QUEUE_H__

#define QUEUE_LEN	100

#include "Data.h"

typedef struct _arrayQeuue
{
	int front;
	int rear;
	Data data[QUEUE_LEN + 1];
} ArrayQueue;

typedef ArrayQueue Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq);

#endif