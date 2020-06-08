#ifndef __ARRAY_QUEUE_H__
#define __ARRAY_QUEUE_H__

#define QUEUE_LEN	100

#include "QueueData.h"

typedef struct _arrayQeuue
{
	int front;
	int rear;
	Data data[QUEUE_LEN + 1];
} ArrayQueue;

void QueueInit(ArrayQueue* pq);
int QIsEmpty(ArrayQueue* pq);

void Enqueue(ArrayQueue* pq, Data data);
Data Dequeue(ArrayQueue* pq);
Data QPeek(ArrayQueue* pq);

#endif