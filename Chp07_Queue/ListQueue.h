#ifndef __LIST_QUEUE_H__
#define __LIST_QUEUE_H__

#include "QueueData.h"

typedef struct _listQueue
{
	Node* front;
	Node* rear;
} ListQueue;

void LQueueInit(ListQueue* pq);
int LQIsEmpty(ListQueue* pq);

void LEnqueue(ListQueue* pq, Data data);
Data LDequeue(ListQueue* pq);
Data LQPeek(ListQueue* pq);

#endif