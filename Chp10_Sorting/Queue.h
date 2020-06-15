#ifndef __QUEUE_H__
#define __QUEUE_H__

#define QUEUE_LEN	100

typedef struct _qeuue
{
	int front;
	int rear;
	int data[QUEUE_LEN + 1];
} Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, int data);
int Dequeue(Queue* pq);
int QPeek(Queue* pq);

#endif